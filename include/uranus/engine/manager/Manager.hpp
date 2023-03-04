/*
** EPITECH PROJECT, 2023
** Manager.hpp
** File description:
** Manager.hpp
*/

#ifndef URANUS_MANAGER_HPP
#define URANUS_MANAGER_HPP

#include "EntityManager.hpp"
#include "uranus/engine/components/RenderWindow.hpp"
#include "SceneManager.hpp"
#include "TextureManager.hpp"

namespace engine {
    class Manager {
    public:
        ~Manager() = default;

        Manager(const Manager &) = delete;

        Manager &operator=(const Manager &) = delete;

        static std::shared_ptr<engine::RenderWindow> &getWindow();

        static std::shared_ptr<uranus::ecs::Registry> &getRegistry();

        static std::shared_ptr<engine::SceneManager> &getSceneManager();

        static std::shared_ptr<engine::TextureManager> &getTextureManager();

        static std::shared_ptr<engine::EntityManager> &getEntityManager();

        static void killAllEntitiesAndPrefabs();

    private:
        Manager() = default;

        static std::shared_ptr<engine::RenderWindow> window;
        static std::shared_ptr<uranus::ecs::Registry> registry;
        static std::shared_ptr<engine::SceneManager> sceneManager;
        static std::shared_ptr<engine::TextureManager> textureManager;
        static std::shared_ptr<engine::EntityManager> entityManager;
    };
} // namespace engine

#endif // URANUS_MANAGER_HPP
