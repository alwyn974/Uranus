/*
** EPITECH PROJECT, 2023
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef URANUS_TEXTURE_HPP
#define URANUS_TEXTURE_HPP

#include "Dependencies.hpp"

namespace engine {

class Texture: public sf::Texture {
public:
    explicit Texture(const std::string &path);
};

}

#endif //URANUS_TEXTURE_HPP
