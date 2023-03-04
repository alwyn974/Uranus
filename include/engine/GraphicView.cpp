//
// Created by nicol on 03/03/2023.
//

#include "GraphicView.hpp"

uranus::View::View(const FloatRect &rectangle) : _view(sf::View(rectangle))
{
}

uranus::View::View(const Vector2f &center, const Vector2f &size) : _view(sf::View(center, size))
{
}

void uranus::View::setCenter(const Vector2f &center)
{
    _view.setCenter(center);
}

void uranus::View::setCenter(float x, float y)
{
    _view.setCenter(x, y);
}

void uranus::View::setSize(const Vector2f &size)
{
    _view.setSize(size);
}

void uranus::View::setSize(float x, float y)
{
    _view.setSize(x, y);
}

void uranus::View::setRotation(float angle)
{
    _view.setRotation(angle);
}

void uranus::View::setViewport(const FloatRect &viewport)
{
    _view.setViewport(viewport);
}

void uranus::View::reset(const FloatRect &rectangle) {
    _view.reset(rectangle);
}

const uranus::Vector2f &uranus::View::getCenter() const {
    return _center;
}

const uranus::Vector2f &uranus::View::getSize() const {
    return _size;
}

float uranus::View::getRotation() const {
    return _view.getRotation();
}

const uranus::FloatRect &uranus::View::getViewport() const {
    return _viewport;
}

void uranus::View::move(const Vector2f &offset) {
    _view.move(offset);
}

void uranus::View::move(float offsetX, float offsetY) {
    _view.move(offsetX, offsetY);
}

void uranus::View::rotate(float angle) {
    _view.rotate(angle);
}

void uranus::View::zoom(float factor) {
    _view.zoom(factor);
}

const uranus::Transform &uranus::View::getTransform() const {
    return _transform;
}

const uranus::Transform &uranus::View::getInverseTransform() const {
    return _inverseTransform;
}