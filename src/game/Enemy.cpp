/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "game/Enemy.hpp"

void Enemy::animationCallback(size_t entity, const std::string &animationName)
{
    //    std::cout << animationName << std::endl;
}

Enemy::Enemy(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture) : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    uranus::ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, uranus::ecs::component::Name {uniqueName});
    r->addComponent(newEntity, uranus::ecs::component::Position {pos.x, pos.y});
    r->addComponent(newEntity, uranus::ecs::component::Velocity {0, 0});
    r->addComponent(newEntity, uranus::ecs::component::Sprite {std::make_shared<engine::Sprite>(texture)});

    std::array<bool, LAYER_SIZE> layer {true, false, false, false};
    std::array<bool, MASK_SIZE> mask {false, false, false, false};
    r->addComponent(
        newEntity,
        uranus::ecs::component::Collisionable {
            0, 0, 30, 30, layer, mask, [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});

    r->addComponent(newEntity, uranus::ecs::component::Loop {[&](const size_t entity) { this->loop(entity); }});

    r->addComponent(newEntity, uranus::ecs::component::Animation {
                                   6, 1, [&](const size_t entity, const std::string &animationName) { this->animationCallback(entity, animationName); }});

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
    auto &vel = r->getComponent<uranus::ecs::component::Velocity>(entity);
    vel->value().x = -0.5;
}

void Enemy::colliding(const size_t &entity, const size_t &entityCollidingWith) {}
