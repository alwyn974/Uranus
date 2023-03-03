//
// Created by nicol on 01/03/2023.
//

#ifndef URANUS_COLOR_HPP
#define URANUS_COLOR_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Color class that inherits from sf::Color
     */
    class Color : public sf::Color {
    public:
        /**
         * @brief Default constructor
         */
        Color() = default;

        /**
         * @brief Constructor from a sf::Color
         * @param color to copy
         */
        explicit Color(const sf::Color &color);

        /**
         * @brief Constructor from a RGBA color
         * @param r Red value
         * @param g Green value
         * @param b Blue value
         * @param a Alpha value
         */
        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

        /**
         * @brief Constructor from a RGBA color
         * @param color Color value
         */
        explicit Color(unsigned int color);

        /**
         * @brief Copy constructor
         * @param color to copy
         */
        Color(const Color &color) = default;

        /**
         * @brief Default destructor
         */
        ~Color() = default;

        static const Color BLACK;       /*< Black predefined color*/
        static const Color WHITE;       /*< White predefined color*/
        static const Color RED;         /*< Red predefined color*/
        static const Color GREEN;       /*< Green predefined color*/
        static const Color BLUE;        /*< Blue predefined color*/
        static const Color YELLOW;      /*< Yellow predefined color*/
        static const Color MAGENTA;     /*< Magenta predefined color*/
        static const Color CYAN;        /*< Cyan predefined color*/
        static const Color TRANSPARENT; /*< Transparent predefined color*/
    };


    const Color Color::BLACK(0, 0, 0);
    const Color Color::WHITE(255, 255, 255);
    const Color Color::RED(255, 0, 0);
    const Color Color::GREEN(0, 255, 0);
    const Color Color::BLUE(0, 0, 255);
    const Color Color::YELLOW(255, 255, 0);
    const Color Color::MAGENTA(255, 0, 255);
    const Color Color::CYAN(0, 255, 255);
    const Color Color::TRANSPARENT(0, 0, 0, 0);
}



#endif //URANUS_COLOR_HPP
