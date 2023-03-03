//
// Created by nicol on 01/03/2023.
//

#ifndef URANUS_RECT_HPP
#define URANUS_RECT_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Rect class that inherits from sf::Rect
     */
    template<typename T>
    class Rect : public sf::Rect<T> {
    public:
        /**
         * @brief Default constructor
         */
        Rect() = default;

        /**
         * @brief Constructor from left, top, width and height
         * @param rect to copy
         */
        Rect(T left, T top, T width, T height);

        /**
         * @brief Constructor from a sf::Rect
         * @param rect to copy
         */
        explicit Rect(const sf::Rect<T> &rect);

        /**
         * @brief Copy constructor
         * @param rect to copy
         */
        Rect(const Rect<T> &rect) = default;

        /**
         * @brief Default destructor
         */
        ~Rect() = default;
    };

    typedef Rect<float> FloatRect; /**< Rect of float */
    typedef Rect<int> IntRect; /**< Rect of int */
}


#endif //URANUS_RECT_HPP
