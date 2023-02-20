/*
** EPITECH PROJECT, 2023
** Button.hpp
** File description:
** Button.hpp
*/

#ifndef URANUS_BUTTON_HPP
#define URANUS_BUTTON_HPP

#include <SFML/Window.hpp>

#include "Entity.hpp"
#include "Systems.hpp"

class Button {
public:
    ~Button() = default;
    explicit Button(ecs::Registry &r, const std::string spritePath, std::function<void(ecs::Registry &r, const size_t)> buttonPressed);
    void loop(ecs::Registry &r, const size_t entity, const sf::Event event);
private:
    ecs::Entity _entity;
    sf::FloatRect _spriteSize;
    std::function<void(ecs::Registry &r, const size_t)> _buttonPressed;
};

#endif //URANUS_BUTTON_HPP
