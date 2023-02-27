/*
** EPITECH PROJECT, 2023
** SceneManager.cpp
** File description:
** SceneManager.cpp
*/


#include "engine/SceneManager.hpp"

void engine::SceneManager::addScene(const std::shared_ptr<engine::Scene> &newScene)
{
    this->_scenes.push_back(newScene);
}

void engine::SceneManager::changeScene(const std::string &sceneToSwitch)
{
    for (std::shared_ptr<engine::Scene> &sceneItem : this->_scenes) {
        if (sceneItem->getName() == sceneToSwitch) {
            this->_actualScene = sceneItem;
            break;
        }
    }

    //TODO: delete all entity

    this->_actualScene->init();
}

void engine::SceneManager::changeScene(const std::shared_ptr<engine::Scene> &newScene)
{
    this->_actualScene = newScene;
    this->_actualScene->init();
}
