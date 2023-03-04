//
// Created by nicol on 04/03/2023.
//

#include "Text.hpp"

uranus::Text::Text(const std::string &string, const Font &font, unsigned int characterSize) {
    _text.setString(string);
    _text.setFont(font.getFont());
    _text.setCharacterSize(characterSize);
}

void uranus::Text::setString(const std::string &string) {
    _string = string;
    _text.setString(string);
}

void uranus::Text::setFont(const Font &font) {
    _font = font;
    _text.setFont(font.getFont());
}

void uranus::Text::setCharacterSize(unsigned int size) {
    _characterSize = size;
    _text.setCharacterSize(size);
}

void uranus::Text::setLineSpacing(float factor) {
    _lineSpacing = factor;
    _text.setLineSpacing(factor);
}

void uranus::Text::setLetterSpacing(float factor) {
    _letterSpacing = factor;
    _text.setLetterSpacing(factor);
}

void uranus::Text::setStyle(unsigned int style) {
    _style = style;
    _text.setStyle(style);
}

void uranus::Text::setColor(const Color &color) {
    _color = color;
    _text.setFillColor(color);
}

void uranus::Text::setFillColor(const Color &color) {
    _fillColor = color;
    _text.setFillColor(color);
}

void uranus::Text::setOutlineColor(const Color &color) {
    _outlineColor = color;
    _text.setOutlineColor(color);
}

void uranus::Text::setOutlineThickness(float thickness) {
    _outlineThickness = thickness;
    _text.setOutlineThickness(thickness);
}

const std::string &uranus::Text::getString() const {
    return _string;
}

const uranus::Font &uranus::Text::getFont() const {
    return _font;
}

unsigned int uranus::Text::getCharacterSize() const {
    return _characterSize;
}

float uranus::Text::getLineSpacing() const {
    return _lineSpacing;
}

float uranus::Text::getLetterSpacing() const {
    return _letterSpacing;
}

unsigned int uranus::Text::getStyle() const {
    return _style;
}

const uranus::Color &uranus::Text::getColor() const {
    return _color;
}

const uranus::Color &uranus::Text::getFillColor() const {
    return _fillColor;
}

const uranus::Color &uranus::Text::getOutlineColor() const {
    return _outlineColor;
}

float uranus::Text::getOutlineThickness() const {
    return _outlineThickness;
}

uranus::Vector2f uranus::Text::findCharacterPos(std::size_t index) const {
    return Vector2f(_text.findCharacterPos(index));
}

uranus::FloatRect uranus::Text::getLocalBounds() const {
    return FloatRect(_text.getLocalBounds());
}

uranus::FloatRect uranus::Text::getGlobalBounds() const {
    return FloatRect(_text.getGlobalBounds());
}

void uranus::Text::draw(RenderTarget &target, RenderStates states) const {
    target.draw(_text, states);
}
