/*
** EPITECH PROJECT, 2023
** Manager.cpp
** File description:
** Manager.cpp
*/

#include "engine/Manager.hpp"

engine::RenderWindow *engine::Manager::_window = nullptr;
ecs::Registry *engine::Manager::_registry = nullptr;

engine::RenderWindow *engine::Manager::getWindow()
{
    if (!_window) { _window = new engine::RenderWindow(sf::VideoMode(800, 600), "Uranus"); }
    return _window;
}

ecs::Registry *engine::Manager::getRegistry()
{
    if (!_registry) { _registry = new ecs::Registry(); }
    return _registry;
}