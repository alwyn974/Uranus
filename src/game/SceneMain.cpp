/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "game/SceneMain.hpp"

#include "game/Enemy.hpp"
#include "game/EnemyShooter.hpp"
#include "game/Player.hpp"

#include "game/bonus/DoubleBullet.hpp"

#include "game/ui/Button.hpp"


SceneMain::SceneMain() : Scene("Main"){}

void SceneMain::init()
{
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();
    textureManager->addTexture("ship.png", "ship");
    textureManager->addTexture("enemy.png", "enemy");
    textureManager->addTexture("enemy2.png", "enemyShooter");
    textureManager->addTexture("bullet3.png", "bullet");
    textureManager->addTexture("bulletEnemy.png", "bulletEnemy");
    textureManager->addTexture("explosion.png", "explosion");
    textureManager->addTexture("bonusDouble.png", "bonusDoubleBullet");
    textureManager->addTexture("button.png", "button");

    auto player = std::make_shared<Player>("player", textureManager->getTextureByName("ship"), "bullet");
    entityManager->addPrefab(player);

    component::position pos{500, 20};
    for (int i = 0; i < 10; i++) {
        auto enemy = std::make_shared<Enemy>("enemy", pos, textureManager->getTextureByName("enemy"));
        entityManager->addPrefab(enemy);
        pos.y += 40;
        pos.x += 10;
    }

    auto enemy = std::make_shared<EnemyShooter>("enemyShooter", component::position{700, 100}, textureManager->getTextureByName("enemyShooter"));
    entityManager->addPrefab(enemy);

    auto bonusDoubleBullet = std::make_shared<bonus::DoubleBullet>("bonusDoubleBullet", component::position{200, 300});
    entityManager->addPrefab(bonusDoubleBullet);

    auto button = std::make_shared<ui::Button>("button", component::position{500, 300}, textureManager->getTextureByName("button"));
    entityManager->addPrefab(button);
}
