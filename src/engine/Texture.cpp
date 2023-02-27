/*
** EPITECH PROJECT, 2023
** Texture.cpp
** File description:
** Texture.cpp
*/

#include "engine/Texture.hpp"

engine::Texture::Texture(const std::string &path)
{
    loadFromFile(path);
}