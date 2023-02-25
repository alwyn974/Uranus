/*
** EPITECH PROJECT, 2023
** Player.hpp
** File description:
** Player.hpp
*/

#ifndef URANUS_PLAYER_HPP
#define URANUS_PLAYER_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Registry.hpp"

class Player {
public:
    ~Player() = default;
    explicit Player(ecs::Registry &r, std::shared_ptr<sf::Texture> &texture, std::string &&bulletPath);
    //    void handle_input(ecs::Registry &r, size_t entity, const sf::Event event);
    void move(ecs::Registry &r, size_t entity, const sf::Event event);
    void loop();

private:
    ecs::Entity _entity;
    std::shared_ptr<sf::Texture> _bullet_texture;
};

#endif // URANUS_PLAYER_HPP
