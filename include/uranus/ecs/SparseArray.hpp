/*
** EPITECH PROJECT, 2023
** SparseArray.hpp
** File description:
** SparseArray.hpp
*/

#ifndef URANUS_SPARSEARRAY_HPP
#define URANUS_SPARSEARRAY_HPP

#include "uranus/Core.hpp"
#include <memory>
#include <optional>
#include <vector>

/**
 * @brief Namespace containing all the ECS related classes
 */
namespace uranus::ecs {
    /**
     * @brief SparseArray class, used to store components in a sparse way
     * @tparam Component Type of the component to store
     */
    template<typename Component>
    class SparseArray {
    public:
        using ValueType = std::shared_ptr<Component>;
        using ReferenceType = ValueType &;
        using ConstReferenceType = const ValueType &;
        using Container = std::vector<ValueType>;
        using SizeType = typename Container::size_type;
        using Iterator = typename Container::iterator;
        using ConstIterator = typename Container::const_iterator;

        /**
         * @brief Default constructor
         */
        SparseArray() = default;

        /**
         * @brief Default copy constructor
         * @param other SparseArray to copy
         */
        SparseArray(const SparseArray &) = default;

        /**
         * @brief Default move constructor
         * @param other SparseArray to move
         */
        SparseArray(SparseArray &&) noexcept = default;

        /**
         * @brief Default destructor
         */
        ~SparseArray() = default;

        /**
         * @brief Copy assignment operator
         * @tparam Component Type of the component
         * @param other SparseArray to copy
         * @return Reference to the current SparseArray
         */
        SparseArray &operator=(const SparseArray &);

        /**
         * @brief Move assignment operator
         * @tparam Component Type of the component
         * @param other SparseArray to move
         * @return Reference to the current SparseArray
         */
        SparseArray &operator=(SparseArray &&) noexcept;

        /**
         * @brief Access the component at the given index, if it exists, otherwise resize the SparseArray
         * @tparam Component Type of the component
         * @param idx Index to get the component
         * @return Reference to the component
         */
        ReferenceType operator[](std::size_t idx);

        /**
         * @brief Access the component at the given index, if it exists, otherwise return nullptr
         * @tparam Component Type of the component
         * @param idx Index to get the component
         * @return Reference to the component if it exists, nullptr otherwise
         */
        ConstReferenceType operator[](std::size_t idx) const;

        /**
         * @brief Return the iterator pointing to the beginning of the SparseArray
         * @tparam Component Type of the component
         * @return Iterator pointing to the beginning of the SparseArray
         */
        Iterator begin();

        /**
         * @brief Return the const_iterator pointing to the beginning of the SparseArray
         * @tparam Component Type of the component
         * @return ConstIterator pointing to the beginning of the SparseArray
         */
        ConstIterator begin() const;

        /**
         * @brief Return the const_iterator pointing to the beginning of the SparseArray
         * @tparam Component Type of the component
         * @return ConstIterator pointing to the beginning of the SparseArray
         */
        ConstIterator cbegin() const;

        /**
         * @brief Return the iterator pointing to the end of the SparseArray
         * @tparam Component Type of the component
         * @return Iterator pointing to the end of the SparseArray
         */
        Iterator end();

        /**
         * @brief Return the const_iterator pointing to the end of the SparseArray
         * @tparam Component Type of the component
         * @return ConstIterator pointing to the end of the SparseArray
         */
        ConstIterator end() const;

        /**
         * @brief Return the const_iterator pointing to the end of the SparseArray
         * @tparam Component Type of the component
         * @return ConstIterator pointing to the end of the SparseArray
         */
        ConstIterator cend() const;

        /**
         * @brief Return the size of the SparseArray
         * @tparam Component Type of the component
         * @return Size of the SparseArray
         */
        SizeType size() const;

        /**
         * @brief Insert a component at the given index
         * @tparam Component Type of the component
         * @param pos Index to insert the component
         * @param component Component to insert
         * @return Reference to the inserted component
         */
        ReferenceType insertAt(SizeType pos, const Component &);

        /**
         * @brief Insert a component at the given index
         * @tparam Component Type of the component
         * @param pos Index to insert the component
         * @param component Component to insert
         * @return Reference to the inserted component
         * @note The component is moved
         */
        ReferenceType insertAt(SizeType pos, Component &&);

        /**
         * @brief Emplace a component at the given index
         * @tparam Params Types of the parameters to construct the component
         * @param pos Index to emplace the component
         * @param params Parameters to construct the component
         * @return Reference to the inserted component
         * @note The component is constructed in place or moved into the SparseArray
         */
        template<class... Params>
        ReferenceType emplaceAt(SizeType pos, Params &&...params);

        /**
         * @brief Erase the component at the given index
         * @tparam Component Type of the component
         * @param pos Index of the component to erase
         */
        void erase(SizeType pos);

        /**
         * @brief Get the index of the entity possessing the given component
         * @tparam Component Type of the component
         * @param ptr Pointer to the component
         * @return Optional containing the index of the entity possessing the given component or nullopt if the component is not found
         */
        std::optional<SizeType> getIndex(const ValueType &) const;

        /**
         * @brief Get the _data container
         * @return Reference to the _data container
         */
        Container &getData() const;

    private:
        Container _data; /**< Container of the components */
    };

    template<typename Component>
    SparseArray<Component> &SparseArray<Component>::operator=(const SparseArray<Component> &other)
    {
        _data = other._data;
        return *this;
    }

    template<typename Component>
    SparseArray<Component> &SparseArray<Component>::operator=(SparseArray<Component> &&other) noexcept
    {
        _data = std::move(other._data);
        return *this;
    }

    template<typename Component>
    typename SparseArray<Component>::ReferenceType SparseArray<Component>::operator[](std::size_t idx)
    {
        if (idx >= _data.size()) _data.resize(idx + 1);
        return _data[idx];
    }

    template<typename Component>
    typename SparseArray<Component>::ConstReferenceType SparseArray<Component>::operator[](std::size_t idx) const
    {
        if (idx >= _data.size()) return nullptr;
        return _data[idx];
    }

    template<typename Component>
    typename SparseArray<Component>::Iterator SparseArray<Component>::begin()
    {
        return _data.begin();
    }

    template<typename Component>
    typename SparseArray<Component>::ConstIterator SparseArray<Component>::begin() const
    {
        return _data.begin();
    }

    template<typename Component>
    typename SparseArray<Component>::ConstIterator SparseArray<Component>::cbegin() const
    {
        return _data.cbegin();
    }

    template<typename Component>
    typename SparseArray<Component>::Iterator SparseArray<Component>::end()
    {
        return _data.end();
    }

    template<typename Component>
    typename SparseArray<Component>::ConstIterator SparseArray<Component>::end() const
    {
        return _data.end();
    }

    template<typename Component>
    typename SparseArray<Component>::ConstIterator SparseArray<Component>::cend() const
    {
        return _data.cend();
    }

    template<typename Component>
    typename SparseArray<Component>::SizeType SparseArray<Component>::size() const
    {
        return _data.size();
    }

    template<typename Component>
    typename SparseArray<Component>::ReferenceType SparseArray<Component>::insertAt(SizeType pos, const Component &component)
    {
        if (pos >= _data.size()) _data.resize(pos + 1);
        _data[pos] = std::make_shared<Component>(component);
        return _data[pos];
    }

    template<typename Component>
    typename SparseArray<Component>::ReferenceType SparseArray<Component>::insertAt(SizeType pos, Component &&component)
    {
        if (pos >= _data.size()) _data.resize(pos + 1);
        _data[pos] = std::move(std::make_shared<Component>(component));
        return _data[pos];
    }

    // TODO test this function
    template<typename Component>
    template<class... Params>
    typename SparseArray<Component>::ReferenceType SparseArray<Component>::emplaceAt(SizeType pos, Params &&...params)
    {
        if (pos >= _data.size()) _data.resize(pos + 1);
        _data[pos] = std::make_shared<Component>(std::forward<Params>(params)...);
        return _data[pos];
    }

    template<typename Component>
    void SparseArray<Component>::erase(SizeType pos)
    {
        if (pos >= _data.size()) return;
        _data[pos] = nullptr;
    }

    template<typename Component>
    std::optional<typename SparseArray<Component>::SizeType> SparseArray<Component>::getIndex(const ValueType &ptr) const
    {
        for (SizeType i = 0; i < _data.size(); i++) {
            if (_data[i] && ptr) {
                if (std::addressof(_data[i].get()) == std::addressof(ptr.get())) return i;
            }
        }
        return std::nullopt;
    }

    template<typename Component>
    typename SparseArray<Component>::Container &SparseArray<Component>::getData() const
    {
        return _data;
    }
} // namespace uranus::ecs
#endif // URANUS_SPARSEARRAY_HPP
