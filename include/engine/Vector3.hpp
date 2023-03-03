//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_VECTOR3_HPP
#define URANUS_VECTOR3_HPP

#include "SFML/Graphics.hpp"

namespace uranus {
    /**
     * @brief Vector3 class that inherits from sf::Vector3
     * @tparam T Type of the vector
     */
    template<typename T>
    class Vector3 : public sf::Vector3<T> {
    public:
        /**
         * @brief Default constructor
         */
        Vector3() = default;

        /**
         * @brief Constructor from a sf::Vector3
         * @param vector to copy
         */
        Vector3(T x, T y, T z);

        /**
         * @brief Constructor from a sf::Vector3
         * @param vector to copy
         */
        explicit Vector3(const sf::Vector3<T> &vector);

        /**
         * @brief Copy constructor
         * @param vector to copy
         */
        Vector3(const Vector3<T> &vector) = default;

        /**
         * @brief Default destructor
         */
        ~Vector3() = default;
    };

    typedef Vector3<float> Vector3f; /*< Vector3 of float */
    typedef Vector3<int> Vector3i; /*< Vector3 of int */
    typedef Vector3<unsigned int> Vector3u; /*< Vector3 of unsigned int */
}


#endif //URANUS_VECTOR3_HPP
