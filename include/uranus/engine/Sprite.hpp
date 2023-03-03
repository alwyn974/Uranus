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

    class Sprite : public sf::Sprite {
    public:
        explicit Sprite(std::shared_ptr<engine::Texture> &texture);

    private:
    };

} // namespace engine

#endif // URANUS_SPRITE_HPP
