//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_WINDOW_HPP
#define URANUS_WINDOW_HPP

#include "Vector2.hpp"
#include "VideoMode.hpp"
#include "ContextSettings.hpp"
#include "Event.hpp"
#include "Cursor.hpp"

namespace uranus {
    enum Style {
        NONE = 0, ///< No border / title bar (this flag and all others are mutually exclusive)
        TITLEBAR = 1 << 0, ///< Title bar + fixed border
        RESIZE = 1 << 1, ///< Titlebar + resizable border + maximize button
        CLOSE = 1 << 2, ///< Titlebar + close button
        FULLSCREEN = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)
        DEFAULT = TITLEBAR | RESIZE | CLOSE ///< Default window style
    };

    /**
     * @brief Window class
     */
    class Window {
    public:
        /**
         * @brief Default constructor
         */
        Window() = default;

        Window(VideoMode mode, const std::string &title, unsigned int style = sf::Style::Default, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Default destructor
         */
        virtual ~Window() = default;

        /**
         * @brief Create the window
         * @param mode Video mode
         * @param title Title of the window
         * @param style Style of the window
         * @param settings Context settings
         */
        void create(VideoMode mode, const std::string &title, unsigned int style = Style::DEFAULT, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Create the window from an existing control
         * @param handle Handle of the control
         * @param settings Context settings
         */
        void create(sf::WindowHandle handle, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Close the window
         */
        void close();

        /**
         * @brief Check if the window is open
         * @return True if the window is open, false otherwise
         */
        bool isOpen() const;

        /**
         * @brief Get the context settings of the window
         * @return The context settings
         */
        const ContextSettings &getSettings() const;

        /**
         * @brief Pop the event on top of the event queue, if any, and return it
         * @param event Event to fill
         * @return True if an event was returned, false otherwise
         */
        bool pollEvent(Event &event);

        /**
         * @brief Wait for an event and return it
         * @param event Event to fill
         */
        void waitEvent(Event &event);

        /**
         * @brief Get the position of the window
         * @return The position of the window
         */
        Vector2i getPosition() const;

        /**
         * @brief Set the position of the window
         * @param position New position of the window
         */
        void setPosition(const Vector2i &position);

        /**
         * @brief Get the size of the rendering region of the window
         * @return The size in pixels
         */
        Vector2u getSize() const;

        /**
         * @brief Set the size of the rendering region of the window
         * @param size New size, in pixels
         */
        void setSize(const Vector2u &size);

        /**
         * @brief Change the title of the window
         * @param title New title
         */
        void setTitle(const std::string &title);

        /**
         * @brief Change the window's icon
         * @param width Icon's width, in pixels
         * @param height Icon's height, in pixels
         * @param pixels Pointer to the pixels in memory, format must be RGBA 32 bits
         */
        void setIcon(unsigned int width, unsigned int height, const unsigned char *pixels);

        /**
         * @brief Show or hide the window
         * @param visible True to show the window, false to hide it
         */
        void setVisible(bool visible);

        /**
         * @brief Enable or disable vertical synchronization
         * @param enabled True to enable v-sync, false to deactivate
         */
        void setVerticalSyncEnabled(bool enabled);

        /**
         * @brief Hide or show the mouse cursor
         * @param visible True to show the mouse cursor, false to hide it
         */
        void setMouseCursorVisible(bool visible);

        /**
         * @brief Grab or release the mouse cursor
         * @param grabbed True to enable, false to disable
         */
        void setMouseCursorGrabbed(bool grabbed);

        /**
         * @brief Set the displayed cursor to a native system cursor
         * @param cursor Native system cursor type to display
         */
        void setMouseCursor(const Cursor &cursor);

        /**
         * @brief Enable or disable automatic key-repeat
         * @param enabled True to enable, false to disable
         */
        void setKeyRepeatEnabled(bool enabled);

        /**
         * @brief Limit the framerate to a maximum fixed frequency
         * @param limit Framerate limit, in frames per seconds (use 0 to disable limit)
         */
        void setFramerateLimit(unsigned int limit);

        /**
         * @brief Change the joystick threshold, ie. the value below which no move event will be generated
         * @param threshold New threshold, in the range [0, 100]
         */
        void setJoystickThreshold(float threshold);

        /**
         * @brief Activate or deactivate the window as the current target for OpenGL rendering
         * @param active True to activate, false to deactivate
         * @return True if operation was successful, false otherwise
         */
        bool setActive(bool active = true);

        /**
         * @brief Request the current window to be made the active foreground window
         */
        void requestFocus();

        /**
         * @brief Check whether the window has the input focus
         * @return True if window has focus, false otherwise
         */
        bool hasFocus() const;

        /**
         * @brief Display on screen what has been rendered to the window so far
         */
        void display();

        /**
         * @brief Get the OS-specific handle of the window
         * @return The handle
         */
        sf::WindowHandle getSystemHandle() const;

        /**
         * @brief Get the SFML window
         * @return The SFML window
         */
        const sf::Window &getWindow() const;
    protected:
        /**
         * @brief Called when the window is created
         */
        virtual void onCreate();

        /**
         * @brief Called when the window is resized
         */
        virtual void onResize();

    private:
        /**
//         * @brief Register a callback to be called when the context is destroyed
//         * @param callback Callback to register
//         * @param args Arguments to pass to the callback
//         */
//        static void registerContextDestroyCallback(sf::ContextDestroyCallback callback, void* args);

        sf::Window _window; /**< SFML window */
        ContextSettings _settings; /**< Context settings */
    };
}


#endif //URANUS_WINDOW_HPP
