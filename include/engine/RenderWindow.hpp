/*
** EPITECH PROJECT, 2023
** Window.hpp
** File description:
** Window.hpp
*/

#ifndef URANUS_RENDERWINDOW_HPP
#define URANUS_RENDERWINDOW_HPP

#include "Dependencies.hpp"
#include "Window.hpp"

namespace uranus {
    class RenderWindow: public Window {
    public:
        /**
         * @brief Default constructor
         */
        RenderWindow() = default;

        /**
         * @brief Constructor from a video mode, a title and a style
         * @param mode Video mode
         * @param title Title of the window
         * @param style Style of the window
         * @param settings Context settings
         */
        RenderWindow(sf::VideoMode mode, const std::string &title, unsigned int style = Style::DEFAULT, const ContextSettings &settings = ContextSettings());7

        /**
         * @brief Constructor from a window handle
         * @param handle Window handle
         * @param settings Context settings
         */
        explicit RenderWindow(sf::WindowHandle handle, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Default destructor
         */
        virtual ~RenderWindow() = default;

        /**
         * @brief Get the size of the window
         * @return Size of the window
         */
        virtual Vector2u getSize() const;

        /**
         * @brief Activate or deactivate the window as the current target for OpenGL rendering
         * @param active True to activate, false to deactivate
         * @return True if operation was successful, false otherwise
         */
        bool setActive(bool active = true) const;

    protected:
        /**
         * @brief Called when the window is created
         */
        virtual void onCreate();

        /**
         * @brief Called when the window is resized
         */
        virtual void onResize();
    };

}

#endif //URANUS_RENDERWINDOW_HPP


