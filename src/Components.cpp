//
// Created by nicol on 23/01/2023.
//

#include "Components.hpp"

void deletePosition(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::position>(e);
}

void deleteVelocity(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::velocity>(e);
}

void deleteDrawable(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::drawable>(e);
}

void deleteControllable(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::controllable>(e);
}

void deleteInputKeyboard(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::inputKeyboard>(e);
}

void deleteInputMouse(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::inputMouse>(e);
}

void deleteCollisionable(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::collisionable>(e);
}

void deleteSpriteComponent(ecs::Registry &r, size_t const e)
{
    r.removeComponent<component::sprite>(e);
}

void deleteLoopComponent(ecs::Registry &r, size_t e)
{
    r.removeComponent<component::loop>(e);
}
