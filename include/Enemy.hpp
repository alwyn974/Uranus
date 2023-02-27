/*
** EPITECH PROJECT, 2023
** Enemy.hpp
** File description:
** Enemy.hpp
*/

#ifndef URANUS_ENEMY_HPP
#define URANUS_ENEMY_HPP

#include "engine/Engine.hpp"
#include "ecs/Components.hpp"

class Enemy {
public:
    ~Enemy() = default;
    explicit Enemy(ecs::Registry &r, std::shared_ptr<engine::Texture> &texture);

private:
    ecs::Entity _entity;
};

#endif // URANUS_ENEMY_HPP
