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

        void animation();

        //TODO: move tha non "system" functions -----------------------------------
        void addNewAnimation(size_t entity, const std::string &name, bool loop, float length);

        void insertAnimationFrame(size_t entity, const std::string &name, float frameTime, int frame);

        void playAnimation(size_t entity, const std::string &name);

        void stopAnimation(size_t entity);

        bool isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2);



        void gameLoop();

        void gameInit();
        //--------------------------------------------------------------------------
}

#endif // URANUS_SYSTEMS_HPP
