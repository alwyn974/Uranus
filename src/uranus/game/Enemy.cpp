/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "uranus/game/Enemy.hpp"

void Enemy::animationCallback(size_t entity, const std::string &animationName)
{
//    std::cout << animationName << std::endl;
}

Enemy::Enemy(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture) : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, component::name{uniqueName});
    r->addComponent(newEntity, component::position{pos.x, pos.y});
    r->addComponent(newEntity, component::velocity {0, 0});
    r->addComponent(newEntity, component::sprite {std::make_shared<engine::Sprite>(texture)});

    std::array<bool, LAYER_SIZE> layer{true, false, false, false};
    std::array<bool, MASK_SIZE> mask{false, false, false, false};
    r->addComponent(newEntity, component::collisionable {0, 0, 30, 30, layer, mask, \
    [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});

    r->addComponent(newEntity, component::loop {[&](const size_t entity) { this->loop(entity); }});

    r->addComponent(newEntity, component::animation{6, 1, \
    [&](const size_t entity, const std::string &animationName) { this->animationCallback(entity, animationName);}});

    engine::system::addNewAnimation(newEntity, "idle", true, 0.6);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.0, 0);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.1, 1);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.2, 2);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.3, 3);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.4, 4);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.5, 5);

    engine::system::playAnimation(newEntity, "idle");
}

void Enemy::loop(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = -0.5;
}

void Enemy::colliding(const size_t &entity, const size_t &entityCollidingWith) {}
