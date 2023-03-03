/*
** EPITECH PROJECT, 2023
** BonusDoubleBullet.hpp
** File description:
** BonusDoubleBullet.hpp
*/

#ifndef URANUS_DOUBLEBULLET_HPP
#define URANUS_DOUBLEBULLET_HPP

#include "Bonus.hpp"

namespace bonus {
    class DoubleBullet : public Bonus {
    public:
        DoubleBullet(const std::string &uniqueName, uranus::ecs::component::Position pos);

        void enable(Player &player) override;

        void loop(size_t entity) override;
    };
} // namespace bonus

#endif // URANUS_DOUBLEBULLET_HPP
