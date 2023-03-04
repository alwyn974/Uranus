//
// Created by nicol on 02/03/2023.
//

#include "Convex.hpp"

uranus::Convex::Convex(std::size_t pointCount) : _convex(pointCount) {
}

void uranus::Convex::setPointCount(std::size_t pointCount) {
    _convex.setPointCount(pointCount);
}

std::size_t uranus::Convex::getPointCount() const {
    return _convex.getPointCount();
}

void uranus::Convex::setPoint(std::size_t index, const Vector2f &point) {
    _convex.setPoint(index, sf::Vector2f(point.x, point.y));
}

uranus::Vector2f uranus::Convex::getPoint(std::size_t index) const {
    return Vector2f(_convex.getPoint(index));
}