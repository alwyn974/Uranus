//
// Created by nicol on 03/03/2023.
//

#include "Rectangle.hpp"

uranus::Rectangle::Rectangle(const Vector2f &size) : _rectangle(size) {}

void uranus::Rectangle::setSize(const Vector2f &size) {
    _rectangle.setSize(size);
}

const uranus::Vector2f &uranus::Rectangle::getSize() const {
    return _size;
}

std::size_t uranus::Rectangle::getPointCount() const {
    return 4;
}

uranus::Vector2f uranus::Rectangle::getPoint(std::size_t index) const {
    _rectangle.getPoint(index);
}
