//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include "Sprite.hpp"
#include "Registry.hpp"

namespace component {

    struct position {
        float x;
        float y;
    };

    struct velocity {
        float x;
        float y;
    };

    struct drawable {
        sf::Shape *shape = nullptr;
        sf::Color color = sf::Color::White;
    };

    struct sprite {
       Sprite *sprite;
    };

    struct controllable {
    };

    struct collisionable {
        float x;
        float y;
        float width;
        float height;
        std::function<void(registry &r, const size_t, const size_t)> callback;
    };

    struct inputKeyboard {
        std::function<void(registry &r, const size_t, const sf::Event)> callback;
    };

    struct inputMouse {
        std::function<void(registry &r, const size_t, const sf::Event)> callback;
    };

    struct loop {
        std::function<void(registry &r, const size_t)> update;
    };
}

void delete_position(registry &r, size_t e);
void delete_velocity(registry &r, size_t e);
void delete_drawable(registry &r, size_t e);
void delete_controllable(registry &r, size_t e);
void delete_inputKeyboard(registry &r, size_t e);
void delete_inputMouse(registry &r, size_t e);
void delete_sprite_component(registry &r, size_t e);
void delete_collisionable(registry &r, size_t e);
void delete_loop_component(registry &r, size_t e);

#endif //URANUS_COMPONENTS_HPP
