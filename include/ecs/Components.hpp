//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include "engine/Sprite.hpp"
#include "engine/Clock.hpp"
#include "engine/Event.hpp"
#include "engine/Manager.hpp"

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

#endif // URANUS_COMPONENTS_HPP
