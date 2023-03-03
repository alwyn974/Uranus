//
// Created by nicol on 01/03/2023.
//

#include "Color.hpp"

uranus::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : sf::Color(r, g, b, a)
{
}

uranus::Color::Color(unsigned int color) : sf::Color(color)
{
}

uranus::Color::Color(const sf::Color &color) : sf::Color(color)
{
}


