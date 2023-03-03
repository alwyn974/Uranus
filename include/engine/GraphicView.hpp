//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_VIEW_HPP
#define URANUS_VIEW_HPP

#include "Rect.hpp"
#include "Vector2.hpp"
#include "Transform.hpp"

namespace uranus {
    /**
     * @brief View class
     */
    class View {
    public:
        /**
         * @brief Default constructor
         */
        View() = default;

        /**
         * @brief Constructor from a rectangle
         * @param rectangle Rectangle to construct from
         */
        View(const FloatRect &rectangle);

        /**
         * @brief Constructor from a center and a size
         * @param center Center to construct from
         * @param size Size to construct from
         */
        View(const Vector2f &center, const Vector2f &size);

        /**
         * @brief Default destructor
         */
        ~View() = default;

        /**
         * @brief Get the center of the view
         * @return Center of the view
         */
        void setCenter(const Vector2f &center);

        /**
         * @brief Set the center of the view
         * @param x X coordinate of the center
         * @param y Y coordinate of the center
         */
        void setCenter(float x, float y);

        /**
         * @brief Get the size of the view
         * @return Size of the view
         */
        void setSize(const Vector2f &size);

        /**
         * @brief Set the size of the view
         * @param width Width of the view
         * @param height Height of the view
         */
        void setSize(float width, float height);

        /**
         * @brief Set the rotation of the view
         * @param angle Angle of the rotation
         */
        void setRotation(float angle);

        /**
         * @brief Set the viewport of the view
         * @param viewport Viewport of the view
         */
        void setViewport(const FloatRect &viewport);

        /**
         * @brief Reset the view
         * @param rectangle Rectangle to reset from
         */
        void reset(const FloatRect &rectangle);

        /**
         * @brief Get the center of the view
         * @return Center of the view
         */
        const Vector2f &getCenter() const;

        /**
         * @brief Get the size of the view
         * @return Size of the view
         */
        const Vector2f &getSize() const;

        /**
         * @brief Get the rotation of the view
         * @return Rotation of the view
         */
        float getRotation() const;

        /**
         * @brief Get the viewport of the view
         * @return Viewport of the view
         */
        const FloatRect &getViewport() const;

        /**
         * @brief Move the view
         * @param offset Offset to move the view
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the view
         * @param offsetX Offset on the X axis
         * @param offsetY Offset on the Y axis
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the view
         * @param angle Angle to rotate the view
         */
        void rotate(float angle);

        /**
         * @brief Zoom the view
         * @param factor Factor to zoom the view
         */
        void zoom(float factor);

        /**
         * @brief Get the transform of the view
         * @return Transform of the view
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the view
         * @return Inverse transform of the view
         */
        const Transform &getInverseTransform() const;

    private:
        sf::View _view /**< SFML view */;
        Vector2f _center /**< Center of the view */;
        Vector2f _size /**< Size of the view */;
        float _rotation /**< Rotation of the view */;
        Transform _transform /**< Transform of the view */;
        Transform _inverseTransform /**< Inverse transform of the view */;
        FloatRect _viewport /**< Viewport of the view */;
    };
}


#endif //URANUS_VIEW_HPP
