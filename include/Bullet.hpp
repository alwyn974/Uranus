/*
** EPITECH PROJECT, 2023
** Bullet.hpp
** File description:
** Bullet.hpp
*/

#ifndef URANUS_BULLET_HPP
#define URANUS_BULLET_HPP

#include <SFML/Window.hpp>

#include "Components.hpp"
#include "Entity.hpp"
#include "Registry.hpp"

class Bullet {
public:
    ~Bullet() = default;
    explicit Bullet(registry &r, component::position pos);
    void move(registry &r, size_t entity);
    void colliding(registry &r, const size_t &entity, const size_t &entity_colliding_with);
    void loop(registry &r, const size_t);

private:
    Entity _entity;
};

#endif // URANUS_BULLET_HPP
