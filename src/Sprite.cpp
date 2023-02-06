/*
** EPITECH PROJECT, 2023
** Sprite.cpp
** File description:
** Sprite.cpp
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string &file_path)
{
    this->texture.loadFromFile(file_path);
    this->sprite.setTexture(this->texture);
}
sf::Sprite &Sprite::get(){
return this->sprite;
}
