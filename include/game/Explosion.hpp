/*
** EPITECH PROJECT, 2023
** Explosion.hpp
** File description:
** Explosion.hpp
*/

#ifndef URANUS_EXPLOSION_HPP
#define URANUS_EXPLOSION_HPP

#include "uranus/engine/Engine.hpp"

class Explosion : public engine::Base {
public:
    explicit Explosion(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture);
    void animationCallback(const size_t entity, const std::string &animationName);
};

#endif // URANUS_EXPLOSION_HPP
