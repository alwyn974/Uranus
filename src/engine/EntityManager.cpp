/*
** EPITECH PROJECT, 2023
** EntityManager.cpp
** File description:
** EntityManager.cpp
*/

#include "engine/EntityManager.hpp"

void engine::EntityManager::addPrefab(const std::shared_ptr<engine::Base> &prefab)
{
    this->_prefabs.push_back(prefab);
}

std::shared_ptr<engine::Base> &engine::EntityManager::getPrefabByName(const std::string &prefabName)
{
    for (std::shared_ptr<engine::Base> &prefab: this->_prefabs) {
        if (prefab->getUniqueName() == prefabName) {
            return prefab;
        }
    }
}