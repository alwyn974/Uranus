/*
** EPITECH PROJECT, 2023
** Sprite.cpp
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

Sprite::Sprite(std::shared_ptr<sf::Texture> &texture)
{
    this->texture = texture;
    this->sprite.setTexture(*this->texture);
}

sf::Sprite &Sprite::get()
{
    return this->sprite;
}
