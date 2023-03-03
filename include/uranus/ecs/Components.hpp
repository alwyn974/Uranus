//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include "uranus/engine/Sprite.hpp"
#include "uranus/engine/Clock.hpp"
#include "uranus/engine/Event.hpp"
#include "uranus/engine/Manager.hpp"

namespace component {

    struct name {
        std::string uniqueName;
    };

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
        sf::Color color = sf::Color::White;
        ~drawable() {
            if (shape != nullptr)
                delete shape;
        }
    };

    struct sprite {
        std::shared_ptr<engine::Sprite> sprite;
    };

    struct collisionable {
        float x;
        float y;
        float width;
        float height;
        std::array<bool, LAYER_SIZE> layer;
        std::array<bool, MASK_SIZE> mask;
        std::function<void(const size_t, const size_t)> callback;
    };

    struct inputKeyboard {
        std::function<void(const size_t, const engine::Event)> callback;
    };

    struct inputMouse {
        std::function<void(const size_t, const engine::Event)> callback;
    };

    struct loop {
        std::function<void(const size_t)> update;
    };

    struct frameData {
        float frameTime;
        int frame;
    };

    struct animationData {
        std::string name;
        bool loop;
        float length;
        engine::Clock clock;
        bool isPlaying;
        std::vector<component::frameData> frames;
    };

    struct animation {
        int hFrame;
        int vFrame;
        std::function<void(const size_t entity, const std::string &animationName)> callback;
        std::vector<component::animationData> animations;
    };


} // namespace component

void deletePosition(size_t e);
void deleteVelocity(size_t e);
void deleteDrawable(size_t e);
void deleteInputKeyboard(size_t e);
void deleteInputMouse(size_t e);
void deleteSpriteComponent(size_t e);
void deleteCollisionable(size_t e);
void deleteLoopComponent(size_t e);
void deleteAnimationComponent(size_t e);
void deleteNameComponent(size_t e);

#endif // URANUS_COMPONENTS_HPP
