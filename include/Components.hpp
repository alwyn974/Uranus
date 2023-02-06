//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include <SFML/Graphics.hpp>
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
        sf::Shape *shape;
        sf::Color color;
    };

    struct controllable {
    };
}

void delete_position(registry &r, size_t e);
void delete_velocity(registry &r, size_t e);
void delete_drawable(registry &r, size_t e);
void delete_controllable(registry &r, size_t e);

#endif //URANUS_COMPONENTS_HPP
