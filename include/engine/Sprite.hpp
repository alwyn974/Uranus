/*
** EPITECH PROJECT, 2023
** Sprite.hpp
** File description:
** Sprite.hpp
*/

#ifndef URANUS_SPRITE_HPP
#define URANUS_SPRITE_HPP

#include "Texture.hpp"
#include "Rect.hpp"
#include "Vector2.hpp"
#include "Transform.hpp"
#include "Color.hpp"

namespace uranus {
    /**
     * @brief Sprite class
     */
    class Sprite {
    public:
        /**
         * @brief Default constructor
         */
        Sprite() = default;

        /**
         * @brief Constructor from a texture
         * @param texture Texture of the sprite
         */
        explicit Sprite(std::shared_ptr<engine::Texture> &texture);

        /**
         * @brief Constructor from a texture and a texture rect
         * @param texture Texture of the sprite
         * @param textureRect Rect of the texture
         */
        Sprite(std::shared_ptr<engine::Texture> &texture, const IntRect &textureRect);

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
        void setTexture(std::shared_ptr<engine::Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the sprite
         * @param textureRect Rect of the texture
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the position of the sprite
         * @param position Position of the sprite
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the sprite
         * @param x X coordinate of the position
         * @param y Y coordinate of the position
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the scale of the sprite
         * @param scale Scale of the sprite
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the sprite
         * @param factorX Scale factor on X axis
         * @param factorY Scale factor on Y axis
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the rotation of the sprite
         * @param angle Angle of the rotation
         */
        void setRotation(float angle);

        /**
         * @brief Set the origin of the sprite
         * @param origin Origin of the sprite
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the sprite
         * @param x X coordinate of the origin
         * @param y Y coordinate of the origin
         */
        void setOrigin(float x, float y);

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

        /**
         * @brief Get the position of the sprite
         * @return the position of the sprite
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the scale of the sprite
         * @return the scale of the sprite
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the rotation of the sprite
         * @return the rotation of the sprite
         */
        const float &getRotation() const;

        /**
         * @brief Get the color of the sprite
         * @return the color of the sprite
         */
        const Color &getColor() const;

        /**
         * @brief Get the transform of the sprite
         * @return the transform of the sprite
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the sprite
         * @return the inverse transform of the sprite
         */
        const Transform &getInverseTransform() const;

        /**
         * @brief Move the sprite
         * @param offset Offset of the sprite
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the sprite
         * @param offsetX Offset on X axis
         * @param offsetY Offset on Y axis
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Scale the sprite
         * @param factor Scale factor
         */
        void scale(const Vector2f &factor);

        /**
         * @brief Scale the sprite
         * @param factorX Scale factor on X axis
         * @param factorY Scale factor on Y axis
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Rotate the sprite
         * @param angle Angle of the rotation
         */
        void rotate(float angle);

    private:
        sf::Sprite _sprite; /*< SFML sprite */
        std::shared_ptr<uranus::Texture> _texture; /*< Texture of the sprite */
        Vector2f _position; /*< Position of the sprite */
        Vector2f _scale; /*< Scale of the sprite */
        Vector2f _origin; /*< Origin of the sprite */
        float _rotation; /*< Rotation of the sprite */
        Color _color; /*< Color of the sprite */
        Transform _transform; /*< Transform of the sprite */
        Transform _inverseTransform; /*< Inverse transform of the sprite */
        IntRect _textureRect; /*< Texture rect of the sprite */
    };
}



#endif //URANUS_SPRITE_HPP
