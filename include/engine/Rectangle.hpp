//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_RECTANGLE_HPP
#define URANUS_RECTANGLE_HPP

#include "Shape.hpp"

namespace uranus {
    /**
     * @brief Rectangle class
     */
    class Rectangle : public Shape {
    public:
        /**
         * @brief Default constructor
         */
        explicit Rectangle(const Vector2f &size = Vector2f(0, 0));

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

    private:
        sf::RectangleShape _rectangle /**< SFML rectangle */;
        Vector2f _size /**< Size of the rectangle */;
    };
}


#endif //URANUS_RECTANGLE_HPP
