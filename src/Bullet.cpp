/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include <iostream>
#include "Bullet.hpp"

Bullet::Bullet(registry &r, component::position pos) : _entity(r.spawn_entity())
{
    std::cout << "this.bullet: " << this->_entity << std::endl;
  /*  r.add_component(this->_entity, component::position {pos.x, pos.y});
    r.add_component(this->_entity, component::velocity {0, 0});
    r.add_component(this->_entity, component::sprite { new Sprite("bullet.png")});
    sf::FloatRect box{0, 0, 15, 15};
    r.add_component(
        this->_entity,
        component::collisionable {box, [&](registry &r, const size_t &entity, const size_t &entity_colliding_with) { this->colliding(r, entity, entity_colliding_with); }});
    r.add_component(this->_entity, component::loop {[&](registry &r, const size_t entity) { this->loop(r, entity); }});*/

    r.add_component(this->_entity, component::position {pos.x, pos.y});
    r.add_component(this->_entity, component::velocity {0, 0});
    r.add_component(this->_entity, component::sprite {new Sprite("bullet.png")});
    r.add_component(this->_entity, component::loop {[&](registry &r, const size_t entity) { this->loop(r, entity); }});

}

void Bullet::move(registry &r, const size_t entity)
{
    auto &vel = r.get_component<component::velocity>(entity);
    vel->x = 5;
}

void Bullet::loop(registry &r, const size_t entity)
{
    auto &pos = r.get_component<component::position>(entity);
    this->move(r, entity);
//    std::cout <<z "bullet loop: " << this->_entity << std::endl;

    if (pos->x > 500) {
        std::cout << "call kill: " << this->_entity << std::endl;
        r.kill_entity(r.entity_from_index(entity));
    }
}

void Bullet::colliding(registry &r, const size_t &entity, const size_t &entity_colliding_with)
{
    r.kill_entity(r.entity_from_index(entity));
    r.kill_entity(r.entity_from_index(entity_colliding_with));
}
