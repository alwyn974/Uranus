//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_SYSTEMS_HPP
#define URANUS_SYSTEMS_HPP

#include "Manager.hpp"
#include "Event.hpp"
#include "ecs/View.hpp"
#include "ecs/Components.hpp"

namespace engine::system {

        void position();

        void draw();

        void input(engine::Event event);

        void collision();

        void loop();

        bool isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2);

        void gameLoop();

        void gameInit();
}

#endif // URANUS_SYSTEMS_HPP
