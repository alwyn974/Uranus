/*
** EPITECH PROJECT, 2023
** Transformable.cpp
** File description:
** Transformable.cpp
*/


#include "Transformable.hpp"

void uranus::Transformable::setPosition(float x, float y) {
    _position.x = x;
    _position.y = y;
    _transformable.setPosition(x, y);
}

void uranus::Transformable::setPosition(const uranus::Vector2f &position) {
    _position = position;
    _transformable.setPosition(position.x, position.y);
}

void uranus::Transformable::setRotation(float angle) {
    _rotation = angle;
    _transformable.setRotation(angle);
}

void uranus::Transformable::setScale(const uranus::Vector2f &scale) {
    _scale = scale;
    _transformable.setScale(scale.x, scale.y);
}

void uranus::Transformable::setScale(float factorX, float factorY) {
    _scale.x = factorX;
    _scale.y = factorY;
    _transformable.setScale(factorX, factorY);
}

void uranus::Transformable::setOrigin(const uranus::Vector2f &origin) {
    _origin = origin;
    _transformable.setOrigin(origin.x, origin.y);
}

void uranus::Transformable::setOrigin(float x, float y) {
    _origin.x = x;
    _origin.y = y;
    _transformable.setOrigin(x, y);
}

const uranus::Vector2f &uranus::Transformable::getPosition() const {
    return _position;
}

float uranus::Transformable::getRotation() const {
    return _rotation;
}

const uranus::Vector2f &uranus::Transformable::getScale() const {
    return _scale;
}

const uranus::Vector2f &uranus::Transformable::getOrigin() const {
    return _origin;
}

void uranus::Transformable::move(float offsetX, float offsetY) {
    _position.x += offsetX;
    _position.y += offsetY;
    _transformable.move(offsetX, offsetY);
}

void uranus::Transformable::move(const uranus::Vector2f &offset) {
    _position.x += offset.x;
    _position.y += offset.y;
    _transformable.move(offset.x, offset.y);
}

void uranus::Transformable::rotate(float angle) {
    _rotation += angle;
    _transformable.rotate(angle);
}

void uranus::Transformable::scale(const Vector2f &factor) {
    _scale.x *= factor.x;
    _scale.y *= factor.y;
    _transformable.scale(factor.x, factor.y);
}

void uranus::Transformable::scale(float factorX, float factorY) {
    _scale.x *= factorX;
    _scale.y *= factorY;
    _transformable.scale(factorX, factorY);
}

const uranus::Transform &uranus::Transformable::getTransform() const {
    return _transform;
}

const uranus::Transform &uranus::Transformable::getInverseTransform() const {
    return _inverseTransform;
}

sf::Transformable &uranus::Transformable::getTransformable() {
    return _transformable;
}