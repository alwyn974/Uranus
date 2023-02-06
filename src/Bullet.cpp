/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "Bullet.hpp"

Bullet::Bullet(registry &r, component::position pos) : _entity(r.spawn_entity())
{
    Entity e2(r.spawn_entity());
    r.add_component(e2, component::position {pos.x, pos.y});
    r.add_component(e2, component::velocity {0, 0});
    r.add_component(e2, component::sprite {new Sprite("bullet.png")});
    r.add_component(
        e2,
        component::collisionable {
            0, 0, 20, 20, [&](registry &r, const size_t &entity, const size_t &entity_colliding_with) { this->colliding(r, entity, entity_colliding_with); }});
    r.add_component(e2, component::loop {.update = [&](registry &r, const size_t entity) { this->loop(r, entity); }});
}

void Bullet::move(registry &r, size_t entity)
{
    auto &vel = r.get_component<component::velocity>(entity);
    vel->x = 5;
}

void Bullet::loop(registry &r, const size_t entity)
{
    this->move(r, entity);
}

void Bullet::colliding(registry &r, const size_t &entity, const size_t &entity_colliding_with)
{
    r.kill_entity(r.entity_from_index(entity));
    r.kill_entity(r.entity_from_index(entity_colliding_with));
}
