//
// Created by nicol on 01/03/2023.
//

#include "Transform.hpp"

uranus::Transform::Transform(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22) : sf::Transform(a00, a01, a02, a10, a11, a12, a20, a21, a22)
{
}

uranus::Transform::Transform(const sf::Transform& transform) : sf::Transform(transform)
{
}