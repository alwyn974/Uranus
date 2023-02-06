/*
** EPITECH PROJECT, 2023
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef URANUS_SPRITE_HPP
#define URANUS_SPRITE_HPP

#include <SFML/Graphics.hpp>

class Sprite {
public:
    ~Sprite() = default;
    Sprite(const std::string &file_path);
    sf::Sprite &get();

private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // URANUS_SPRITE_HPP
