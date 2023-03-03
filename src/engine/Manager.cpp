/*
** EPITECH PROJECT, 2023
** Manager.cpp
** File description:
** Manager.cpp
*/

#include "uranus/engine/Manager.hpp"

std::shared_ptr<engine::RenderWindow> engine::Manager::window = nullptr;
std::shared_ptr<uranus::ecs::Registry> engine::Manager::registry = nullptr;
std::shared_ptr<engine::SceneManager> engine::Manager::sceneManager = nullptr;
std::shared_ptr<engine::TextureManager> engine::Manager::textureManager = nullptr;
std::shared_ptr<engine::EntityManager> engine::Manager::entityManager = nullptr;

std::shared_ptr<engine::RenderWindow> &engine::Manager::getWindow()
{
    if (!window) {
        window = std::make_shared<engine::RenderWindow>(sf::VideoMode(800, 600), "Uranus");
    }
    return window;
}

std::shared_ptr<uranus::ecs::Registry> &engine::Manager::getRegistry()
{
    if (!registry) {
        registry = std::make_shared<uranus::ecs::Registry>();
    }
    return registry;
}

std::shared_ptr<engine::SceneManager> &engine::Manager::getSceneManager()
{
    if (!sceneManager) {
        sceneManager = std::make_shared<engine::SceneManager>();
    }
    return sceneManager;
}

std::shared_ptr<engine::TextureManager> &engine::Manager::getTextureManager()
{
    if (!textureManager) {
        textureManager = std::make_shared<engine::TextureManager>();
    }
    return textureManager;
}

std::shared_ptr<engine::EntityManager> &engine::Manager::getEntityManager()
{
    if (!entityManager) {
        entityManager = std::make_shared<engine::EntityManager>();
    }
    return entityManager;
}

void engine::Manager::killAllEntitiesAndPrefabs()
{
    auto &r = engine::Manager::getRegistry();
    auto &entityManger = engine::Manager::getEntityManager();
    r->killAllEntities();
    entityManger->killAllPrefabs();
}
