/*
** EPITECH PROJECT, 2023
** Explosion.cpp
** File description:
** Explosion.cpp
*/

#include "Explosion.hpp"

Explosion::Explosion(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture)
    : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity entity = r->entityFromIndex(this->_entityId);

    r->addComponent(entity, component::position{pos.x, pos.y});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});

    r->addComponent(entity, component::animation{5, 1, \
    [&](const size_t entity, const std::string &animationName) { this->animationCallback(entity, animationName);}});

    engine::system::addNewAnimation(entity, "idle", true, 0.25);
    engine::system::insertAnimationFrame(entity, "idle", 0.0, 0);
    engine::system::insertAnimationFrame(entity, "idle", 0.05, 1);
    engine::system::insertAnimationFrame(entity, "idle", 0.1, 2);
    engine::system::insertAnimationFrame(entity, "idle", 0.15, 3);
    engine::system::insertAnimationFrame(entity, "idle", 0.2, 4);

    engine::system::playAnimation(entity, "idle");
}

void Explosion::animationCallback(const size_t entity, const std::string &animationName)
{
    auto &r = engine::Manager::getRegistry();
    r->killEntity(r->entityFromIndex(entity));
}
