//
// Created by nicol on 02/03/2023.
//

#include "Cursor.hpp"

void uranus::Cursor::loadFromPixels(const unsigned char *pixels, const Vector2u &size, const Vector2u &hotspot)
{
    _cursor.loadFromPixels(pixels, size, hotspot);
}

void uranus::Cursor::loadFromSystem(Type type)
{
    _cursor.loadFromSystem(static_cast<sf::Cursor::Type>(type));
}

const sf::Cursor &uranus::Cursor::getCursor() const
{
    return _cursor;
}
