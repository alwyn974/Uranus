/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "Bullet.hpp"


Bullet::Bullet(ecs::Registry &r, component::position pos, std::shared_ptr<engine::Texture> &texture) : _entity(r.spawnEntity())
{
    r.addComponent(this->_entity, component::position {pos.x, pos.y});
    r.addComponent(this->_entity, component::velocity {0, 0});
    r.addComponent(this->_entity, component::sprite {new engine::Sprite(texture)});
    r.addComponent(
        this->_entity,
        component::collisionable {
            0, 0, 18, 15, [&](ecs::Registry &r, const size_t &entity, const size_t &entity_colliding_with) { this->colliding(r, entity, entity_colliding_with); }});
    r.addComponent(this->_entity, component::loop {.update = [&](ecs::Registry &r, const size_t entity) { this->loop(r, entity); }});
}

void Bullet::move(ecs::Registry &r, size_t entity)
{
    auto &vel = r.getComponent<component::velocity>(entity);
    vel->value().x = 5;
}

void Bullet::loop(ecs::Registry &r, const size_t entity)
{
    this->move(r, entity);
    if (r.getComponent<component::position>(entity)->value().x > 600) {
        r.killEntity(r.entityFromIndex(entity));
    }
}

void Bullet::colliding(ecs::Registry &r, const size_t &entity, const size_t &entity_colliding_with)
{
    r.killEntity(r.entityFromIndex(entity));
    r.killEntity(r.entityFromIndex(entity_colliding_with));
}
