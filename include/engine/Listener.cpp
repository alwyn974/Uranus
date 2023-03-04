//
// Created by nicol on 03/03/2023.
//

#include "Listener.hpp"

void uranus::Listener::setGlobalVolume(float volume) {
    sf::Listener::setGlobalVolume(volume);
}

float uranus::Listener::getGlobalVolume() {
    return sf::Listener::getGlobalVolume();
}

void uranus::Listener::setPosition(const Vector3f &position) {
    sf::Listener::setPosition(position.x, position.y, position.z);
}

void uranus::Listener::setPosition(float x, float y, float z) {
    sf::Listener::setPosition(x, y, z);
}

uranus::Vector3f uranus::Listener::getPosition() {
    return Vector3f(sf::Listener::getPosition().x, sf::Listener::getPosition().y, sf::Listener::getPosition().z);
}

void uranus::Listener::setDirection(const Vector3f &direction) {
    sf::Listener::setDirection(direction.x, direction.y, direction.z);
}

void uranus::Listener::setDirection(float x, float y, float z) {
    sf::Listener::setDirection(x, y, z);
}

uranus::Vector3f uranus::Listener::getDirection() {
    return Vector3f(sf::Listener::getDirection().x, sf::Listener::getDirection().y, sf::Listener::getDirection().z);
}

void uranus::Listener::setUpVector(const Vector3f &upVector) {
    sf::Listener::setUpVector(upVector.x, upVector.y, upVector.z);
}

void uranus::Listener::setUpVector(float x, float y, float z) {
    sf::Listener::setUpVector(x, y, z);
}

uranus::Vector3f uranus::Listener::getUpVector() {
    return Vector3f(sf::Listener::getUpVector());
}