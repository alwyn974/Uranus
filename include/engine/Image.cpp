//
// Created by nicol on 02/03/2023.
//

#include "Image.hpp"

uranus::Image::Image(const sf::Image &image) : _image(image) {
}

void uranus::Image::create(unsigned int width, unsigned int height, const Color &color) {
    _image.create(width, height, color);
}

void uranus::Image::create(unsigned int width, unsigned int height, const unsigned char *pixels) {
    _image.create(width, height, pixels);
}

bool uranus::Image::loadFromFile(const std::string &path) {
    return _image.loadFromFile(path);
}

bool uranus::Image::loadFromMemory(const void *data, std::size_t size) {
    return _image.loadFromMemory(data, size);
}

bool uranus::Image::loadFromStream(InputStream &stream) {
    return _image.loadFromStream(stream.getInputStream());
}

bool uranus::Image::saveToFile(const std::string &path) const {
    return _image.saveToFile(path);
}

uranus::Vector2u uranus::Image::getSize() const {
    return Vector2u(_image.getSize());
}

void uranus::Image::createMaskFromColor(const Color &color, unsigned char alpha) {
    _image.createMaskFromColor(color, alpha);
}

void uranus::Image::copy(const Image &image, unsigned int destX, unsigned int destY, const IntRect &sourceRect, bool applyAlpha) {
    _image.copy(image._image, destX, destY, sourceRect, applyAlpha);
}

void uranus::Image::setPixel(unsigned int x, unsigned int y, const Color &color) {
    _image.setPixel(x, y, color);
}

uranus::Color uranus::Image::getPixel(unsigned int x, unsigned int y) const {
    return Color(_image.getPixel(x, y));
}

const unsigned char *uranus::Image::getPixelsPtr() const {
    return _image.getPixelsPtr();
}

void uranus::Image::flipHorizontally() {
    _image.flipHorizontally();
}

void uranus::Image::flipVertically() {
    _image.flipVertically();
}

const sf::Image &uranus::Image::getImage() const {
    return _image;
}