/*
** EPITECH PROJECT, 2023
** Sprite.cpp
** File description:
** Sprite.cpp
*/

#include "uranus/engine/Sprite.hpp"

engine::Sprite::Sprite(std::shared_ptr<engine::Texture> &texture) : sf::Sprite(*texture) {}
