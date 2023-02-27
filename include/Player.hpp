/*
** EPITECH PROJECT, 2023
** Player.hpp
** File description:
** Player.hpp
*/

#ifndef URANUS_PLAYER_HPP
#define URANUS_PLAYER_HPP

#include "engine/Engine.hpp"
#include "ecs/Components.hpp"

class Player : public engine::Base {
public:
    ~Player() = default;
    explicit Player(std::shared_ptr<engine::Texture> &texture, const std::string &_bulletTextureName);
    void move(size_t entity, const engine::Event event);
private:
    std::string _bulletTextureName;
};

#endif // URANUS_PLAYER_HPP
