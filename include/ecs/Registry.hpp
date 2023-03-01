//
// Created by nicol on 20/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP

#include <any>
#include <functional>
#include <list>
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
         * @param deleteFunction Function to call when the component is deleted
         * @return Reference to the SparseArray of the component
         */
        template<class Component>
        SparseArray<Component> &registerComponent(std::function<void(const size_t &)> &);

        /**
         * @brief Register a component type and it's delete function
         * @tparam Component Type of the component
         * @param deleteFunction Function to call when the component is deleted
         * @return Reference to the SparseArray of the component
         */
        template<class Component>
        SparseArray<Component> &registerComponent(std::function<void(const size_t &)> &&);

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
        Entity entityFromIndex(std::size_t idx) const;

        /**
         * @brief Destroy an entity
         * @param e Entity to destroy
         */
        void killEntity(const Entity &e);

        /**
         * @brief Destroy an entity
         * @param e Index of the entity to destroy
         */
        void killEntity(const size_t &e);


        /**
         * @brief Destroy all entities
         */
        void killAllEntities();

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

        /**
         * @brief Get the number of entities alive
         * @return Number of entities alive
         */
        int entitiesAliveCount() const;

        /**
         * @brief Get the counter used to generate new entity ids
         * @return Counter used to generate new entity ids
         */
        size_t getEntityCounter() const;

        /**
         * @brief Get the maximum index of an entity
         * @return Maximum index of an entity
         */
//        size_t getEntityAliveMaxIndex() const;
    private:
        std::unordered_map<std::type_index, std::any> _componentsArrays; /*< Map containing all the components SparseArrays */
        std::unordered_map<std::type_index, std::function<void(size_t const &)>> _destroyArrays; /*< Map containing all the components delete functions */
        size_t _entityCounter = 0; /*< Counter used to generate new entity ids */
        std::list<size_t> _freeIds; /*< Queue containing the ids of the destroyed entities */
    };

    template<class Component>
    SparseArray<Component> &
    Registry::registerComponent(std::function<void(const size_t &)> &&deleteFunction) {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) != _componentsArrays.end())
            throw std::runtime_error("Component already registered");
        if (_destroyArrays.find(typeIndex) != _destroyArrays.end())
            throw std::runtime_error("Delete function already registered");
        _componentsArrays[typeIndex] = SparseArray<Component>();
        _destroyArrays[typeIndex] = deleteFunction;
        return std::any_cast<SparseArray<Component> &>(_componentsArrays[typeIndex]);
    }

    template<class Component>
    SparseArray<Component> &
    Registry::registerComponent(std::function<void(const size_t &)> &deleteFunction) {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) != _componentsArrays.end())
            throw std::runtime_error("Component already registered");
        if (_destroyArrays.find(typeIndex) != _destroyArrays.end())
            throw std::runtime_error("Delete function already registered");
        _componentsArrays[typeIndex] = SparseArray<Component>();
        _destroyArrays[typeIndex] = deleteFunction;
        return std::any_cast<SparseArray<Component> &>(_componentsArrays[typeIndex]);
    }

    template<class Component>
    typename SparseArray<Component>::ReferenceType Registry::getComponent(const Entity &e) {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_componentsArrays[typeIndex])[e];
    }

    template<class Component>
    typename SparseArray<Component>::ReferenceType Registry::getComponent(const size_t &e) {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_componentsArrays[typeIndex])[e];
    }

    template<class Component>
    typename SparseArray<Component>::ConstReferenceType Registry::getComponent(const Entity &e) const {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_componentsArrays.at(typeIndex))[e];
    }

    template<class Component>
    typename SparseArray<Component>::ConstReferenceType Registry::getComponent(const size_t &e) const {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_componentsArrays.at(typeIndex))[e];
    }

    template<class Component>
    SparseArray<Component> &Registry::getComponents() {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> &>(_componentsArrays[typeIndex]);
    }

    template<class Component>
    SparseArray<Component> const &Registry::getComponents() const {
        auto const &typeIndex = std::type_index(typeid(Component));
        if (_componentsArrays.find(typeIndex) == _componentsArrays.end())
            throw std::runtime_error("Component not registered");
        return std::any_cast<SparseArray<Component> const &>(_componentsArrays.at(typeIndex));
    }

    inline Entity Registry::spawnEntity() {
        if (_freeIds.empty()) {
            return Entity(_entityCounter++);
        } else {
            size_t id = _freeIds.front();
            _freeIds.pop_front();
            return Entity(id);
        }
    }

    inline Entity Registry::entityFromIndex(std::size_t idx) const {
        return Entity(idx);
    }

    inline void Registry::killEntity(const Entity &e) {
        _freeIds.push_back(e._id);
        for (auto &i: _destroyArrays) { i.second(e._id); }
    }

    inline void Registry::killEntity(const size_t &e) {
        _freeIds.push_back(e);
        for (auto &i: _destroyArrays) { i.second(e); }
    }

    inline void Registry::killAllEntities() {
        for (size_t i = 0; i < _entityCounter; i++) {
            killEntity(i);
        }
        _freeIds.clear();
        _entityCounter = 0;
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

    inline int Registry::entitiesAliveCount() const {
        return _entityCounter - _freeIds.size();
    }

    inline size_t Registry::getEntityCounter() const {
        return _entityCounter;
    }

//    //TODO what if there is no entity alive cf view
//    inline size_t Registry::getEntityAliveMaxIndex() const {
//        for (long int i = static_cast<int>(_entityCounter); i >= 0; i--) {
//            if (_freeIds.empty() || *std::max_element(_freeIds.begin(), _freeIds.end()) < i)
//                return i;
//        }
//        return 0;
//    }
}

#endif // B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
