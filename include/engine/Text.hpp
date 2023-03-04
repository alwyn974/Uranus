//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_TEXT_HPP
#define URANUS_TEXT_HPP

#include "Font.hpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include "Transform.hpp"

namespace uranus {
    /**
     * @brief Text class.
     */
    class Text {
    public:
        enum Style {
            Regular = 0,
            Bold = 1 << 0,
            Italic = 1 << 1,
            Underlined = 1 << 2,
            Strikethrough = 1 << 3
        };

        /**
         * @brief Default constructor.
         */
        Text();

        /**
         * @brief Construct a text from a string, a font and a character size.
         * @param string String to set.
         * @param font Font to set.
         * @param characterSize Character size to set.
         */
        Text(const std::string &string, const Font &font, unsigned int characterSize = 30);

        /**
         * @brief Default destructor.
         */
        ~Text();

        /**
         * @brief Set the string of the text.
         * @param string String to set.
         */
        void setString(const std::string &string);

        /**
         * @brief Set the font of the text.
         * @param font Font to set.
         */
        void setFont(const Font &font);

        /**
         * @brief Set the character size of the text.
         * @param size Size to set.
         */
        void setCharacterSize(unsigned int size);

        /**
         * @brief Set the line spacing factor of the text.
         * @param factor Factor to set.
         */
        void setLineSpacing(float factor);

        /**
         * @brief Set the letter spacing factor of the text.
         * @param factor Factor to set.
         */
        void setLetterSpacing(float factor);

        /**
         * @brief Set the style of the text.
         * @param style Style to set.
         */
        void setStyle(unsigned int style);

        /**
         * @brief Set the color of the text.
         * @param color Color to set.
         */
        void setColor(const Color &color);

        /**
         * @brief Set the fill color of the text.
         * @param color Color to set.
         */
        void setFillColor(const Color &color);

        /**
         * @brief Set the outline color of the text.
         * @param color Color to set.
         */
        void setOutlineColor(const Color &color);

        /**
         * @brief Set the outline thickness of the text.
         * @param thickness Thickness to set.
         */
        void setOutlineThickness(float thickness);

        /**
         * @brief Get the string of the text.
         * @return String of the text.
         */
        const std::string &getString() const;

        /**
         * @brief Get the font of the text.
         * @return Font of the text.
         */
        const Font &getFont() const;

        /**
         * @brief Get the character size of the text.
         * @return Character size of the text.
         */
        unsigned int getCharacterSize() const;

        /**
         * @brief Get the line spacing factor of the text.
         * @return Line spacing factor of the text.
         */
        float getLineSpacing() const;

        /**
         * @brief Get the letter spacing factor of the text.
         * @return Letter spacing factor of the text.
         */
        float getLetterSpacing() const;

        /**
         * @brief Get the style of the text.
         * @return Style of the text.
         */
        unsigned int getStyle() const;

        /**
         * @brief Get the color of the text.
         * @return Color of the text.
         */
        const Color &getColor() const;

        /**
         * @brief Get the fill color of the text.
         * @return Fill color of the text.
         */
        const Color &getFillColor() const;

        /**
         * @brief Get the outline color of the text.
         * @return Outline color of the text.
         */
        const Color &getOutlineColor() const;

        /**
         * @brief Get the outline thickness of the text.
         * @return Outline thickness of the text.
         */
        float getOutlineThickness() const;

        /**
         * @brief Get the position of a character in the text.
         * @param index Index of the character.
         * @return Position of the character.
         */
        Vector2f findCharacterPos(std::size_t index) const;

        /**
         * @brief Get the local bounds of the text.
         * @return Local bounds of the text.
         */
        const FloatRect &getLocalBounds() const;

        /**
         * @brief Get the global bounds of the text.
         * @return Global bounds of the text.
         */
        const FloatRect &getGlobalBounds() const;

        /**
         * @brief Set the position of the text.
         * @param position Position to set.
         */
        void setPosition(const Vector2f &position);

        /**
         * @brief Set the position of the text.
         * @param x X position to set.
         * @param y Y position to set.
         */
        void setPosition(float x, float y);

        /**
         * @brief Set the rotation of the text.
         * @param angle Angle to set.
         */
        void setRotation(float angle);

        /**
         * @brief Set the scale of the text.
         * @param scale Scale to set.
         */
        void setScale(const Vector2f &scale);

        /**
         * @brief Set the scale of the text.
         * @param factorX X factor to set.
         * @param factorY Y factor to set.
         */
        void setScale(float factorX, float factorY);

        /**
         * @brief Set the origin of the text.
         * @param origin Origin to set.
         */
        void setOrigin(const Vector2f &origin);

        /**
         * @brief Set the origin of the text.
         * @param x X origin to set.
         * @param y Y origin to set.
         */
        void setOrigin(float x, float y);

        /**
         * @brief Get the position of the text.
         * @return Position of the text.
         */
        const Vector2f &getPosition() const;

        /**
         * @brief Get the rotation of the text.
         * @return Rotation of the text.
         */
        float getRotation() const;

        /**
         * @brief Get the scale of the text.
         * @return Scale of the text.
         */
        const Vector2f &getScale() const;

        /**
         * @brief Get the origin of the text.
         * @return Origin of the text.
         */
        const Vector2f &getOrigin() const;

        /**
         * @brief Move the text.
         * @param offset Offset to move.
         */
        void move(const Vector2f &offset);

        /**
         * @brief Move the text.
         * @param offsetX X offset to move.
         * @param offsetY Y offset to move.
         */
        void move(float offsetX, float offsetY);

        /**
         * @brief Rotate the text.
         * @param angle Angle to rotate.
         */
        void rotate(float angle);

        /**
         * @brief Scale the text.
         * @param factor Scale factor.
         */
        void scale(const Vector2f &factor);

        /**
         * @brief Scale the text.
         * @param factorX X scale factor.
         * @param factorY Y scale factor.
         */
        void scale(float factorX, float factorY);

        /**
         * @brief Get the transform of the text.
         * @return Transform of the text.
         */
        const Transform &getTransform() const;

        /**
         * @brief Get the inverse transform of the text.
         * @return Inverse transform of the text.
         */
        const Transform &getInverseTransform() const;

    private:
        sf::Text _text; /**< SFML text. */
        std::string _string; /**< String of the text. */
        Font _font; /**< Font of the text. */
        unsigned int _characterSize; /**< Character size of the text. */
        float _lineSpacing; /**< Line spacing factor of the text. */
        float _letterSpacing; /**< Letter spacing factor of the text. */
        unsigned int _style; /**< Style of the text. */
        Color _color; /**< Color of the text. */
        Color _fillColor; /**< Fill color of the text. */
        Color _outlineColor; /**< Outline color of the text. */
        float _outlineThickness; /**< Outline thickness of the text. */
        Vector2f _position; /**< Position of the text. */
        float _rotation; /**< Rotation of the text. */
        Vector2f _scale; /**< Scale of the text. */
        Vector2f _origin; /**< Origin of the text. */
        Transform _transform; /**< Transform of the text. */
        Transform _inverseTransform; /**< Inverse transform of the text. */
    };
}


#endif //URANUS_TEXT_HPP
