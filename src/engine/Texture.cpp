/*
** EPITECH PROJECT, 2023
** Texture.cpp
** File description:
** Texture.cpp
*/

#include "uranus/engine/components/Texture.hpp"

engine::Texture::Texture(const std::string &path, const std::string &name)
{
    loadFromFile(path);
    this->_name = name;
}

const std::string &engine::Texture::getName() const
{
    return this->_name;
}
