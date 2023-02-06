//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_SYSTEMS_HPP
#define URANUS_SYSTEMS_HPP

#include <iostream>

#include "Components.hpp"
#include "Registry.hpp"
#include "Window.hpp"

void position_system(registry &r);
void draw_system(registry &r);
// void control_system(registry &r);
void input_system(registry &r, sf::Event event);
void collision_system(registry &r);
void loop_system(registry &r);

#endif // URANUS_SYSTEMS_HPP
