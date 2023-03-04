//
// Created by nicol on 02/03/2023.
//

#include "engine/Circle.hpp"

uranus::Circle::Circle(float radius, std::size_t pointCount) : _circle(radius, pointCount)
{
}

void uranus::Circle::setRadius(float radius)
{
    _circle.setRadius(radius);
}

float uranus::Circle::getRadius() const
{
    return _circle.getRadius();
}

void uranus::Circle::setPointCount(std::size_t pointCount)
{
    _circle.setPointCount(pointCount);
}

std::size_t uranus::Circle::getPointCount() const
{
    return _circle.getPointCount();
}

uranus::Vector2f uranus::Circle::getPoint(std::size_t index) const
{
    return Vector2f(_circle.getPoint(index));
}