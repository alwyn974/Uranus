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
#include "RenderTarget.hpp"

namespace uranus {
    class RenderWindow: public Window, public RenderTarget {
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
        RenderWindow(VideoMode mode, const std::string &title, unsigned int style = Style::DEFAULT, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Constructor from a window handle
         * @param handle Window handle
         * @param settings Context settings
         */
        explicit RenderWindow(sf::WindowHandle handle, const ContextSettings &settings = ContextSettings());

        /**
         * @brief Default destructor
         */
        ~RenderWindow() override = default;

        /**
         * @brief Get the size of the window
         * @return Size of the window
         */
        Vector2u getSize() const override;

        /**
         * @brief Activate or deactivate the window as the current target for OpenGL rendering
         * @param active True to activate, false to deactivate
         * @return True if operation was successful, false otherwise
         */
        bool setActive(bool active = true) override;

    protected:
        /**
         * @brief Called when the window is created
         */
        void onCreate() override;

        /**
         * @brief Called when the window is resized
         */
        void onResize() override;

    private:
        sf::RenderWindow _window; /**< SFML RenderWindow */
    };

}

#endif //URANUS_RENDERWINDOW_HPP


