/*
** EPITECH PROJECT, 2023
** Event.hpp
** File description:
** Event.hpp
*/

#ifndef URANUS_EVENT_HPP
#define URANUS_EVENT_HPP

#include "Dependencies.hpp"

namespace uranus {
    /**
     * @brief Event class
     */
    class Event {
    public:
        /**
         * @brief Size event
         */
        struct SizeEvent {
            unsigned int width; /**< Width of the window */
            unsigned int height; /**< Height of the window */
        };

        /**
         * @brief Key event
         */
        struct KeyEvent {
            sf::Keyboard::Key code; /**< Code of the key */
            bool alt; /**< True if the alt key is pressed, false otherwise */
            bool control; /**< True if the control key is pressed, false otherwise */
            bool shift; /**< True if the shift key is pressed, false otherwise */
            bool system; /**< True if the system key is pressed, false otherwise */
        };

        /**
         * @brief Text event
         */
        struct TextEvent {
            sf::Uint32 unicode; /**< Unicode of the text */
        };

        /**
         * @brief Mouse move event
         */
        struct MouseMoveEvent {
            int x; /**< X position of the mouse */
            int y; /**< Y position of the mouse */
        };

        /**
         * @brief Mouse button event
         */
        struct MouseButtonEvent {
            sf::Mouse::Button button; /**< Code of the button */
            int x; /**< X position of the mouse */
            int y; /**< Y position of the mouse */
        };

        /**
         * @brief Mouse wheel event
         */
        struct MouseWheelEvent {
            int delta; /**< Number of ticks the wheel has moved */
            int x; /**< X position of the mouse */
            int y; /**< Y position of the mouse */
        };

        /**
         * @brief Mouse wheel scroll event
         */
        struct MouseWheelScrollEvent {
            sf::Mouse::Wheel wheel; /**< Code of the wheel */
            float delta; /**< Number of ticks the wheel has moved */
            int x; /**< X position of the mouse */
            int y; /**< Y position of the mouse */
        };

        /**
         * @brief Joystick connection event
         */
        struct JoystickConnectEvent {
            unsigned int joystickId; /**< Id of the joystick */
        };

        /**
         * @brief Joystick move event
         */
        struct JoystickMoveEvent {
            unsigned int joystickId; /**< Id of the joystick */
            sf::Joystick::Axis axis; /**< Axis of the movement */
            float position; /**< New position on the axis */
        };

        /**
         * @brief Joystick button event
         */
        struct JoystickButtonEvent {
            unsigned int joystickId; /**< Id of the joystick */
            unsigned int button; /**< Index of the button */
        };

        /**
         * @brief Touch event
         */
        struct TouchEvent {
            unsigned int finger; /**< Index of the finger */
            int x; /**< X position of the touch */
            int y; /**< Y position of the touch */
        };

        struct SensorEvent {
            sf::Sensor::Type type; /**< Type of the sensor */
            float x; /**< X value of the sensor */
            float y; /**< Y value of the sensor */
            float z; /**< Z value of the sensor */
        };

        /**
         * @brief Enum for the event type
         */
        enum EventType {
            CLOSED,
            RESIZED,
            LOST_FOCUS,
            GAINED_FOCUS,
            TEXT_ENTERED,
            KEY_PRESSED,
            KEY_RELEASED,
            MOUSE_WHEEL_MOVED,
            MOUSE_WHEEL_SCROLLED,
            MOUSE_BUTTON_PRESSED,
            MOUSE_BUTTON_RELEASED,
            MOUSE_MOVED,
            MOUSE_ENTERED,
            MOUSE_LEFT,
            JOYSTICK_BUTTON_PRESSED,
            JOYSTICK_BUTTON_RELEASED,
            JOYSTICK_MOVED,
            JOYSTICK_CONNECTED,
            JOYSTICK_DISCONNECTED,
            TOUCH_BEGAN,
            TOUCH_MOVED,
            TOUCH_ENDED,
            SENSOR_CHANGED,
            COUNT
        };

        EventType type; /**< Type of the event */

        /**
         * @brief Union for the event
         */
        union {
            SizeEvent size;
            KeyEvent key;
            TextEvent text;
            MouseMoveEvent mouseMove;
            MouseButtonEvent mouseButton;
            MouseWheelEvent mouseWheel;
            MouseWheelScrollEvent mouseWheelScroll;
            JoystickConnectEvent joystickConnect;
            JoystickMoveEvent joystickMove;
            JoystickButtonEvent joystickButton;
            TouchEvent touch;
            SensorEvent sensor;
        };
        };
    };
}

#endif //URANUS_EVENT_HPP
