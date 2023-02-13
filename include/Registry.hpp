//
// Created by nicol on 20/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP

#include <any>
#include <functional>
#include <queue>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

#include "Entity.hpp"
#include "SparseArray.hpp"

namespace ecs {
/**
 * @brief Registry class, used to store and manage entities and their components
 */
    class Registry {
    public:
        /**
         * @brief Register a component type and it's delete function
         * @tparam Component Type of the component
         * @param delete_function Function to call when the component is deleted
         * @return Reference to the SparseArray of the component
         */
        template<class Component>
        SparseArray<Component> &registerComponent(std::function<void(Registry &, const size_t &)> &);

        /**
         * @brief Get a component from an entity
         * @tparam Component Type of the component
         * @param e Entity to get the component from
         * @return Reference to the component
         */
        template<class Component>
        typename SparseArray<Component>::ReferenceType getComponent(const Entity &e);

        /**
         * @brief Get a const component from an entity
         * @tparam Component Type of the component
         * @param e Entity to get the component from
         * @return Const reference to the component
         */
        template<class Component>
        typename SparseArray<Component>::ConstReferenceType getComponent(const Entity &e) const;

        /**
         * @brief Get a component from an index
         * @tparam Component Type of the component
         * @param e Index of the entity to get the component from
         * @return Reference to the component
         */
        template<class Component>
        typename SparseArray<Component>::ReferenceType getComponent(const size_t &e);

        /**
         * @brief Get a const component from an index
         * @tparam Component Type of the component
         * @param e Index of the entity to get the component from
         * @return Const reference to the component
         */
        template<class Component>
        typename SparseArray<Component>::ConstReferenceType getComponent(const size_t &e) const;

        /**
         * @brief Get the SparseArray of a component type
         * @tparam Component Type of the component
         * @return Reference to the SparseArray of the component type
         */
        template<class Component>
        SparseArray<Component> &getComponents();

        /**
         * @brief Get the const SparseArray of a component type
         * @tparam Component Type of the component
         * @return Const reference to the SparseArray of the component type
         */
        template<class Component>
        SparseArray<Component> const &getComponents() const;

        /**
         * @brief Spawn a new entity
         * @return The new entity
         */
        Entity spawnEntity();

        /**
         * @brief Create an entity from an index
         * @param idx Index of the entity
         * @return The newly created entity
         */
        Entity entityFromIndex(std::size_t idx);

        /**
         * @brief Destroy an entity
         * @param e Entity to destroy
         */
        void killEntity(const Entity &e);

        /**
         * @brief Add a component to an entity
         * @tparam Component Type of the component
         * @param to Entity to add the component to
         * @param c Component to add
         * @return Reference to the component
         */
        template<typename Component>
        typename SparseArray<Component>::ReferenceType addComponent(const Entity &to, Component &&c);

        /**
         * @brief Emplace a component to an entity
         * @tparam Component Type of the component
         * @tparam Params Variadic parameters to pass to the constructor
         * @param to Entity to add the component to
         * @param p Parameters to pass to the constructor
         * @return Reference to the component
         */
        template<typename Component, typename... Params>
        typename SparseArray<Component>::ReferenceType emplaceComponent(const Entity &to, Params &&...p);

        /**
         * @brief Remove a component from an entity
         * @tparam Component Type of the component
         * @param from Entity to remove the component from
         */
        template<typename Component>
        void removeComponent(const Entity &from);

        /**
         * @brief Remove a component from an entity
         * @tparam Component Type of the component
         * @param from Index of the entity to remove the component from
         */
        template<typename Component>
        void removeComponent(const size_t &from);

    private:
        std::unordered_map<std::type_index, std::any> _components_arrays; /*< Map containing all the components SparseArrays */
        std::unordered_map<std::type_index, std::function<void(Registry &,
                                                               size_t const &)>> _destroy_arrays; /*< Map containing all the components delete functions */
        size_t entity_counter = 0; /*< Counter used to generate new entity ids */
        std::queue<size_t> _free_ids; /*< Queue containing the ids of the destroyed entities */
    };

    template<class Component>
    SparseArray<Component> &
    Registry::registerComponent(std::function<void(Registry &, const size_t &)> &delete_function) {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) != _components_arrays.end())
            throw std::runtime_error("Component already registered");
        if (_destroy_arrays.find(type_index) != _destroy_arrays.end())
            throw std::runtime_error("Delete function already registered");
        _components_arrays[type_index] = SparseArray<Component>();
        _destroy_arrays[type_index] = delete_function;
        return std::any_cast<SparseArray<Component> &>(_components_arrays[type_index]);
    }

    template<class Component>
    typename SparseArray<Component>::ReferenceType Registry::getComponent(const Entity &e) {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_components_arrays[type_index])[e];
    }

    template<class Component>
    typename SparseArray<Component>::ReferenceType Registry::getComponent(const size_t &e) {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_components_arrays[type_index])[e];
    }

    template<class Component>
    typename SparseArray<Component>::ConstReferenceType Registry::getComponent(const Entity &e) const {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_components_arrays.at(type_index))[e];
    }

    template<class Component>
    typename SparseArray<Component>::ConstReferenceType Registry::getComponent(const size_t &e) const {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_components_arrays.at(type_index))[e];
    }

    template<class Component>
    SparseArray<Component> &Registry::getComponents() {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_components_arrays[type_index]);
    }

    template<class Component>
    SparseArray<Component> const &Registry::getComponents() const {
        auto const &type_index = std::type_index(typeid(Component));
        if (_components_arrays.find(type_index) == _components_arrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_components_arrays.at(type_index));
    }

    inline Entity Registry::spawnEntity() {
        if (_free_ids.empty()) {
            return Entity(entity_counter++);
        } else {
            size_t id = _free_ids.front();
            _free_ids.pop();
            return Entity(id);
        }
    }

    inline Entity Registry::entityFromIndex(std::size_t idx) {
        return Entity(idx);
    }

    inline void Registry::killEntity(const Entity &e) {
        _free_ids.push(e._id);
        for (auto &i: _destroy_arrays) { i.second(*this, e._id); }
    }

    template<typename Component>
    typename SparseArray<Component>::ReferenceType Registry::addComponent(const Entity &to, Component &&c) {
        auto &components = getComponents<Component>();
        return components.insertAt(to, std::forward<Component>(c));
    }

    template<typename Component, typename... Params>
    typename SparseArray<Component>::ReferenceType Registry::emplaceComponent(const Entity &to, Params &&...p) {
        auto &components = getComponents<Component>();
        return components.emplaceAt(to, std::forward<Params>(p)...);
    }

    template<typename Component>
    void Registry::removeComponent(const Entity &from) {
        auto &components = getComponents<Component>();
        components.erase(from);
    }

    template<typename Component>
    void Registry::removeComponent(const size_t &from) {
        auto &components = getComponents<Component>();
        components.erase(from);
    }
}

#endif // B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
