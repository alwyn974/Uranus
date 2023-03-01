/*
** EPITECH PROJECT, 2023
** Bonus.cpp
** File description:
** Bonus.cpp
*/

#include "game/bonus/Bonus.hpp"

bonus::Bonus::Bonus(const std::string &uniqueName, component::position pos, const std::string &textureName)
    : Base(uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, component::name{uniqueName});
    r->addComponent(newEntity, component::position {pos.x, pos.y});
    r->addComponent(newEntity, component::velocity {0, 0});

    auto &textureManager = engine::Manager::getTextureManager();
    r->addComponent(newEntity, component::sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName(textureName))});

    std::array<bool, LAYER_SIZE> layer{false, false, false, false};
    std::array<bool, MASK_SIZE> mask{false, true, false, false};
    r->addComponent(newEntity, component::collisionable {
        0, 0, 64, 64, layer, mask, [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});
    r->addComponent(newEntity, component::loop {[&](const size_t entity) { this->loop(entity); }});

    r->addComponent(newEntity, component::animation{5, 1, [&](const size_t entity, const std::string &animationName) { return;}});
    engine::system::addNewAnimation(newEntity, "idle", true, 1);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.0, 0);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.2, 1);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.4, 2);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.6, 3);
    engine::system::insertAnimationFrame(newEntity, "idle", 0.8, 4);

    engine::system::playAnimation(newEntity, "idle");

}

void bonus::Bonus::colliding(size_t entity, size_t entityCollidingWith)
{
    auto &r = engine::Manager::getRegistry();
    auto &entityManager = engine::Manager::getEntityManager();

    auto &name = r->getComponent<component::name>(entityCollidingWith);

    std::cout << name->value().uniqueName << std::endl;
    std::shared_ptr<engine::Base> base = entityManager->getPrefabByName(name->value().uniqueName);
    auto &player = dynamic_cast<Player &>(*base);

    r->killEntity(entity);
    this->enable(player);
}












