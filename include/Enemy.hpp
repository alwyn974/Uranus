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
#include "Components.hpp"

class Enemy {
public:
    ~Enemy() = default;
    explicit Enemy(registry &r, component::position pos);
    void loop(registry &r, const size_t);

private:
    Entity _entity;
};

#endif // URANUS_ENEMY_HPP
