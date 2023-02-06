/*
** EPITECH PROJECT, 2023
** Enemy.hpp
** File description:
** Enemy.hpp
*/

#ifndef URANUS_ENEMY_HPP
#define URANUS_ENEMY_HPP

#include "Entity.hpp"
#include "Registry.hpp"
#include <SFML/Window.hpp>

class Enemy {
public:
    ~Enemy() = default;
    explicit Enemy(registry &r);
private:
    Entity _entity;
};

#endif //URANUS_ENEMY_HPP
