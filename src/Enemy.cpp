/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

Enemy::Enemy(ecs::Registry &r, std::shared_ptr<engine::Texture> &texture) : _entity(r.spawnEntity())
{
    r.addComponent(this->_entity, component::position {200, 100});
    r.addComponent(this->_entity, component::sprite {new engine::Sprite(texture)});
    r.addComponent(this->_entity, component::collisionable {0, 0, 30, 30, [&](ecs::Registry &r, const size_t &, const size_t &) { return; }});
}
