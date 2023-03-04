//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CIRCLE_HPP
#define URANUS_CIRCLE_HPP

#include "Shape.hpp"

namespace uranus {
    /**
     * @brief Circle class
     */
    class Circle : public Shape {
    public:
        /**
         * @brief Default constructor
         * @param radius Radius of the circle
         * @param pointCount Number of points of the circle
         */
        explicit Circle(float radius, std::size_t pointCount = 30);

        /**
         * @brief Default destructor
         */
        ~Circle() override = default;

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

    private:
        sf::CircleShape _circle; /**< SFML circle */
    };
}

#endif //URANUS_CIRCLE_HPP
