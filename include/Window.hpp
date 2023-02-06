//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_WINDOW_HPP
#define URANUS_WINDOW_HPP

#include <SFML/Graphics.hpp>

//Singleton window class
class Window {
public:
    ~Window() = default;
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    static sf::RenderWindow *getWindow();
private:
    Window() = default;

    static sf::RenderWindow *_window;
};



#endif //URANUS_WINDOW_HPP
