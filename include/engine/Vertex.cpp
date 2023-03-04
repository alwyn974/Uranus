//
// Created by nicol on 04/03/2023.
//

#include "Vertex.hpp"

uranus::Vertex::Vertex(const Vector2f &position) : sf::Vertex(position)
{
}

uranus::Vertex::Vertex(const Vector2f &position, const Color &color) : sf::Vertex(position, color)
{
}

uranus::Vertex::Vertex(const Vector2f &position, const Vector2f &texCoords) : sf::Vertex(position, texCoords)
{
}

uranus::Vertex::Vertex(const Vector2f &position, const Color &color, const Vector2f &texCoords) : sf::Vertex(position, color, texCoords)
{
}



