//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CIRCLE_HPP
#define URANUS_CIRCLE_HPP

#include "Color.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Rect.hpp"
#include "Transform.hpp"

namespace uranus {
    /**
     * @brief Circle class
     */
    class Circle {
    public:
        /**
         * @brief Default constructor
         * @param radius Radius of the circle
         * @param pointCount Number of points of the circle
         */
        Circle(float radius, std::size_t pointCount = 30);

        /**
         * @brief Default destructor
         */
        ~Circle() = default;

        /**
         * @brief Set the radius of the circle
         * @param radius Radius of the circle
         */
        void setRadius(float radius);

        /**
         * @brief Get the radius of the circle
         * @return Radius of the circle
         */
        float getRadius() const;

        /**
         * @brief Set the number of points of the circle
         * @param pointCount Number of points of the circle
         */
        void setPointCount(std::size_t pointCount);

        /**
         * @brief Get the number of points of the circle
         * @return Number of points of the circle
         */
        std::size_t getPointCount() const;

        /**
         * @brief Get a point of the circle
         * @param index Index of the point
         * @return Point of the circle
         */
        Vector2f getPoint(std::size_t index) const;

        /**
         * @brief Set the texture of the circle
         * @param texture Texture of the circle
         * @param resetRect True to reset the texture rect, false otherwise
         */
        void setTexture(std::shared_ptr<uranus::Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the circle
         * @param textureRect Texture rect of the circle
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the fill color of the circle
         * @param color Fill color of the circle
         */
        void setFillColor(const Color &color);

        /**
         * @brief Set the outline color of the circle
         * @param color Outline color of the circle
         */
        void setOutlineColor(const Color &color);

        /**
         * @brief Set the outline thickness of the circle
         * @param thickness Outline thickness of the circle
         */
        void setOutlineThickness(float thickness);

        /**
         * @brief Get the texture of the circle
         * @return Texture of the circle
         */
        const std::shared_ptr<uranus::Texture> &getTexture() const;

        /**
         * @brief Get the texture rect of the circle
         * @return Texture rect of the circle
         */
        const IntRect &getTextureRect() const;

        /**
         * @brief Get the fill color of the circle
         * @return Fill color of the circle
         */
        const Color &getFillColor() const;

        /**
         * @brief Get the outline color of the circle
         * @return Outline color of the circle
         */
        const Color &getOutlineColor() const;

        /**
         * @brief Get the outline thickness of the circle
         * @return Outline thickness of the circle
         */
        const float &getOutlineThickness() const;

        /**
         * @brief Get the local bounds of the circle
         * @return Local bounds of the circle
         */
        FloatRect getLocalBounds() const;

        /**
         * @brief Get the global bounds of the circle
         * @return Global bounds of the circle
         */
        FloatRect getGlobalBounds() const;

        /**
         * @brief Set the position of the circle
         * @param position Position of the circle
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the circle
         * @param x X position of the circle
         * @param y Y position of the circle
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the rotation of the circle
         * @param angle Angle of the rotation
         */
        void setRotation(float angle);

        /**
         * @brief Set the scale of the circle
         * @param scale Scale of the circle
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the circle
         * @param factorX X scale of the circle
         * @param factorY Y scale of the circle
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the origin of the circle
         * @param origin Origin of the circle
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the circle
         * @param x X origin of the circle
         * @param y Y origin of the circle
         */
        void setOrigin(float x, float y);

        /**
         * @brief Get the position of the circle
         * @return Position of the circle
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the rotation of the circle
         * @return Rotation of the circle
         */
        float getRotation() const;

        /**
         * @brief Get the scale of the circle
         * @return Scale of the circle
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the origin of the circle
         * @return Origin of the circle
         */
        const Vector2f &getOrigin() const;

        /**
         * @brief Move the circle
         * @param offset Offset of the movement
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the circle
         * @param offsetX X offset of the movement
         * @param offsetY Y offset of the movement
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the circle
         * @param angle Angle of the rotation
         */
        void rotate(float angle);

        /**
         * @brief Scale the circle
         * @param factor Scale factor
         */
        void scale(const Vector2f &factor);

        /**
         * @brief Scale the circle
         * @param factorX X scale factor
         * @param factorY Y scale factor
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Get the transform of the circle
         * @return Transform of the circle
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the circle
         * @return Inverse transform of the circle
         */
        const Transform &getInverseTransform() const;

    private:
        /**
         * @brief Update the circle
         */
        void update();

        sf::CircleShape _circle; /**< SFML circle */
        Color _fillColor; /**< Fill color of the circle */
        Color _outlineColor; /**< Outline color of the circle */
        float _outlineThickness; /**< Outline thickness of the circle */
        float _radius; /**< Radius of the circle */
        IntRect _textureRect; /**< Texture rect of the circle */
        std::shared_ptr<uranus::Texture> _texture; /**< Texture of the circle */
        std::size_t _pointCount; /**< Number of points of the circle */
        Transform _transform; /**< Transform of the circle */
        Transform _inverseTransform; /**< Inverse transform of the circle */
    };
}

#endif //URANUS_CIRCLE_HPP
