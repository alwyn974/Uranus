//
// Created by nicol on 23/01/2023.
//

#include "Window.hpp"

sf::RenderWindow* Window::_window = nullptr;

sf::RenderWindow *Window::getWindow() {
    if (!_window) {
        _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Uranus");
    }
    return _window;
}