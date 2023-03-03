/*
** EPITECH PROJECT, 2023
** Sprite.cpp
** File description:
** Sprite.cpp
*/

#include "engine/Sprite.hpp"

uranus::Sprite::Sprite(std::shared_ptr<engine::Texture> &texture) :
_sprite(*texture),
_texture(texture),
_textureRect(_sprite.getTextureRect()),
_color(_sprite.getColor()),
_position(_sprite.getPosition()),
_scale(_sprite.getScale()),
_rotation(_sprite.getRotation()),
_origin(_sprite.getOrigin()),
_transform(_sprite.getTransform()),
_inverseTransform(_sprite.getInverseTransform())
{
}

uranus::Sprite::Sprite(std::shared_ptr<engine::Texture> &texture, const IntRect &rectangle) :
_sprite(*texture, rectangle),
_texture(texture),
_textureRect(_sprite.getTextureRect()),
_color(_sprite.getColor()),
_position(_sprite.getPosition()),
_scale(_sprite.getScale()),
_rotation(_sprite.getRotation()),
_origin(_sprite.getOrigin()),
_transform(_sprite.getTransform()),
_inverseTransform(_sprite.getInverseTransform())
{
}

void uranus::Sprite::setTexture(std::shared_ptr<engine::Texture> &texture, bool resetRect)
{
    _texture = texture;
    _sprite.setTexture(*texture, resetRect);
}

void uranus::Sprite::setTextureRect(const IntRect &rectangle)
{
    _textureRect = rectangle;
    _sprite.setTextureRect(rectangle);
}

void uranus::Sprite::setColor(const Color &color)
{
    _color = color;
    _sprite.setColor(color);
}

void uranus::Sprite::setPosition(const Vector2f &position)
{
    _position = position;
    _sprite.setPosition(position);
}

void uranus::Sprite::setPosition(float x, float y)
{
    _position = Vector2f(x, y);
    _sprite.setPosition(x, y);
}

void uranus::Sprite::setScale(const Vector2f &scale)
{
    _scale = scale;
    _sprite.setScale(scale);
}

void uranus::Sprite::setScale(float x, float y)
{
    _scale = Vector2f(x, y);
    _sprite.setScale(x, y);
}

void uranus::Sprite::setRotation(float angle)
{
    _rotation = angle;
    _sprite.setRotation(angle);
}

void uranus::Sprite::setOrigin(const Vector2f &origin)
{
    _origin = origin;
    _sprite.setOrigin(origin);
}

void uranus::Sprite::setOrigin(float x, float y)
{
    _origin = Vector2f(x, y);
    _sprite.setOrigin(x, y);
}

const std::shared_ptr<uranus::Texture> &uranus::Sprite::getTexture() const {
    return _texture;
}

const uranus::IntRect &uranus::Sprite::getTextureRect() const {
    return _textureRect;
}

uranus::FloatRect uranus::Sprite::getGlobalBounds() const
{
    return FloatRect(_sprite.getGlobalBounds());
}

uranus::FloatRect uranus::Sprite::getLocalBounds() const
{
    return FloatRect(_sprite.getLocalBounds());
}

const uranus::Vector2f &uranus::Sprite::getPosition() const {
    return _position;
}

const uranus::Vector2f &uranus::Sprite::getScale() const {
    return _scale;
}

const float &uranus::Sprite::getRotation() const {
    return _rotation;
}

const uranus::Color &uranus::Sprite::getColor() const {
    return _color;
}

const uranus::Transform &uranus::Sprite::getTransform() const {
    return _transform;
}

const uranus::Transform &uranus::Sprite::getInverseTransform() const {
    return _inverseTransform;
}

void uranus::Sprite::move(const Vector2f &offset)
{
    _position += offset;
    _sprite.move(offset);
}

void uranus::Sprite::move(float x, float y)
{
    _position += Vector2f(x, y);
    _sprite.move(x, y);
}

void uranus::Sprite::scale(const Vector2f &factors)
{
    _scale.x *= factors.x;
    _scale.y *= factors.y;
    _sprite.scale(factors);
}

void uranus::Sprite::scale(float x, float y)
{
    _scale.x *= x;
    _scale.y *= y;
    _sprite.scale(x, y);
}

void uranus::Sprite::rotate(float angle)
{
    _rotation += angle;
    _sprite.rotate(angle);
}
