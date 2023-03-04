/*
** EPITECH PROJECT, 2023
** Texture.cpp
** File description:
** Texture.cpp
*/

#include "engine/Texture.hpp"

uranus::Texture::Texture(const std::string &path) {
    _texture.loadFromFile(path);
}

bool uranus::Texture::create(unsigned int width, unsigned int height) {
    return _texture.create(width, height);
}

bool uranus::Texture::loadFromFile(const std::string &path, const uranus::IntRect &area) {
   return _texture.loadFromFile(path, area);
}

bool uranus::Texture::loadFromMemory(const void *data, std::size_t size, const uranus::IntRect &area) {
    return _texture.loadFromMemory(data, size, area);
}

bool uranus::Texture::loadFromStream(uranus::InputStream &stream, const uranus::IntRect &area) {
    return _texture.loadFromStream(stream.getInputStream(), area);
}

bool uranus::Texture::loadFromImage(const uranus::Image &image, const uranus::IntRect &area) {
    return _texture.loadFromImage(image.getImage(), area);
}

uranus::Vector2u uranus::Texture::getSize() const {
    return Vector2u(_texture.getSize());
}

const sf::Texture &uranus::Texture::getTexture() const {
    return _texture;
}

uranus::Image uranus::Texture::copyToImage() const {
    return Image(_texture.copyToImage());
}

void uranus::Texture::update(const sf::Uint8 *pixels) {
    _texture.update(pixels);
}

void uranus::Texture::update(const sf::Uint8 *pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y) {
    _texture.update(pixels, width, height, x, y);
}

void uranus::Texture::update(const uranus::Texture &texture) {
    _texture.update(texture.getTexture());
}

void uranus::Texture::update(const uranus::Texture &texture, unsigned int x, unsigned int y) {
    _texture.update(texture.getTexture(), x, y);
}

void uranus::Texture::update(const uranus::Image &image) {
    _texture.update(image.getImage());
}

void uranus::Texture::update(const uranus::Image &image, unsigned int x, unsigned int y) {
    _texture.update(image.getImage(), x, y);
}

void uranus::Texture::update(const uranus::Window &window) {
    _texture.update(window.getWindow());
}

void uranus::Texture::update(const uranus::Window &window, unsigned int x, unsigned int y) {
    _texture.update(window.getWindow(), x, y);
}

void uranus::Texture::setSmooth(bool smooth) {
    _texture.setSmooth(smooth);
}

void uranus::Texture::setRepeated(bool repeated) {
    _texture.setRepeated(repeated);
}

bool uranus::Texture::isSmooth() const {
    return _texture.isSmooth();
}

bool uranus::Texture::isRepeated() const {
    return _texture.isRepeated();
}

void uranus::Texture::setSrgb(bool srgb) {
    _texture.setSrgb(srgb);
}

bool uranus::Texture::isSrgb() const {
    return _texture.isSrgb();
}

bool uranus::Texture::generateMipmap() {
    return _texture.generateMipmap();
}

void uranus::Texture::swap(Texture &texture) {
    *this = texture;
}

unsigned int uranus::Texture::getNativeHandle() const {
    return _texture.getNativeHandle();
}

void uranus::Texture::bind(const Texture texture, CoordinateType type) {
    sf::Texture::bind(&texture.getTexture(), static_cast<sf::Texture::CoordinateType>(type));
}

unsigned int uranus::Texture::getMaximumSize() {
    return sf::Texture::getMaximumSize();
}
