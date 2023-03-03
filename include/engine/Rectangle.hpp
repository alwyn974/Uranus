//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_RECTANGLE_HPP
#define URANUS_RECTANGLE_HPP

#include "Color.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Rect.hpp"
#include "Transform.hpp"

namespace uranus {
    /**
     * @brief Rectangle class
     */
    class Rectangle {
    public:
        /**
         * @brief Default constructor
         */
        Rectangle(const Vector2f &size = Vector2f(0, 0));

        /**
         * @brief Set the size of the rectangle
         * @param size Size of the rectangle
         */
        void setSize(const Vector2f &size);

        /**
         * @brief Get the size of the rectangle
         * @return Size of the rectangle
         */
        const Vector2f &getSize() const;

        /**
         * @brief Get the number of points of the rectangle
         * @return Number of points of the rectangle
         */
        std::size_t getPointCount() const;

        /**
         * @brief Get a point of the rectangle
         * @param index Index of the point
         * @return Point of the rectangle
         */
        Vector2f getPoint(std::size_t index) const;

        /**
         * @brief Set the texture of the rectangle
         * @param texture Texture of the rectangle
         * @param resetRect True to reset the texture rect, false otherwise
         */
        void setTexture(const std::shared_ptr<Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the rectangle
         * @param textureRect Texture rect of the rectangle
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the fill color of the rectangle
         * @brief color Fill color of the rectangle
         */
        void setFillColor(const Color &color);

        /**
         * @brief Set the outline color of the rectangle
         * @param color Outline color of the rectangle
         */
        void setOutlineColor(const Color &color);

        /**
         * @brief Set the outline thickness of the rectangle
         * @param thickness Outline thickness of the rectangle
         */
        void setOutlineThickness(float thickness);

        /**
         * @brief Get the texture of the rectangle
         * @return Texture of the rectangle
         */
        const std::shared_ptr<Texture> &getTexture() const;

        /**
         * @brief Get the texture rect of the rectangle
         * @return Texture rect of the rectangle
         */
        const IntRect &getTextureRect() const;

        /**
         * @brief Get the fill color of the rectangle
         * @return Fill color of the rectangle
         */
        const Color &getFillColor() const;

        /**
         * @brief Get the outline color of the rectangle
         * @return Outline color of the rectangle
         */
        const Color &getOutlineColor() const;

        /**
         * @brief Get the outline thickness of the rectangle
         * @return Outline thickness of the rectangle
         */
        float getOutlineThickness() const;

        /**
         * @brief Get the local bounds of the rectangle
         * @return Local bounds of the rectangle
         */
        FloatRect getLocalBounds() const;

        /**
         * @brief Get the global bounds of the rectangle
         * @return Global bounds of the rectangle
         */
        FloatRect getGlobalBounds() const;

        /**
         * @brief Set the position of the rectangle
         * @param position Position of the rectangle
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the rectangle
         * @param x X position of the rectangle
         * @param y Y position of the rectangle
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the rotation of the rectangle
         * @param angle Angle of the rotation
         */
        void setRotation(float angle);

        /**
         * @brief Set the scale of the rectangle
         * @param scale Scale of the rectangle
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the rectangle
         * @param factorX X factor of the scale
         * @param factorY Y factor of the scale
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the origin of the rectangle
         * @param origin Origin of the rectangle
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the rectangle
         * @param x X origin of the rectangle
         * @param y Y origin of the rectangle
         */
        void setOrigin(float x, float y);

        /**
         * @brief Get the position of the rectangle
         * @return Position of the rectangle
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the rotation of the rectangle
         * @return Rotation of the rectangle
         */
        float getRotation() const;

        /**
         * @brief Get the scale of the rectangle
         * @return Scale of the rectangle
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the origin of the rectangle
         * @return Origin of the rectangle
         */
        const Vector2f &getOrigin() const;

        /**
         * @brief Move the rectangle
         * @param offset Offset of the movement
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the rectangle
         * @param offsetX X offset of the movement
         * @param offsetY Y offset of the movement
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the rectangle
         * @param angle Angle of the rotation
         */
        void rotate(float angle);

        /**
         * @brief Scale the rectangle
         * @param factors Scale factors
         */
        void scale(const Vector2f &factors);

        /**
         * @brief Scale the rectangle
         * @param factorX X factor of the scale
         * @param factorY Y factor of the scale
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Get the transform of the rectangle
         * @return Transform of the rectangle
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the rectangle
         * @return Inverse transform of the rectangle
         */
        const Transform &getInverseTransform() const;
    private:
        /**
         * @brief Update the rectangle
         */
        void update();

        sf::RectangleShape _rectangle /**< SFML rectangle */;
        Vector2f _size /**< Size of the rectangle */;
        Vector2f _position /**< Position of the rectangle */;
        Vector2f _origin /**< Origin of the rectangle */;
        Vector2f _scale /**< Scale of the rectangle */;
        float _rotation /**< Rotation of the rectangle */;
        std::shared_ptr<Texture> _texture /**< Texture of the rectangle */;
        IntRect _textureRect /**< Texture rect of the rectangle */;
        Transform _transform /**< Transform of the rectangle */;
        Transform _inverseTransform /**< Inverse transform of the rectangle */;
        Color _fillColor /**< Fill color of the rectangle */;
        Color _outlineColor /**< Outline color of the rectangle */;
        float _outlineThickness /**< Outline thickness of the rectangle */;
    };
}


#endif //URANUS_RECTANGLE_HPP
