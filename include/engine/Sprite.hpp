/*
** EPITECH PROJECT, 2023
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef URANUS_SPRITE_HPP
#define URANUS_SPRITE_HPP

#include "Drawable.hpp"
#include "Transformable.hpp"

namespace uranus {
    /**
     * @brief Sprite class
     */
    class Sprite : public Drawable, public Transformable {
    public:
        /**
         * @brief Default constructor
         */
        Sprite() = default;

        /**
         * @brief Constructor from a texture
         * @param texture Texture of the sprite
         */
        explicit Sprite(std::shared_ptr<uranus::Texture> &texture);

        /**
         * @brief Constructor from a texture and a texture rect
         * @param texture Texture of the sprite
         * @param textureRect Rect of the texture
         */
        Sprite(std::shared_ptr<uranus::Texture> &texture, const IntRect &textureRect);

        /**
         * @brief Copy constructor
         * @param sprite to copy
         */
        Sprite(const Sprite &sprite) = default;

        /**
         * @brief Default destructor
         */
        ~Sprite() = default;

        /**
         * @brief Set the texture of the sprite
         * @param texture Texture of the sprite
         */
        void setTexture(std::shared_ptr<uranus::Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the sprite
         * @param textureRect Rect of the texture
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the color of the sprite
         * @param color Color of the sprite
         */
        void setColor(const Color &color);

        /**
         * @brief Get the texture of the sprite
         * @return the texture of the sprite
         */
        const std::shared_ptr<uranus::Texture> &getTexture() const;

        /**
         * @brief Get the texture rect of the sprite
         * @return the texture rect of the sprite
         */
        const IntRect &getTextureRect() const;

        /**
         * @brief Get the global bounds of the sprite
         * @return the global bounds of the sprite
         */
        FloatRect getGlobalBounds() const;

        /**
         * @brief Get the local bounds of the sprite
         * @return the local bounds of the sprite
         */
        FloatRect getLocalBounds() const;

    private:
        /**
         * @brief Draw the sprite
         * @param target Target to draw the sprite
         * @param states States of the sprite
         */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        /**
         * @brief Update the positions of the sprite
         */
        void updatePositions() const;

        /**
         * @brief Update the texture coordinates of the sprite
         */
        void updateTexCoords() const;

        sf::Sprite _sprite; /*< SFML sprite */
        std::shared_ptr<uranus::Texture> _texture; /*< Texture of the sprite */
        IntRect _textureRect; /*< Texture rect of the sprite */
    };
}



#endif //URANUS_SPRITE_HPP
