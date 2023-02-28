/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "SceneMain.hpp"

#include "Enemy.hpp"
#include "Player.hpp"


SceneMain::SceneMain() : Scene("Main"){}

void SceneMain::init()
{
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();
    textureManager->addTexture("ship.png", "ship");
    textureManager->addTexture("enemy.png", "enemy");
    textureManager->addTexture("bullet3.png", "bullet");
    textureManager->addTexture("explosion.png", "explosion");

    auto player = std::make_shared<Player>("player", textureManager->getTextureByName("ship"), "bullet");
    entityManager->addPrefab(player);

    component::position pos{500, 20};
    for (int i = 0; i < 10; i++) {
        auto enemy = std::make_shared<Enemy>("enemy", pos, textureManager->getTextureByName("enemy"));
        entityManager->addPrefab(enemy);
        pos.y += 40;
        pos.x += 10;
    }

}
