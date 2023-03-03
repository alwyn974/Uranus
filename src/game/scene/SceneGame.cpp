/*
** EPITECH PROJECT, 2023
** SceneGame.cpp
** File description:
** SceneGame.cpp
*/

#include "game/scene/SceneGame.hpp"
#include "game/bonus/DoubleBullet.hpp"
#include "game/Enemy.hpp"
#include "game/EnemyShooter.hpp"
#include "game/Player.hpp"
#include "game/ui/Button.hpp"

SceneGame::SceneGame() : Scene("Game") {}

void SceneGame::init()
{
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();

    auto player = std::make_shared<Player>("player", textureManager->getTextureByName("ship"), "bullet");
    entityManager->addPrefab(player);

    uranus::ecs::component::Position pos {500, 20};
    for (int i = 0; i < 10; i++) {
        auto enemy = std::make_shared<Enemy>("enemy", pos, textureManager->getTextureByName("enemy"));
        entityManager->addPrefab(enemy);
        pos.y += 40;
        pos.x += 10;
    }

    auto enemy = std::make_shared<EnemyShooter>("enemyShooter", uranus::ecs::component::Position {700, 100}, textureManager->getTextureByName("enemyShooter"));
    entityManager->addPrefab(enemy);

    auto bonusDoubleBullet = std::make_shared<bonus::DoubleBullet>("bonusDoubleBullet", uranus::ecs::component::Position {200, 300});
    entityManager->addPrefab(bonusDoubleBullet);
}
