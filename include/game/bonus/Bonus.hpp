/*
** EPITECH PROJECT, 2023
** Bonus.hpp
** File description:
** Bonus.hpp
*/

#ifndef URANUS_BONUS_HPP
#define URANUS_BONUS_HPP

#include "game/Player.hpp"
#include "uranus/engine/Engine.hpp"

namespace bonus {
    class Bonus : public engine::Base {
    public:
        explicit Bonus(const std::string &uniqueName, uranus::ecs::component::Position pos, const std::string &textureName);

        void colliding(size_t entity, size_t entityCollidingWith);

        virtual void loop(size_t entity) = 0;

        virtual void enable(Player &player) = 0;
    };
} // namespace bonus

#endif // URANUS_BASE_HPP
