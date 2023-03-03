//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CONVEX_HPP
#define URANUS_CONVEX_HPP

#include "Color.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
#include "Rect.hpp"
#include "Transform.hpp"

namespace uranus {
    /*
     * @brief Convex class
     */
    class Convex {
    public:
        /**
         * @brief Default constructor
         */
         Convex(std::size_t pointCount = 0);

         /**
          * @brief Default destructor
          */
        ~Convex() = default;

        /**
         * @brief Set the number of points of the convex
         * @param pointCount Number of points of the convex
         */
        void setPointCount(std::size_t pointCount);

        /**
         * @brief Get the number of points of the convex
         * @return Number of points of the convex
         */
        std::size_t getPointCount() const;

        /**
         * @brief Set a point of the convex
         * @param index Index of the point
         * @param point Point of the convex
         */
        void setPoint(std::size_t index, const Vector2f &point);

        /**
         * @brief Get a point of the convex
         * @param index Index of the point
         * @return Point of the convex
         */
        Vector2f getPoint(std::size_t index) const;

        /**
         * @brief Set the texture of the convex
         * @param texture Texture of the convex
         */
        void setTexture(std::shared_ptr<uranus::Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the convex
         * @param textureRect Rect of the texture
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the fill color of the convex
         * @param color Fill color of the convex
         */
        void setFillColor(const Color &color);

        /**
         * @brief Set the outline color of the convex
         * @param color Outline color of the convex
         */
        void setOutlineColor(const Color &color);

        /**
         * @brief Set the outline thickness of the convex
         * @param thickness Outline thickness of the convex
         */
        void setOutlineThickness(float thickness);

        /**
         * @brief Get the texture of the convex
         * @return Texture of the convex
         */
        const std::shared_ptr<uranus::Texture> &getTexture() const;

        /**
         * @brief Get the texture rect of the convex
         * @return Texture rect of the convex
         */
        const IntRect &getTextureRect() const;

        /**
         * @brief Get the fill color of the convex
         * @return Fill color of the convex
         */
        const Color &getFillColor() const;

        /**
         * @brief Get the outline color of the convex
         * @return Outline color of the convex
         */
        const Color &getOutlineColor() const;

        /**
         * @brief Get the outline thickness of the convex
         * @return Outline thickness of the convex
         */
        float getOutlineThickness() const;

        /**
         * @brief Get the local bounds of the convex
         * @return Local bounds of the convex
         */
        FloatRect getLocalBounds() const;

        /**
         * @brief Get the global bounds of the convex
         * @return Global bounds of the convex
         */
        FloatRect getGlobalBounds() const;

        /**
         * @brief Set the position of the convex
         * @param position Position of the convex
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the convex
         * @param x X position of the convex
         * @param y Y position of the convex
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the rotation of the convex
         * @param angle Angle of the rotation
         */
        void setRotation(float angle);

        /**
         * @brief Set the scale of the convex
         * @param scale Scale of the convex
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the convex
         * @param factorX X factor of the scale
         * @param factorY Y factor of the scale
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the origin of the convex
         * @param origin Origin of the convex
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the convex
         * @param x X origin of the convex
         * @param y Y origin of the convex
         */
        void setOrigin(float x, float y);

        /**
         * @brief Get the position of the convex
         * @return Position of the convex
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the rotation of the convex
         * @return Rotation of the convex
         */
        float getRotation() const;

        /**
         * @brief Get the scale of the convex
         * @return Scale of the convex
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the origin of the convex
         * @return Origin of the convex
         */
        const Vector2f &getOrigin() const;

        /**
         * @brief Move the convex
         * @param offset Offset of the movement
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the convex
         * @param offsetX X offset of the movement
         * @param offsetY Y offset of the movement
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the convex
         * @param angle Angle of the rotation
         */
        void rotate(float angle);

        /**
         * @brief Scale the convex
         * @param factors Scale factors
         */
        void scale(const Vector2f &factors);

        /**
         * @brief Scale the convex
         * @param factorX X factor of the scale
         * @param factorY Y factor of the scale
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Get the transform of the convex
         * @return Transform of the convex
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the convex
         * @return Inverse transform of the convex
         */
        const Transform &getInverseTransform() const;
    private:
        /**
         * @brief Update the convex
         */
        void update();

        sf::ConvexShape _convex; /**< SFML convex */
        std::shared_ptr<uranus::Texture> _texture; /**< Texture of the convex */
        IntRect _textureRect; /**< Texture rect of the convex */
        Color _fillColor; /**< Fill color of the convex */
        Color _outlineColor; /**< Outline color of the convex */
        float _outlineThickness; /**< Outline thickness of the convex */
        Vector2f _position; /**< Position of the convex */
        float _rotation; /**< Rotation of the convex */
        Vector2f _scale; /**< Scale of the convex */
        Vector2f _origin; /**< Origin of the convex */
        Transform _transform; /**< Transform of the convex */
        Transform _inverseTransform; /**< Inverse transform of the convex */
    };
}


#endif //URANUS_CONVEX_HPP
