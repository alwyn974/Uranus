//
// Created by nicol on 23/01/2023.
//

#include "Systems.hpp"

void position_system(registry &r) {
    auto &positions = r.get_components<component::position>();
    auto &velocities = r.get_components<component::velocity>();
    for (size_t i = 0; i < positions.size() && i < velocities.size() ; ++i) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (pos && vel) {
            pos->x += vel->x;
            pos->y += vel->y;
        }
    }
}

void control_system(registry &r) {
    auto &velocities = r.get_components<component::velocity>();
    auto &controllables = r.get_components<component::controllable>();
    for ( size_t i = 0; i < velocities.size() && i < controllables.size(); ++i) {
        auto &vel = velocities[i];
        auto &controllable = controllables[i];
        if (vel && controllable) {
            if (sf::Keyboard::isKeyPressed (sf::Keyboard::Key::Left)) {
                vel->x = - 1 ;
            } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Right ) ) {
                vel->x = 1;
            } else {
                vel->x = 0;
            }
            if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Up ) ) {
                vel->y = - 1 ;
            } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Down ) ) {
                vel->y = 1;
            } else {
                vel->y = 0;
            }
        }
    }
}

void draw_system(registry &r) {
    auto &positions = r.get_components<component::position>();
    auto &drawables = r.get_components<component::drawable>();
    sf::RenderWindow *window = Window::getWindow();
    for (size_t i = 0; i < positions.size() && i < drawables.size(); ++i) {
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (pos && drawable) {
            drawable->shape->setPosition(pos->x, pos->y);
            drawable->shape->setFillColor(drawable->color);
            window->draw(*drawable->shape);
        }
    }
}