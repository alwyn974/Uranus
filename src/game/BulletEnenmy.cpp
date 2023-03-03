/*
** EPITECH PROJECT, 2023
** BulletEnenmy.cpp
** File description:
** BulletEnenmy.cpp
*/

#include "game/BulletEnemy.hpp"

BulletEnemy::BulletEnemy(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture) :
    Bullet(uniqueName, pos, texture)
{
    std::array<bool, MASK_SIZE> mask {false, true, false, false};
    engine::system::setMask(this->_entityId, mask);
    this->_canMove = true;
    engine::system::stopAnimation(this->_entityId);
}

void BulletEnemy::move(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<uranus::ecs::component::Velocity>(entity);
    vel->value().x = -5;
    if (r->getComponent<uranus::ecs::component::Position>(entity)->value().x < -100) {
        r->killEntity(entity);
    }
}
