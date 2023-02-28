/*
** EPITECH PROJECT, 2023
** Enemy.hpp
** File description:
** Enemy.hpp
*/

#ifndef URANUS_ENEMY_HPP
#define URANUS_ENEMY_HPP

#include "engine/Engine.hpp"

class Enemy : public engine::Base {
public:
    ~Enemy() = default;
    explicit Enemy(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture);
    void loop(const size_t);
    void animationCallback(const size_t entity, const std::string &animationName);
private:
};

#endif // URANUS_ENEMY_HPP
