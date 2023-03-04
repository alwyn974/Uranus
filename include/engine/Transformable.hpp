/*
** EPITECH PROJECT, 2023
** Transformable.hpp
** File description:
** Transformable.hpp
*/


#ifndef URANUS_TRANSFORMABLE_HPP
#define URANUS_TRANSFORMABLE_HPP

#include "Vector2.hpp"
#include "Transform.hpp"

namespace uranus {
    /**
     * @brief Transformable class
     */
    class Transformable {
    public:
        /**
         * @brief Default constructor
         */
        Transformable() = default;

        /**
         * @brief Default destructor
         */
        virtual ~Transformable() = default;

        /**
         * @brief Set the position of the transformable.
         * @param position Position to set.
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the transformable.
         * @param x X position to set.
         * @param y Y position to set.
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the rotation of the transformable.
         * @param angle Angle to set.
         */
        void setRotation(float angle);

        /**
         * @brief Set the scale of the transformable.
         * @param scale Scale to set.
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the transformable.
         * @param factorX X factor to set.
         * @param factorY Y factor to set.
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the origin of the transformable.
         * @param origin Origin to set.
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the transformable.
         * @param x X origin to set.
         * @param y Y origin to set.
         */
        void setOrigin(float x, float y);

        /**
         * @brief Get the position of the transformable.
         * @return Position of the transformable.
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the rotation of the transformable.
         * @return Rotation of the transformable.
         */
        float getRotation() const;

        /**
         * @brief Get the scale of the transformable.
         * @return Scale of the transformable.
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the origin of the transformable.
         * @return Origin of the transformable.
         */
        const Vector2f &getOrigin() const;

        /**
         * @brief Move the transformable.
         * @param offset Offset to move.
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the transformable.
         * @param offsetX X offset to move.
         * @param offsetY Y offset to move.
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the transformable.
         * @param angle Angle to rotate.
         */
        void rotate(float angle);

        /**
         * @brief Scale the transformable.
         * @param factor Scale factor.
         */
        void scale(const Vector2f &factor);

        /**
         * @brief Scale the transformable.
         * @param factorX X scale factor.
         * @param factorY Y scale factor.
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Get the transform of the transformable.
         * @return Transform of the transformable.
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the transformable.
         * @return Inverse transform of the transformable.
         */
        const Transform &getInverseTransform() const;

    protected:
        Vector2f _position; /**< Position of the transformable. */
        float _rotation; /**< Rotation of the transformable. */
        Vector2f _scale; /**< Scale of the transformable. */
        Vector2f _origin; /**< Origin of the transformable. */
        Transform _transform; /**< Transform of the transformable. */
        Transform _inverseTransform; /**< Inverse transform of the transformable. */
    };
}


#endif //URANUS_TRANSFORMABLE_HPP
