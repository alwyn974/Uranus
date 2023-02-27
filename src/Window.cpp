//
// Created by nicol on 23/01/2023.
//

#include "Window.hpp"

engine::RenderWindow *Window::_window = nullptr;

engine::RenderWindow *Window::getWindow()
{
    if (!_window) { _window = new engine::RenderWindow(sf::VideoMode(800, 600), "Uranus"); }
    return _window;
}
