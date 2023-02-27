/*
** EPITECH PROJECT, 2023
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef URANUS_SPRITE_HPP
#define URANUS_SPRITE_HPP

#include "Texture.hpp"

namespace engine {

    class Sprite: public sf::Sprite {
    public:
        explicit Sprite(const engine::Texture &texture);
        explicit Sprite(std::shared_ptr<engine::Texture> &texture);
    };
}



#endif //URANUS_SPRITE_HPP
