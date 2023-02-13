/*
** EPITECH PROJECT, 2023
** Enemy.hpp
** File description:
** Enemy.hpp
*/

#ifndef URANUS_ENEMY_HPP
#define URANUS_ENEMY_HPP

#include <SFML/Window.hpp>

#include "Entity.hpp"
#include "Registry.hpp"

class Enemy {
public:
    ~Enemy() = default;
    explicit Enemy(ecs::Registry &r);

private:
    ecs::Entity _entity;
};

#endif // URANUS_ENEMY_HPP
