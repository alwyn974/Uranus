//
// Created by nicol on 01/03/2023.
//

#ifndef URANUS_TRANSFORM_HPP
#define URANUS_TRANSFORM_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Transform class that inherits from sf::Transform
     */
    class Transform : public sf::Transform {
    public:
        /**
         * @brief Default constructor
         */
        Transform() = default;

        /**
         * @brief Constructor from a matrix
         * @param a00 Element at row 0, column 0
         * @param a01 Element at row 0, column 1
         * @param a02 Element at row 0, column 2
         * @param a10 Element at row 1, column 0
         * @param a11 Element at row 1, column 1
         * @param a12 Element at row 1, column 2
         * @param a20 Element at row 2, column 0
         * @param a21 Element at row 2, column 1
         * @param a22 Element at row 2, column 2
         */
        Transform(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22);

        /**
         * @brief Copy constructor
         * @param transform to copy
         */
        Transform(const Transform& transform) = default;

        /**
         * @brief Constructor from sf::Transform
         * @param transform Transform to copy
         */
        explicit Transform(const sf::Transform& transform);

        /**
         * @brief Default destructor
         */
        ~Transform() = default;
    };
}


#endif //URANUS_TRANSFORM_HPP
