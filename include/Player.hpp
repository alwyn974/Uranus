/*
** EPITECH PROJECT, 2023
** Player.hpp
** File description:
** Player.hpp
*/

#ifndef URANUS_PLAYER_HPP
#define URANUS_PLAYER_HPP

#include <SFML/Window.hpp>

#include "Entity.hpp"
#include "Registry.hpp"

class Player {
public:
    ~Player() = default;
    explicit Player(registry &r);
    //    void handle_input(registry &r, size_t entity, const sf::Event event);
    void move(registry &r, size_t entity, const sf::Event event);
    void loop();

private:
    Entity _entity;
};

#endif // URANUS_PLAYER_HPP
