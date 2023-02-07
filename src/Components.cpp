//
// Created by nicol on 23/01/2023.
//

#include <iostream>
#include "Components.hpp"

void delete_position(registry &r, size_t const e)
{
    r.remove_component<component::position>(e);
}

void delete_velocity(registry &r, size_t const e)
{
    r.remove_component<component::velocity>(e);
}

void delete_drawable(registry &r, size_t const e)
{
    r.remove_component<component::drawable>(e);
}

void delete_controllable(registry &r, size_t const e)
{
    r.remove_component<component::controllable>(e);
}

void delete_inputKeyboard(registry &r, size_t const e)
{
    r.remove_component<component::inputKeyboard>(e);
}

void delete_inputMouse(registry &r, size_t const e)
{
    r.remove_component<component::inputMouse>(e);
}

void delete_collisionable(registry &r, size_t const e)
{
    r.remove_component<component::collisionable>(e);
}

void delete_sprite_component(registry &r, size_t const e)
{
    std::cout << "delete sprite component: " << e << std::endl;
    r.remove_component<component::sprite>(e);
}

void delete_loop_component(registry &r, size_t e)
{
    r.remove_component<component::loop>(e);
}
