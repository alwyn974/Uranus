/*
** EPITECH PROJECT, 2023
** SceneManager.cpp
** File description:
** SceneManager.cpp
*/

#include "uranus/engine/manager/SceneManager.hpp"
#include "uranus/engine/manager/Manager.hpp"

void engine::SceneManager::addScene(const std::shared_ptr<engine::Scene> &newScene)
{
    this->_scenes.push_back(newScene);
}

void engine::SceneManager::changeScene(const std::string &sceneToSwitch)
{
    for (std::shared_ptr<engine::Scene> &sceneItem : this->_scenes) {
        if (sceneItem->getName() == sceneToSwitch) {
            engine::Manager::killAllEntitiesAndPrefabs();

            this->_actualScene = sceneItem;
            this->_actualScene->init();
            break;
        }
    }
}

void engine::SceneManager::changeScene(const std::shared_ptr<engine::Scene> &newScene)
{
    this->_actualScene = newScene;
    this->_actualScene->init();
}
