/*
** EPITECH PROJECT, 2023
** EnemyShooter.cpp
** File description:
** EnemyShooter.cpp
*/

#include "EnemyShooter.hpp"
#include "BulletEnemy.hpp"
#include <cmath>

EnemyShooter::EnemyShooter(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture)
    : Enemy(uniqueName, pos, texture)
{
    this->_tick = 0;
}

void EnemyShooter::loop(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = -0.5;

    this->_tick += 0.1;
    vel->value().y = sin(1 * this->_sineClock.getElapsedTime().asSeconds()) * 3;

    std::cout << this->_tick << std::endl;

    if (this->_clock.getElapsedTime().asSeconds() > 1) {
        auto &textureManager = engine::Manager::getTextureManager();
        auto &entityManager = engine::Manager::getEntityManager();

        auto &pos = r->getComponent<component::position>(entity);
        auto bullet = std::make_shared<BulletEnemy>("bullet", component::position{pos->value().x - 30, pos->value().y}, textureManager->getTextureByName("bulletEnemy"));
        entityManager->addPrefab(bullet);

        this->_clock.restart();
    }
}