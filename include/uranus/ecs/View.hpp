/*
** EPITECH PROJECT, 2023
** View.hpp
** File description:
** View.hpp
*/

#ifndef URANUS_VIEW_HPP
#define URANUS_VIEW_HPP

#include "Registry.hpp"

/**
 * @brief Namespace containing all the ECS related classes
 */
namespace uranus::ecs {
    /**
     * @brief A view is a way to iterate over a set of entities that have a specific set of components
     * @tparam Components the components that the entities must have
     */
    template<typename... Components>
    class View {
    public:
        using Tuple = std::tuple<size_t, Components &...>; /**< The tuple type that will be returned by the iterators */

        /**
         * @brief Construct a new View object
         * @param registry the registry to iterate over
         */
        explicit View(ecs::Registry &registry) : _registry(registry) {}

        /**
         * @brief Iterator class for the view
         */
        class Iterator {
        public:
            /**
             * @brief Construct a new Iterator object
             * @param registry the registry to iterate over
             */
            explicit Iterator(ecs::Registry &registry) : _registry(registry)
            {
                idx = 0;
                skipInvalidEntities<Components...>();
            }

            /**
             * @brief Prefix increment operator
             * @return the iterator
             */
            Iterator &operator++()
            {
                idx++;
                skipInvalidEntities<Components...>();
                return *this;
            }

            /**
             * @brief Postfix increment operator
             * @return the iterator
             */
            Tuple operator->() { return Tuple(idx, (*_registry.getComponent<Components>(idx))...); }

            /**
             * @brief Dereference operator
             * @return the tuple
             */
            Tuple operator*() { return Tuple(idx, (*_registry.getComponent<Components>(idx))...); }

            /**
             * @brief Equality operator
             * @param other the other iterator
             * @return true if the iterators are equal
             */
            bool operator==(const Iterator &other) const { return idx == other.idx; }

            /**
             * @brief Inequality operator
             * @param other the other iterator
             * @return true if the iterators are not equal
             */
            bool operator!=(const Iterator &other) const { return !(other == *this); /* NOLINT */ }

            std::size_t idx;

        private:
            ecs::Registry _registry; /**< The registry to iterate over */

            /**
             * @brief Skip all the entities that don't have all the components
             * @tparam Component the current component
             * @tparam Others the other components
             */
            template<typename Component, typename... Others>
            void skipInvalidEntities()
            {
                while (idx < _registry.getEntityCounter()) {
                    bool hasAllComponents = true;
                    auto &component = _registry.getComponent<Component>(idx);
                    if (component == nullptr) {
                        hasAllComponents = false;
                    }
                    if (hasAllComponents) {
                        if constexpr (sizeof...(Others) > 0) {
                            skipInvalidEntities<Others...>();
                        }
                    }
                    if (hasAllComponents) return;
                    if (idx == _registry.getEntityCounter()) break;
                    idx++;
                }
            }
        };

        /**
         * @brief Get the begin iterator
         * @return the begin iterator
         */
        Iterator begin() { return Iterator(_registry); }

        /**
         * @brief Get the end iterator
         * @return the end iterator
         */
        Iterator end()
        {
            Iterator it(_registry);
            it.idx = _registry.getEntityCounter();
            return it;
        }

    private:
        Registry _registry; /**< The registry to iterate over */
    };
} // namespace uranus::ecs

#endif // URANUS_VIEW_HPP
