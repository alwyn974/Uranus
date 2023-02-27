/*
** EPITECH PROJECT, 2023
** Manager.cpp
** File description:
** Manager.cpp
*/

#include "engine/Manager.hpp"

std::shared_ptr<engine::RenderWindow> engine::Manager::_window = nullptr;
std::shared_ptr<ecs::Registry> engine::Manager::_registry = nullptr;
std::shared_ptr<engine::SceneManager> engine::Manager::_sceneManager = nullptr;

std::shared_ptr<engine::RenderWindow> &engine::Manager::getWindow()
{
    if (!_window) { _window = std::make_shared<engine::RenderWindow>(sf::VideoMode(800, 600), "Uranus"); }
    return _window;
}

std::shared_ptr<ecs::Registry> &engine::Manager::getRegistry()
{
    if (!_registry) { _registry = std::make_shared<ecs::Registry>(); }
    return _registry;
}

std::shared_ptr<engine::SceneManager> &engine::Manager::getSceneManager()
{
    if (!_sceneManager) { _sceneManager = std::make_shared<engine::SceneManager>(); }
    return _sceneManager;
}
