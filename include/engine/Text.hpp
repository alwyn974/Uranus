//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_TEXT_HPP
#define URANUS_TEXT_HPP

#include "Font.hpp"
#include "Drawable.hpp"
#include "Transformable.hpp"

namespace uranus {
    /**
     * @brief Text class.
     */
    class Text : public Drawable, public Transformable {
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
        Text() = default;

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
        ~Text() = default;

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
        FloatRect getLocalBounds() const;

        /**
         * @brief Get the global bounds of the text.
         * @return Global bounds of the text.
         */
        FloatRect getGlobalBounds() const;

    private:
        /**
         * @brief Draw the text.
         * @param target Target to draw on.
         * @param states States to draw with.
         */
        void draw(RenderTarget &target, RenderStates states) const;

        /**
         * @brief Ensure the geometry update of the text.
         */
        void ensureGeometryUpdate() const;

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
    };
}


#endif //URANUS_TEXT_HPP
