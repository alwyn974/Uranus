/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "Bullet.hpp"


Bullet::Bullet(component::position pos, std::shared_ptr<engine::Texture> &texture)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity entity = r->spawnEntity();

    r->addComponent(entity, component::position {pos.x, pos.y});
    r->addComponent(entity, component::velocity {0, 0});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(entity, component::collisionable {
            0, 0, 18, 15, [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});
    r->addComponent(entity, component::loop {.update = [&](const size_t entity) { this->loop(entity); }});
}

void Bullet::move(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = 5;
}

void Bullet::loop(const size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    this->move(entity);
    if (r->getComponent<component::position>(entity)->value().x > 600) {
        r->killEntity(r->entityFromIndex(entity));
    }
}

void Bullet::colliding(const size_t &entity, const size_t &entityCollidingWith)
{
    auto &r = engine::Manager::getRegistry();
    r->killEntity(r->entityFromIndex(entity));
    r->killEntity(r->entityFromIndex(entityCollidingWith));
}
