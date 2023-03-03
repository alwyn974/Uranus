//
// Created by nicol on 01/03/2023.
//

#ifndef URANUS_VECTOR2_HPP
#define URANUS_VECTOR2_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Vector2 class that inherits from sf::Vector2
     * @tparam T Type of the vector
     */
    template<typename T>
    class Vector2 : public sf::Vector2<T> {
    public:
        /**
         * @brief Default constructor
         */
        Vector2() = default;

        /**
         * @brief Constructor from a sf::Vector2
         * @param vector to copy
         */
        Vector2(T x, T y);

        /**
         * @brief Constructor from a sf::Vector2
         * @param vector to copy
         */
        explicit Vector2(const sf::Vector2<T> &vector);

        /**
         * @brief Copy constructor
         * @param vector to copy
         */
        Vector2(const Vector2<T> &vector) = default;

        /**
         * @brief Default destructor
         */
        ~Vector2() = default;
    };

    typedef Vector2<float> Vector2f; /**< Vector2 of float */
    typedef Vector2<int> Vector2i; /**< Vector2 of int */
    typedef Vector2<unsigned int> Vector2u; /**< Vector2 of unsigned int */
}



#endif //URANUS_VECTOR2_HPP
