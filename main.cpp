/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include "uranus/Uranus.hpp"
#include <SFML/Graphics.hpp>

int main(int ac, char **av)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::CircleShape shape(100);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event = {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
