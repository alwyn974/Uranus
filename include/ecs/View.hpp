//
// Created by nicol on 23/02/2023.
//

#ifndef URANUS_VIEW_HPP
#define URANUS_VIEW_HPP

#include "Registry.hpp"

template<typename... Components>
class View {
public:
    using Tuple = std::tuple<size_t, Components&...>;
    explicit View(ecs::Registry &registry) : _registry(registry) {}

    class Iterator {
    public:
        explicit Iterator(ecs::Registry &registry) : _registry(registry)
        {
            idx = 0;
            skipInvalidEntities<Components...>();
        }

        Iterator& operator++()
        {
            idx++;
            skipInvalidEntities<Components...>();
            return *this;
        }

        Tuple operator->()
        {
            return Tuple(idx, (_registry.getComponent<Components>(idx).get()->value())...);
        }

        Tuple operator*()
        {
            return Tuple(idx, (_registry.getComponent<Components>(idx).get()->value())...);
        }

        bool operator==(const Iterator &other) const
        {
            return idx == other.idx;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(other == *this);
        }
        std::size_t idx;
    private:
        ecs::Registry _registry;

        template<typename Component, typename... Others>
        void skipInvalidEntities()
        {
            while (idx < _registry.getEntityCounter()) {
                bool hasAllComponents = true;
                auto &component = _registry.getComponent<Component>(idx);
                if (component == nullptr || !component->has_value()) {
                    hasAllComponents = false;
                }
                if (hasAllComponents) {
                    if constexpr (sizeof...(Others) > 0) {
                        skipInvalidEntities<Others...>();
                    }
                }
                if (hasAllComponents) {
                    return;
                }
                if (idx == _registry.getEntityCounter())
                    break;
                idx++;
            }
        }
    };

    Iterator begin()
    {
        return Iterator(_registry);
    }

    Iterator end()
    {
        Iterator it(_registry);
        it.idx = _registry.getEntityCounter();
        return it;
    }
private:
    ecs::Registry _registry;
};
#endif //URANUS_VIEW_HPP
