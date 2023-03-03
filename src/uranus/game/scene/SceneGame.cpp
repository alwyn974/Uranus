/*
** EPITECH PROJECT, 2023
** SceneGame.cpp
** File description:
** SceneGame.cpp
*/

#include "uranus/game/scene/SceneGame.hpp"

#include "uranus/game/Enemy.hpp"
#include "uranus/game/EnemyShooter.hpp"
#include "uranus/game/Player.hpp"

#include "uranus/game/bonus/DoubleBullet.hpp"

#include "uranus/game/ui/Button.hpp"

SceneGame::SceneGame() : Scene("Game"){}

void SceneGame::init()
{
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();

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
}