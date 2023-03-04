/*
** EPITECH PROJECT, 2023
** SceneManager.hpp
** File description:
** SceneManager.hpp
*/

#ifndef URANUS_SCENEMANAGER_HPP
#define URANUS_SCENEMANAGER_HPP

#include "uranus/engine/components/Scene.hpp"

namespace engine {

    class SceneManager {
    public:
        explicit SceneManager() = default;

        ~SceneManager() = default;

        void addScene(const std::shared_ptr<engine::Scene> &newScene);

        void changeScene(const std::string &sceneToSwitch);

        void changeScene(const std::shared_ptr<engine::Scene> &newScene);

    private:
        std::shared_ptr<engine::Scene> _actualScene;
        std::vector<std::shared_ptr<engine::Scene>> _scenes;
    };
} // namespace engine

#endif // URANUS_SCENEMANAGER_HPP
