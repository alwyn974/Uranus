/*
** EPITECH PROJECT, 2023
** Manager.hpp
** File description:
** Manager.hpp
*/

#ifndef URANUS_MANAGER_HPP
#define URANUS_MANAGER_HPP

#include "RenderWindow.hpp"
#include "SceneManager.hpp"
#include "TextureManager.hpp"
#include "EntityManager.hpp"


namespace engine {
    class Manager {
    public:
        ~Manager() = default;

        Manager(const Manager &) = delete;

        Manager &operator=(const Manager &) = delete;

        static std::shared_ptr<engine::RenderWindow> &getWindow();

        static std::shared_ptr<ecs::Registry> &getRegistry();

        static std::shared_ptr<engine::SceneManager> &getSceneManager();

        static std::shared_ptr<engine::TextureManager> &getTextureManager();

        static std::shared_ptr<engine::EntityManager> &getEntityManager();

    private:
        Manager() = default;

        static std::shared_ptr<engine::RenderWindow> _window;

        static std::shared_ptr<ecs::Registry> _registry;

        static std::shared_ptr<engine::SceneManager> _sceneManager;

        static std::shared_ptr<engine::TextureManager> _textureManager;

        static std::shared_ptr<engine::EntityManager> _entityManager;
    };
}

#endif //URANUS_MANAGER_HPP
