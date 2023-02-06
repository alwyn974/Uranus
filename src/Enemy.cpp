/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"
#include "Components.hpp"

Enemy::Enemy(registry &r) : _entity(r.spawn_entity())
{
    r.add_component(this->_entity, component::position{200, 100});
    r.add_component(this->_entity, component::sprite{new Sprite("enemy.png")});
    r.add_component(this->_entity, component::collisionable{ .callback = [&](registry &r, const size_t &entity, const size_t &entity_colliding_with){return;}});
}


