//
// Created by nicol on 03/03/2023.
//

#include "Mouse.hpp"

bool uranus::Mouse::isButtonPressed(Mouse::Button button) {
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}

uranus::Vector2i uranus::Mouse::getPosition(const Window &relativeTo) {
    return Vector2i(sf::Mouse::getPosition(relativeTo.getWindow()));
}

void uranus::Mouse::setPosition(const Vector2i &position) {
    sf::Mouse::setPosition(position);
}

void uranus::Mouse::setPosition(const Vector2i &position, const Window &relativeTo) {
    sf::Mouse::setPosition(position, relativeTo.getWindow());
}

uranus::Vector2i uranus::Mouse::getPosition() {
    return Vector2i(sf::Mouse::getPosition());
}