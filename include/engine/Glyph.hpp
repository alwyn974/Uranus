//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_GLYPH_HPP
#define URANUS_GLYPH_HPP

#include "Rect.hpp"

namespace uranus {
    /**
     * @brief Glyph class
     */
    class Glyph {
    public:
        /**
         * @brief Default constructor
         */
        Glyph() : advance(0) {};

        /**
         * @brief Default copy constructor
         * @param glyph Glyph to copy
         */
        Glyph(const Glyph &glyph) = default;

        /**
         * @brief Default destructor
         */
        ~Glyph() = default;

        float advance /**< Advance of the glyph */;
        FloatRect bounds /**< Bounds of the glyph */;
        IntRect textureRect /**< Texture rect of the glyph */;
    };
}


#endif //URANUS_GLYPH_HPP
