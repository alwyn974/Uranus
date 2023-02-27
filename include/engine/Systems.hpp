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

        void position(ecs::Registry &r);

        void draw(ecs::Registry &r);

        void input(ecs::Registry &r, engine::Event event);

        void collision(ecs::Registry &r);

        void loop(ecs::Registry &r);

        bool isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2);

        void gameLoop(ecs::Registry &r);

        void gameInit(ecs::Registry &r);
}

#endif // URANUS_SYSTEMS_HPP
