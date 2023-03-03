//
// Created by nicol on 23/01/2023.
//

#include "uranus/ecs/Components.hpp"

void deletePosition(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Position>(e);
}

void deleteVelocity(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Velocity>(e);
}

void deleteDrawable(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Drawable>(e);
}

void deleteInputKeyboard(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::InputKeyboard>(e);
}

void deleteInputMouse(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::InputMouse>(e);
}

void deleteCollisionable(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Collisionable>(e);
}

void deleteSpriteComponent(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Sprite>(e);
}

void deleteLoopComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Loop>(e);
}

void deleteAnimationComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Animation>(e);
}

void deleteNameComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<uranus::ecs::component::Name>(e);
}
