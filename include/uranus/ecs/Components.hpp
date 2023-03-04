/*
** EPITECH PROJECT, 2023
** Components.hpp
** File description:
** Components.hpp
*/

#ifndef URANUS_COMPONENTS_HPP
#define URANUS_COMPONENTS_HPP

#include "uranus/Core.hpp"
#include "uranus/engine/Clock.hpp"
#include "uranus/engine/Event.hpp"
#include "uranus/engine/Manager.hpp"
#include "uranus/engine/Sprite.hpp"
#include <array>

/**
 * @brief Namespace containing all the base components
 */
namespace uranus::ecs::component {

    struct Name {
        std::string uniqueName;
    };

    struct Position {
        float x;
        float y;
    };

    struct Velocity {
        float x;
        float y;
    };

    struct Drawable {
        sf::Shape *shape = nullptr;
        sf::Color color = sf::Color::White;

        ~Drawable()
        {
            if (shape != nullptr) delete shape;
        }
    };

    struct Sprite {
        std::shared_ptr<engine::Sprite> sprite;
    };

    struct Collisionable {
        float x;
        float y;
        float width;
        float height;
        std::array<bool, LAYER_SIZE> layer;
        std::array<bool, MASK_SIZE> mask;
        std::function<void(const size_t, const size_t)> callback;
    };

    struct InputKeyboard {
        std::function<void(const size_t, const engine::Event)> callback;
    };

    struct InputMouse {
        std::function<void(const size_t, const engine::Event)> callback;
    };

    struct Loop {
        std::function<void(const size_t)> update;
    };

    struct FrameData {
        float frameTime;
        int frame;
    };

    struct AnimationData {
        std::string name;
        bool loop;
        float length;
        engine::Clock clock;
        bool isPlaying;
        std::vector<component::FrameData> frames;
    };

    struct Animation {
        int hFrame;
        int vFrame;
        std::function<void(const size_t entity, const std::string &animationName)> callback;
        std::vector<component::AnimationData> animations;
    };

} // namespace uranus::ecs::component

void deletePosition(size_t entity);
void deleteVelocity(size_t entity);
void deleteDrawable(size_t entity);
void deleteInputKeyboard(size_t entity);
void deleteInputMouse(size_t entity);
void deleteSpriteComponent(size_t entity);
void deleteCollisionable(size_t entity);
void deleteLoopComponent(size_t entity);
void deleteAnimationComponent(size_t entity);
void deleteNameComponent(size_t entity);

#endif // URANUS_COMPONENTS_HPP
