/*
** EPITECH PROJECT, 2023
** EntityManager.hpp
** File description:
** EntityManager.hpp
*/

#ifndef URANUS_ENTITYMANAGER_HPP
#define URANUS_ENTITYMANAGER_HPP

#include "Base.hpp"

namespace engine {
    class EntityManager {
    public:

        explicit EntityManager() = default;

        ~EntityManager() = default;

        void addPrefab(const std::shared_ptr<engine::Base> &prefab);

        std::shared_ptr<engine::Base> &getPrefabByName(const std::string &prefabName);

    private:
        std::vector<std::shared_ptr<engine::Base>> _prefabs;
    };
}

#endif //URANUS_ENTITYMANAGER_HPP
