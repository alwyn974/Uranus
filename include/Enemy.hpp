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

class Enemy : public engine::Base {
public:
    ~Enemy() = default;
    explicit Enemy(std::shared_ptr<engine::Texture> &texture);
    void loop(const size_t);
private:
};

#endif // URANUS_ENEMY_HPP
