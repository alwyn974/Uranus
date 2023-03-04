/*
** EPITECH PROJECT, 2023
** Window.hpp
** File description:
** Window.hpp
*/

#ifndef URANUS_RENDERWINDOW_HPP
#define URANUS_RENDERWINDOW_HPP

#include "uranus/engine/Dependencies.hpp"

namespace engine {

    class RenderWindow : public sf::RenderWindow {
    public:
        RenderWindow(sf::VideoMode mode, const std::string &title);
    };

} // namespace engine

#endif // URANUS_RENDERWINDOW_HPP
