/*
** EPITECH PROJECT, 2023
** EnemyShooter.cpp
** File description:
** EnemyShooter.cpp
*/

#include "game/EnemyShooter.hpp"
#include "game/BulletEnemy.hpp"
#include <cmath>

EnemyShooter::EnemyShooter(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture)
    : Enemy(uniqueName, pos, texture)
{
}

void EnemyShooter::loop(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<uranus::ecs::component::Velocity>(entity);
    vel->value().x = -0.5;

    vel->value().y = sin(1 * this->_movementClock.getElapsedTime().asSeconds()) * 3;

    if (this->_shootClock.getElapsedTime().asSeconds() > 0.5) {
        auto &textureManager = engine::Manager::getTextureManager();
        auto &entityManager = engine::Manager::getEntityManager();

        auto &pos = r->getComponent<uranus::ecs::component::Position>(entity);
        auto bullet = std::make_shared<BulletEnemy>("bullet", uranus::ecs::component::Position{pos->value().x - 30, pos->value().y}, textureManager->getTextureByName("bulletEnemy"));
        entityManager->addPrefab(bullet);

        this->_shootClock.restart();
    }
}