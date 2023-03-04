//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_MOUSE_HPP
#define URANUS_MOUSE_HPP

#include "Vector2.hpp"
#include "Window.hpp"

namespace uranus {
    /**
     * @brief Mouse class
     */
    class Mouse {
    public:
        enum Button {
            Left,       ///< The left mouse button
            Right,      ///< The right mouse button
            Middle,     ///< The middle (wheel) mouse button
            XButton1,   ///< The first extra mouse button
            XButton2,   ///< The second extra mouse button
            ButtonCount ///< Keep last -- the total number of mouse buttons
        };

        enum Wheel {
            VerticalWheel, ///< The vertical mouse wheel.
            HorizontalWheel ///< The horizontal mouse wheel.
        };

        /**
         * @brief Check if a button is pressed
         * @param button Button to check
         * @return True if the button is pressed, false otherwise
         */
        static bool isButtonPressed(Button button);

        /**
         * @brief Get the current position of the mouse
         * @return Position of the mouse
         */
        static Vector2i getPosition();

        /**
         * @brief Get the current position of the mouse relative to a window
         * @param relativeTo Window to get the position relative to
         * @return Position of the mouse
         */
        static Vector2i getPosition(const Window &relativeTo);

        /**
         * @brief Set the current position of the mouse
         * @param position Position to set
         */
        static void setPosition(const Vector2i &position);

        /**
         * @brief Set the current position of the mouse relative to a window
         * @param position Position to set
         * @param relativeTo Window to set the position relative to
         */
        static void setPosition(const Vector2i &position, const Window &relativeTo);

    private:
    };
}


#endif //URANUS_MOUSE_HPP
