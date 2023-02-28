/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "Bullet.hpp"
#include "Explosion.hpp"


Bullet::Bullet(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture)
    : Base(uniqueName)
{
    this->_canMove = false;

    auto &r = engine::Manager::getRegistry();
    ecs::Entity entity = r->entityFromIndex(this->_entityId);

    r->addComponent(entity, component::position {pos.x, pos.y});
    r->addComponent(entity, component::velocity {0, 0});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});

    std::array<bool, 4> layer{false, false, false, false};
    std::array<bool, 4> mask{true, false, false, false};
    r->addComponent(entity, component::collisionable {
            10, 10, 22, 20, layer, mask, [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});
    r->addComponent(entity, component::loop {[&](const size_t entity) { this->loop(entity); }});
    r->addComponent(entity, component::inputKeyboard {[&](size_t entity, const engine::Event event) { this->handleKeyboard(entity, event); }});

    r->addComponent(entity, component::animation{3, 1, [&](const size_t entity, const std::string &animationName) { return;}});
    engine::system::addNewAnimation(entity, "charge", false, 3);
    engine::system::insertAnimationFrame(entity, "charge", 0.0, 0);
    engine::system::insertAnimationFrame(entity, "charge", 1, 1);
    engine::system::insertAnimationFrame(entity, "charge", 2, 2);

    engine::system::playAnimation(entity, "charge");
}

void Bullet::move(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<component::velocity>(entity);
    vel->value().x = 5;
}

void Bullet::loop(const size_t entity)
{
    if (!this->_canMove)
        return;
    auto &r = engine::Manager::getRegistry();
    this->move(entity);
    if (r->getComponent<component::position>(entity)->value().x > 600) {
        r->killEntity(r->entityFromIndex(entity));
    }
}

void Bullet::colliding(const size_t &entity, const size_t &entityCollidingWith)
{
    auto &r = engine::Manager::getRegistry();
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();

    auto pos = r->getComponent<component::position>(entityCollidingWith);

    auto explosion = std::make_shared<Explosion>("explosion", component::position{pos->value().x, pos->value().y}, textureManager->getTextureByName("explosion"));
    entityManager->addPrefab(explosion);

    r->killEntity(r->entityFromIndex(entity));
    r->killEntity(r->entityFromIndex(entityCollidingWith));
}

void Bullet::handleKeyboard(size_t entity, const engine::Event event)
{
    if (this->_canMove)
        return;
    if (event.type == event.MouseButtonReleased) {
        this->_canMove = true;
        engine::system::stopAnimation(this->_entityId);
    }
}
