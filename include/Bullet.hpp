/*
** EPITECH PROJECT, 2023
** Bullet.hpp
** File description:
** Bullet.hpp
*/

#ifndef URANUS_BULLET_HPP
#define URANUS_BULLET_HPP

#include "engine/Engine.hpp"
#include "ecs/Components.hpp"

class Bullet : public engine::Base {
public:
    ~Bullet() = default;
    explicit Bullet(component::position pos, std::shared_ptr<engine::Texture> &texture);
    void move(size_t entity);
    void colliding(const size_t &entity, const size_t &entityCollidingWith);
    void loop(const size_t);
    void handleKeyboard(size_t entity, const engine::Event event);
private:
    bool canMove;
};

#endif // URANUS_BULLET_HPP
