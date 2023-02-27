/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

Enemy::Enemy(std::shared_ptr<engine::Texture> &texture)
{
    ecs::Registry *r = engine::Manager::getRegistry();
    ecs::Entity entity = r->spawnEntity();
    r->addComponent(entity, component::position {200, 100});
    r->addComponent(entity, component::sprite {new engine::Sprite(texture)});
    r->addComponent(entity, component::collisionable {0, 0, 30, 30, [&](const size_t &, const size_t &) { return; }});
}
