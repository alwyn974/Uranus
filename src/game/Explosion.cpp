/*
** EPITECH PROJECT, 2023
** Explosion.cpp
** File description:
** Explosion.cpp
*/

#include "game/Explosion.hpp"

Explosion::Explosion(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture) : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    uranus::ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, uranus::ecs::component::Name {uniqueName});
    r->addComponent(newEntity, uranus::ecs::component::Position {pos.x, pos.y});
    r->addComponent(newEntity, uranus::ecs::component::Sprite {std::make_shared<engine::Sprite>(texture)});

    r->addComponent(newEntity, uranus::ecs::component::Animation {
                                   5, 1, [&](const size_t entity, const std::string &animationName) { this->animationCallback(entity, animationName); }});

    engine::system::addNewAnimation(newEntity, "idle", true, 0.25);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.0, 0);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.05, 1);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.1, 2);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.15, 3);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.2, 4);

    engine::system::playAnimation(newEntity, "idle");
}

void Explosion::animationCallback(const size_t entity, const std::string &animationName)
{
    auto &r = engine::Manager::getRegistry();
    r->killEntity(entity);
}
