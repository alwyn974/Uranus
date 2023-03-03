//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_FONT_HPP
#define URANUS_FONT_HPP

#include <SFML/Graphics.hpp>
#include "Glyph.hpp"

namespace uranus {
    /**
     * @brief Font class
     */
    class Font {
    public:
        /**
         * @brief Font info
         */
        struct Info {
            std::string family /*< Family of the font */;
        };

        /**
         * @brief Default constructor
         */
        Font() = default;

        /**
         * @brief Default copy constructor
         * @param font Font to copy
         */
        Font(const Font &font) = default;

        /**
         * @brief Default destructor
         */
        ~Font() = default;

        /**
         * @brief Load a font from a file
         * @param path Path of the font
         */
        void loadFromFile(const std::string &path);

        /**
         * @brief Load a font from a memory
         * @param data Data of the font
         * @param size Size of the data
         */
        void loadFromMemory(const void *data, std::size_t size);

        /**
         * @brief Load a font from a stream
         * @param stream Stream of the font
         */
        void loadFromStream(sf::InputStream &stream);


        /**
         * @brief Get the Info of the font
         * @return Info of the font
         */
        const Info &getInfo() const;

        /**
         * @brief Get a glyph of the font
         * @param codePoint Unicode code point of the character to get
         * @param characterSize Size of the character
         * @param bold True to get the bold version of the glyph, false otherwise
         * @return Glyph of a character of the font
         */
        const Glyph &getGlyph(unsigned int codePoint, unsigned int characterSize, bool bold) const;

        /**
         * @brief Get the kerning offset of two glyphs
         * @param first First character
         * @param second Second character
         * @param characterSize Size of the characters
         * @return Kerning of two characters
         */
        int getKerning(unsigned int first, unsigned int second, unsigned int characterSize) const;

        /**
         * @brief Get the line spacing of the font
         * @param characterSize Size of the characters
         * @return Line spacing of the font
         */
        int getLineSpacing(unsigned int characterSize) const;

        /**
         * @brief Get the underline position of the font
         * @param characterSize Size of the characters
         * @return Underline position of the font
         */
        float getUnderlinePosition(unsigned int characterSize) const;

        /**
         * @brief Get the underline thickness of the font
         * @param characterSize Size of the characters
         * @return Underline thickness of the font
         */
        float getUnderlineThickness(unsigned int characterSize) const;

        /**
         * @brief Get the texture of the font
         * @return Texture of the font
         */
        const std::shared_ptr<sf::Texture> &getTexture() const;

        /**
         * @brief Overload of assignment operator
         * @param font Font to copy
         * @return Reference to the font
         */
        Font &operator=(const Font &font);
    private:
        sf::Font _font /*< SFML font */;
        Info _info /*< Info of the font */;
        std::shared_ptr<sf::Texture> _texture /*< Texture of the font */;
    };
}


#endif //URANUS_FONT_HPP
