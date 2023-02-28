/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "SceneMain.hpp"

#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Map.hpp"

SceneMain::SceneMain() : Scene("Main")
{}

void SceneMain::init()
{
    auto &textureManager = engine::Manager::getTextureManager();
    textureManager->addTexture("../ship.png", "ship");
    textureManager->addTexture("../enemy.png", "enemy");
    textureManager->addTexture("../bullet.png", "bullet");
    textureManager->addTexture("../ship.png", "tile");

    auto player = std::make_shared<Player>(textureManager->getTextureByName("ship"), "bullet");
    auto enemy = std::make_shared<Enemy>(textureManager->getTextureByName("enemy"));

    auto &entityManager = engine::Manager::getEntityManager();
    entityManager->addPrefab(player);
    entityManager->addPrefab(enemy);
}
