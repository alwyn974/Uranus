/*
** EPITECH PROJECT, 2023
** DoubleBullet.cpp
** File description:
** DoubleBullet.cpp
*/

#include "game/bonus/DoubleBullet.hpp"

bonus::DoubleBullet::DoubleBullet(const std::string &uniqueName, uranus::ecs::component::Position pos) : Bonus(uniqueName, pos, "bonusDoubleBullet") {}

void bonus::DoubleBullet::enable(Player &player)
{
    player.enableDoubleBullet();
}

void bonus::DoubleBullet::loop(size_t entity) {}
