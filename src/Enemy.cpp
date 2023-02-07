/*
** EPITECH PROJECT, 2023
** Enemy.cpp
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

#include "Components.hpp"

Enemy::Enemy(registry &r, component::position pos) : _entity(r.spawn_entity())
{
    r.add_component(this->_entity, component::position {pos.x, pos.y});
    r.add_component(this->_entity, component::sprite {new Sprite("enemy.png")});
    sf::FloatRect box{0, 0, 28, 28};
    r.add_component(
        this->_entity, component::collisionable {box, [&](registry &r, const size_t &entity, const size_t &entity_colliding_with) { return; }});
    r.add_component(this->_entity, component::loop {[&](registry &r, const size_t entity) { this->loop(r, entity); }});
}

void Enemy::loop(registry &r, const size_t entity)
{
//    std::cout << "enemy loop: " << this->_entity << ", vs: " << entity << std::endl;
//    printf("%p, %p\n", &this->_entity, r.entity_from_index(entity));
}
