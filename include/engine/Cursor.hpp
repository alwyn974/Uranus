//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CURSOR_HPP
#define URANUS_CURSOR_HPP

#include <SFML/Graphics.hpp>
#include "Vector2.hpp"

namespace uranus {
    /*
     * @brief Type enum for all cursor types
     */
    enum Type {
        ARROW,
        ARROW_WAIT,
        WAIT,
        TEXT,
        HAND,
        SIZE_HORIZONTAL,
        SIZE_VERTICAL,
        SIZE_TOP_LEFT_BOTTOM_RIGHT,
        SIZE_BOTTOM_LEFT_TOP_RIGHT,
        SIZE_ALL,
        CROSS,
        HELP,
        NOT_ALLOWED
    };

    /**
     * @brief The Cursor class
     */
    class Cursor {
    public:
        /**
         * @brief Default constructor
         */
        Cursor() = default;

        /**
         * @brief Default destructor
         */
        ~Cursor() = default;

        /**
         * @brief Load cursor from pixels
         * @param pixels Pixels of the cursor
         * @param size Size of the cursor
         * @param hotspot Hotspot of the cursor
         */
        void loadFromPixels(const unsigned char *pixels, const Vector2u &size, const Vector2u &hotspot);

        /**
         * @brief Load cursor from system
         * @param type Type of the cursor
         */
        void loadFromSystem(Type type);
    private:
        sf::Cursor _cursor /*< SFML cursor */;
    };
}


#endif //URANUS_CURSOR_HPP
