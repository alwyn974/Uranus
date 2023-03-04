//
// Created by nicol on 03/03/2023.
//

#include "RenderTexture.hpp"

bool uranus::RenderTexture::create(unsigned int width, unsigned int height, const sf::ContextSettings &settings) {
    return _renderTexture.create(width, height);
}

unsigned int uranus::RenderTexture::getMaximumAntialiasingLevel() {
    return sf::RenderTexture::getMaximumAntialiasingLevel();
}

void uranus::RenderTexture::setSmooth(bool smooth) {
    _renderTexture.setSmooth(smooth);
}

bool uranus::RenderTexture::isSmooth() const {
    return _renderTexture.isSmooth();
}

void uranus::RenderTexture::setRepeated(bool repeated) {
    _renderTexture.setRepeated(repeated);
}

bool uranus::RenderTexture::isRepeated() const {
    return _renderTexture.isRepeated();
}

bool uranus::RenderTexture::generateMipmap() {
    return _renderTexture.generateMipmap();
}

bool uranus::RenderTexture::setActive(bool active) {
   return _renderTexture.setActive(active);
}

void uranus::RenderTexture::display() {
    _renderTexture.display();
}

uranus::Vector2u uranus::RenderTexture::getSize() const {
    return Vector2u(_renderTexture.getSize());
}

const std::shared_ptr<uranus::Texture> &uranus::RenderTexture::getTexture() const {
    return _texture;
}