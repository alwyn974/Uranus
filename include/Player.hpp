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


class Player {
public:
    ~Player() = default;
    explicit Player(ecs::Registry &r, std::shared_ptr<engine::Texture> &texture, std::string &&bulletPath);
    //    void handle_input(ecs::Registry &r, size_t entity, const sf::Event event);
    void move(ecs::Registry &r, size_t entity, const engine::Event event);
    void loop();

private:
    ecs::Entity _entity;
    std::shared_ptr<engine::Texture> _bullet_texture;
};

#endif // URANUS_PLAYER_HPP
