/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

Enemy::Enemy(std::shared_ptr<engine::Texture> &texture)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity entity = r->entityFromIndex(this->_entityId);

    r->addComponent(entity, component::position {200, 100});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(entity, component::collisionable {0, 0, 30, 30, [&](const size_t &, const size_t &) { return; }});

//    r->addComponent(entity, component::loop {.update = [&](const size_t entity) { this->loop(entity); }});
}

void Enemy::loop(const size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = -5;
}
