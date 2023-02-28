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

SceneMain::SceneMain() : Scene("Main")
{}

void SceneMain::init()
{
    auto &textureManager = engine::Manager::getTextureManager();
    textureManager->addTexture("ship.png", "ship");
    textureManager->addTexture("enemy.png", "enemy");
    textureManager->addTexture("bullet2.png", "bullet");

    auto &entityManager = engine::Manager::getEntityManager();


    auto player = std::make_shared<Player>("player", textureManager->getTextureByName("ship"), "bullet");

    component::position pos{500, 20};
    for (int i = 0; i < 10; i++) {
        auto enemy = std::make_shared<Enemy>("enemy", pos, textureManager->getTextureByName("enemy"));
        entityManager->addPrefab(enemy);
        pos.y += 40;
    }

    entityManager->addPrefab(player);
}
