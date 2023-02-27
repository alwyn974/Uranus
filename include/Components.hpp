//
// Created by nicol on 23/01/2023.
//

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include "engine/Engine.hpp"
#include "engine/Sprite.hpp"

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
        engine::Sprite *sprite;
    };

    struct controllable {};

    struct collisionable {
        float x;
        float y;
        float width;
        float height;
        std::function<void(ecs::Registry &r, const size_t, const size_t)> callback;
    };

    struct inputKeyboard {
        std::function<void(ecs::Registry &r, const size_t, const sf::Event)> callback;
    };

    struct inputMouse {
        std::function<void(ecs::Registry &r, const size_t, const sf::Event)> callback;
    };

    struct loop {
        std::function<void(ecs::Registry &r, const size_t)> update;
    };
} // namespace component

void deletePosition(ecs::Registry &r, size_t e);
void deleteVelocity(ecs::Registry &r, size_t e);
void deleteDrawable(ecs::Registry &r, size_t e);
void deleteControllable(ecs::Registry &r, size_t e);
void deleteInputKeyboard(ecs::Registry &r, size_t e);
void deleteInputMouse(ecs::Registry &r, size_t e);
void deleteSpriteComponent(ecs::Registry &r, size_t e);
void deleteCollisionable(ecs::Registry &r, size_t e);
void deleteLoopComponent(ecs::Registry &r, size_t e);

#endif // URANUS_COMPONENTS_HPP
