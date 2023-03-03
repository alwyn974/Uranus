/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "game/Bullet.hpp"
#include "game/Explosion.hpp"

Bullet::Bullet(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture)
    : Base(uniqueName)
{
    this->_canMove = false;

    auto &r = engine::Manager::getRegistry();
    uranus::ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, uranus::ecs::component::name{uniqueName});
    r->addComponent(newEntity, uranus::ecs::component::Position {pos.x, pos.y});
    r->addComponent(newEntity, uranus::ecs::component::Velocity {0, 0});
    r->addComponent(newEntity, uranus::ecs::component::sprite {std::make_shared<engine::Sprite>(texture)});

    std::array<bool, LAYER_SIZE> layer{false, false, false, false};
    std::array<bool, MASK_SIZE> mask{true, false, false, false};
    r->addComponent(newEntity, uranus::ecs::component::Sollisionable {
            0, 0, 22, 20, layer, mask, [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});
    r->addComponent(newEntity, uranus::ecs::component::loop {[&](const size_t entity) { this->loop(entity); }});
    r->addComponent(newEntity, uranus::ecs::component::inputKeyboard {[&](size_t entity, const engine::Event event) { this->handleKeyboard(entity, event); }});

    r->addComponent(newEntity, uranus::ecs::component::Animation{3, 1, [&](const size_t entity, const std::string &animationName) { return;}});
    engine::system::addNewAnimation(newEntity, "charge", false, 3);
    engine::system::insertAnimationFrame(newEntity, "charge", 0.0, 0);
    engine::system::insertAnimationFrame(newEntity, "charge", 1, 1);
    engine::system::insertAnimationFrame(newEntity, "charge", 2, 2);

    engine::system::playAnimation(newEntity, "charge");
}

void Bullet::move(size_t entity)
{
    auto &r = engine::Manager::getRegistry();
    auto &vel = r->getComponent<uranus::ecs::component::Velocity>(entity);
    vel->value().x = 5;
    if (r->getComponent<uranus::ecs::component::Position>(entity)->value().x > 900) {
        r->killEntity(entity);
    }
}

void Bullet::loop(const size_t entity)
{
    if (!this->_canMove)
        return;
    auto &r = engine::Manager::getRegistry();
    this->move(entity);
}

void Bullet::colliding(const size_t &entity, const size_t &entityCollidingWith)
{
//    std::cout << entity << ", " << entityCollidingWith << std::endl;
    auto &r = engine::Manager::getRegistry();
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();

    auto pos = r->getComponent<uranus::ecs::component::Position>(entityCollidingWith);

    auto explosion = std::make_shared<Explosion>("explosion", uranus::ecs::component::Position{pos->value().x, pos->value().y}, textureManager->getTextureByName("explosion"));
    entityManager->addPrefab(explosion);

    r->killEntity(entity);
    r->killEntity(entityCollidingWith);
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
