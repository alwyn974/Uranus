//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_SYSTEMS_HPP
#define URANUS_SYSTEMS_HPP

#include <iostream>

#include "Components.hpp"
#include "Registry.hpp"
#include "Window.hpp"

void position_system(ecs::Registry &r);
void draw_system(ecs::Registry &r);
// void control_system(ecs::Registry &r);
void input_system(ecs::Registry &r, sf::Event event);
void collision_system(ecs::Registry &r);
void loop_system(ecs::Registry &r);


bool is_colliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2);
#endif // URANUS_SYSTEMS_HPP
