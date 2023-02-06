//
// Created by nicol on 20/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP

#include <unordered_map>
#include <typeindex>
#include <any>
#include <functional>
#include <stdexcept>
#include <stack>
#include "SparseArray.hpp"
#include "Entity.hpp"

class registry{
public :
    template <class Component>
    sparse_array<Component> &register_component(std::function<void(registry &, size_t const &)> &);
    template <class Component>
    typename sparse_array<Component>::reference_type get_component(Entity const &e);
    template <class Component>
    typename sparse_array<Component>::reference_type get_component(size_t const &e);
    template <class Component>
    sparse_array<Component> &get_components();
    template <class Component>
    sparse_array<Component> const &get_components() const;
    Entity spawn_entity();
    Entity entity_from_index(std::size_t idx);
    void kill_entity(Entity const &e);
    template <typename Component>
    typename sparse_array<Component>::reference_type add_component(Entity const & to, Component &&c);
    template <typename Component, typename ... Params>
    typename sparse_array<Component>::reference_type emplace_component(Entity const & to, Params &&... p);
    template <typename Component>
    void remove_component(Entity const &from);
    template <typename Component>
    void remove_component(size_t const &from);

private :
    std::unordered_map<std::type_index, std::any> _components_arrays;
    std::unordered_map<std::type_index, std::function<void(registry &, size_t const &)>> _destroy_arrays;
    size_t entity_counter = 0;
    std::stack<size_t> free_ids;
};

template <class Component>
sparse_array<Component> &registry::register_component(std::function<void(registry &, size_t const &)> &delete_function) {
    auto const &type_index = std::type_index(typeid(Component));
    if (_components_arrays.find(type_index) != _components_arrays.end())
        throw std::runtime_error("Component already registered");
    if (_destroy_arrays.find(type_index) != _destroy_arrays.end())
        throw std::runtime_error("Delete function already registered");
    _components_arrays[type_index] = sparse_array<Component>();
    _destroy_arrays[type_index] = delete_function;
    return std::any_cast<sparse_array<Component> &>(_components_arrays[type_index]);
}

template <class Component>
typename sparse_array<Component>::reference_type registry::get_component(Entity const &e) {
    auto const &type_index = std::type_index(typeid(Component));
    if (_components_arrays.find(type_index) == _components_arrays.end())
        throw std::runtime_error("Component not registered");
    return std::any_cast<sparse_array<Component> &>(_components_arrays[type_index])[e];
}

template <class Component>
typename sparse_array<Component>::reference_type registry::get_component(size_t const &e) {
    auto const &type_index = std::type_index(typeid(Component));
    if (_components_arrays.find(type_index) == _components_arrays.end())
        throw std::runtime_error("Component not registered");
    return std::any_cast<sparse_array<Component> &>(_components_arrays[type_index])[e];
}

template <class Component>
sparse_array<Component> &registry::get_components() {
    auto const &type_index = std::type_index(typeid(Component));
    if (_components_arrays.find(type_index) == _components_arrays.end())
        throw std::runtime_error("Component not registered");
    return std::any_cast<sparse_array<Component> &>(_components_arrays[type_index]);
}

template <class Component>
sparse_array<Component> const &registry::get_components() const {
    auto const &type_index = std::type_index(typeid(Component));
    if (_components_arrays.find(type_index) == _components_arrays.end())
        throw std::runtime_error("Component not registered");
    return std::any_cast<sparse_array<Component> const &>(_components_arrays.at(type_index));
}

inline Entity registry::spawn_entity() {
    if (free_ids.empty()) {
        return Entity(entity_counter++);
    } else {
        size_t id = free_ids.top();
        free_ids.pop();
        return Entity(id);
    }
}

inline Entity registry::entity_from_index(std::size_t idx) {
    return Entity(idx);
}

inline void registry::kill_entity(Entity const &e) {
    free_ids.push(e);
    for (auto &i : _destroy_arrays) {
        i.second(*this, e._id);
    }
}

template <typename Component>
typename sparse_array<Component>::reference_type registry::add_component(Entity const & to, Component &&c) {
    auto &components = get_components<Component>();
    return components.insert_at(to, std::forward<Component>(c));
}

template <typename Component, typename ... Params>
typename sparse_array<Component>::reference_type registry::emplace_component(Entity const & to, Params &&... p) {
    auto &components = get_components<Component>();
    return components.emplace_at(to, std::forward<Params>(p)...);
}

template <typename Component>
void registry::remove_component(Entity const &from) {
    auto &components = get_components<Component>();
    components.erase(from);
}

template <typename Component>
void registry::remove_component(size_t const &from) {
    auto &components = get_components<Component>();
    components.erase(from);
}

//template <class ... Components, typename Function>
//void registry::add_system(Function && f) {
//    auto const &type_index = std::type_index(typeid(std::tuple<Components...>));
//    if (_destroy_arrays.find(type_index) != _destroy_arrays.end())
//        throw std::runtime_error("System already registered");
//    _systems_array[type_index] = std::forward<Function>(f);
//}
#endif //B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_REGISTRY_HPP
