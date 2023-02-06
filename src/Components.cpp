//
// Created by nicol on 23/01/2023.
//

#include "Components.hpp"

void delete_position(registry &r, size_t const e) {
    r.remove_component<component::position>(e);
}

void delete_velocity(registry &r, size_t const e) {
    r.remove_component<component::velocity>(e);
}

void delete_drawable(registry &r, size_t const e) {
    r.remove_component<component::drawable>(e);
}

void delete_controllable(registry &r, size_t const e) {
    r.remove_component<component::controllable>(e);
}