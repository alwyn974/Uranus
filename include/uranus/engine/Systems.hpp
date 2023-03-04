//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_SYSTEMS_HPP
#define URANUS_SYSTEMS_HPP

#include "uranus/engine/components/Event.hpp"
#include "uranus/engine/manager/Manager.hpp"
#include "uranus/ecs/Components.hpp"
#include "uranus/ecs/View.hpp"

namespace engine::system {

    void position();

    void draw();

    void input(engine::Event event);

    void collision();

    void loop();

    void animation();

    // TODO: move tha non "system" functions -----------------------------------
    void addNewAnimation(size_t entity, const std::string &name, bool loop, float length);

    void insertAnimationFrame(size_t entity, const std::string &name, float frameTime, int frame);

    void playAnimation(size_t entity, const std::string &name);

    void stopAnimation(size_t entity);

    bool isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2);

    void setLayer(size_t entity, const std::array<bool, LAYER_SIZE> &layer);

    void setMask(size_t entity, const std::array<bool, MASK_SIZE> &mask);

    void gameLoop();

    void gameInit();
    //--------------------------------------------------------------------------
} // namespace engine::system

#endif // URANUS_SYSTEMS_HPP
