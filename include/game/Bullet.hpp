/*
** EPITECH PROJECT, 2023
** Bullet.hpp
** File description:
** Bullet.hpp
*/

#ifndef URANUS_BULLET_HPP
#define URANUS_BULLET_HPP

#include "uranus/engine/Engine.hpp"

class Bullet : public engine::Base {
public:
    explicit Bullet(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture);

    virtual void move(size_t entity);

    void colliding(const size_t &entity, const size_t &entityCollidingWith);

    void loop(const size_t);

    void handleKeyboard(size_t entity, const engine::Event event);

protected:
    bool _canMove;
};

#endif // URANUS_BULLET_HPP
