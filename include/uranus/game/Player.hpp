/*
** EPITECH PROJECT, 2023
** Player.hpp
** File description:
** Player.hpp
*/

#ifndef URANUS_PLAYER_HPP
#define URANUS_PLAYER_HPP

#include "uranus/engine/Engine.hpp"

class Player : public engine::Base {
public:
    explicit Player(const std::string &uniqueName, std::shared_ptr<engine::Texture> &texture, const std::string &bulletTextureName);

    void move(size_t entity, const engine::Event event);

    void shoot();

    void colliding(const size_t &entity, const size_t &entityCollidingWith);

    void enableDoubleBullet();

private:
    std::string _bulletTextureName;

    bool _doubleBullet;
};

#endif // URANUS_PLAYER_HPP
