/*
** EPITECH PROJECT, 2023
** EntityManager.cpp
** File description:
** EntityManager.cpp
*/

#include "uranus/engine/manager/EntityManager.hpp"

void engine::EntityManager::addPrefab(const std::shared_ptr<engine::Base> &prefab)
{
    this->_prefabs.push_back(prefab);
}

std::shared_ptr<engine::Base> engine::EntityManager::getPrefabByName(const std::string &prefabName)
{
    for (const std::shared_ptr<engine::Base> &prefab : this->_prefabs) {
        if (prefab->getUniqueName() == prefabName) {
            return prefab;
        }
    }
}

void engine::EntityManager::killAllPrefabs()
{
    this->_prefabs.clear();
}
