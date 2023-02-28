/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

Enemy::Enemy(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture) : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity entity = r->entityFromIndex(this->_entityId);

    r->addComponent(entity, component::position{pos.x, pos.y});
    r->addComponent(entity, component::velocity {0, 0});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(entity, component::collisionable {0, 0, 30, 30, [&](const size_t &, const size_t &) { return; }});

    r->addComponent(entity, component::loop {.update = [&](const size_t entity) { this->loop(entity); }});


    r->addComponent(entity, component::animation{6, 1});
    engine::system::addNewAnimation(entity, "idle", true, 0.6);
    engine::system::insertAnimationFrame(entity, "idle", 0.0, 0);
    engine::system::insertAnimationFrame(entity, "idle", 0.1, 1);
    engine::system::insertAnimationFrame(entity, "idle", 0.2, 2);
    engine::system::insertAnimationFrame(entity, "idle", 0.3, 3);
    engine::system::insertAnimationFrame(entity, "idle", 0.4, 4);
    engine::system::insertAnimationFrame(entity, "idle", 0.5, 5);

    engine::system::playAnimation(entity, "idle");
}

void Enemy::loop(const size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = -0.1;
}
