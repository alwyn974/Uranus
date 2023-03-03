//
// Created by nicol on 23/01/2023.
//

#include "uranus/ecs/Components.hpp"

void deletePosition(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::position>(e);
}

void deleteVelocity(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::velocity>(e);
}

void deleteDrawable(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::drawable>(e);
}

void deleteInputKeyboard(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::inputKeyboard>(e);
}

void deleteInputMouse(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::inputMouse>(e);
}

void deleteCollisionable(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::collisionable>(e);
}

void deleteSpriteComponent(size_t const e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::sprite>(e);
}

void deleteLoopComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::loop>(e);
}

void deleteAnimationComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::animation>(e);
}

void deleteNameComponent(size_t e)
{
    auto &r = engine::Manager::getRegistry();
    r->removeComponent<component::name>(e);
}
