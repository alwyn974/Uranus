/*
** EPITECH PROJECT, 2023
** DoubleBullet.cpp
** File description:
** DoubleBullet.cpp
*/

#include "uranus/game/bonus/DoubleBullet.hpp"

bonus::DoubleBullet::DoubleBullet(const std::string &uniqueName, component::position pos)
: Bonus(uniqueName, pos, "bonusDoubleBullet")
{
}

void bonus::DoubleBullet::enable(Player &player)
{
    player.enableDoubleBullet();
}

void bonus::DoubleBullet::loop(size_t entity) {}
