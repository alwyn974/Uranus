//
// Created by nicol on 02/03/2023.
//

#include "Font.hpp"

void uranus::Font::loadFromFile(const std::string &path) {
    _font.loadFromFile(path);
}

void uranus::Font::loadFromMemory(const void *data, std::size_t size) {
    _font.loadFromMemory(data, size);
}

void uranus::Font::loadFromStream(InputStream &stream) {
    _font.loadFromStream(stream.getInputStream());
}

const uranus::Font::Info &uranus::Font::getInfo() const {
    return _info;
}

//const uranus::Glyph &uranus::Font::getGlyph(unsigned int codePoint, unsigned int characterSize, bool bold) const {
//}

float uranus::Font::getKerning(unsigned int first, unsigned int second, unsigned int characterSize) const {
    return _font.getKerning(first, second, characterSize);
}

float uranus::Font::getLineSpacing(unsigned int characterSize) const {
    return _font.getLineSpacing(characterSize);
}

float uranus::Font::getUnderlinePosition(unsigned int characterSize) const {
    return _font.getUnderlinePosition(characterSize);
}

float uranus::Font::getUnderlineThickness(unsigned int characterSize) const {
    return _font.getUnderlineThickness(characterSize);
}

//const std::shared_ptr<uranus::Texture> &uranus::Font::getTexture(unsigned int characterSize) const {
//}

const sf::Font &uranus::Font::getFont() const {
    return _font;
}

