/*
** EPITECH PROJECT, 2023
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef URANUS_SPRITE_HPP
#define URANUS_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Sprite {
public:
    ~Sprite() = default;
    explicit Sprite(std::shared_ptr<sf::Texture> &texture);
    sf::Sprite &get();

private:
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture;
};

#endif // URANUS_SPRITE_HPP
