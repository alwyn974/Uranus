//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_RENDERWINDOW_HPP
#define URANUS_WINDOW_HPP

#include "engine/Engine.hpp"

// Singleton window class
//TODO create real abstraction class
class Window {
public:
    ~Window() = default;
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    static engine::RenderWindow *getWindow();

private:
    Window() = default;

    static engine::RenderWindow *_window;
};

#endif // URANUS_RENDERWINDOW_HPP
