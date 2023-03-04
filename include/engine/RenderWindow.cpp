/*
** EPITECH PROJECT, 2023
** RenderWindow.cpp
** File description:
** RenderWindow.cpp
*/

#include "RenderWindow.hpp"

uranus::RenderWindow::RenderWindow(uranus::VideoMode mode, const std::string &title, unsigned int style, const uranus::ContextSettings &settings) :
_window(VideoMode(mode.getWidth(), mode.getHeight(), mode.getBitsPerPixel()).getVideoMode(), title, style, settings) {}

uranus::RenderWindow::RenderWindow(sf::WindowHandle handle, const uranus::ContextSettings &settings) :
_window(handle, settings) {}

uranus::Vector2u uranus::RenderWindow::getSize() const {
    return Vector2u(_window.getSize().x, _window.getSize().y);
}

bool uranus::RenderWindow::setActive(bool active) {
    return _window.setActive(active);
}

void uranus::RenderWindow::onCreate() {
    setActive(true);
}

void uranus::RenderWindow::onResize() {
    //TODO: Implement
}


