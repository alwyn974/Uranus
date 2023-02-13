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
    explicit Bullet(ecs::Registry &r, component::position pos);
    void move(ecs::Registry &r, size_t entity);
    void colliding(ecs::Registry &r, const size_t &entity, const size_t &entity_colliding_with);
    void loop(ecs::Registry &r, const size_t);

private:
    ecs::Entity _entity;
};

#endif // URANUS_BULLET_HPP
