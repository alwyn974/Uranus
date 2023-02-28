/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Bullet.hpp"

Player::Player(const std::string &uniqueName, std::shared_ptr<engine::Texture> &texture,
               const std::string &bulletTextureName) : Base(uniqueName)
{
    this->_bulletTextureName = bulletTextureName;

    auto &r = engine::Manager::getRegistry();
    ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, component::position {0, 0});
    r->addComponent(newEntity, component::velocity {0, 0});
    r->addComponent(newEntity, component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(newEntity, component::inputKeyboard {[&](size_t entity, const engine::Event event) { this->move(entity, event);}});

    std::array<bool, LAYER_SIZE> layer{false, true, false, false};
    std::array<bool, MASK_SIZE> mask{false, false, false, false};
    r->addComponent(newEntity, component::collisionable {0, 0, 30, 15, layer, mask, \
    [&](const size_t &entity, const size_t &entityCollidingWith) { this->colliding(entity, entityCollidingWith); }});
}

void Player::move(size_t entity, const engine::Event event)
{
    auto &r = engine::Manager::getRegistry();
    auto &pos = r->getComponent<component::position>(entity);
    auto &vel = r->getComponent<component::velocity>(entity);
    const int speed = 2;
    if (vel) {
        if (engine::Keyboard::isKeyPressed(engine::Keyboard::Key::Q)) {
            vel->value().x = -speed;
        } else if (engine::Keyboard::isKeyPressed(engine::Keyboard::Key::D)) {
            vel->value().x = speed;
        } else {
            vel->value().x = 0;
        }
        if (engine::Keyboard::isKeyPressed(engine::Keyboard::Key::Z)) {
            vel->value().y = -speed;
        } else if (engine::Keyboard::isKeyPressed(engine::Keyboard::Key::S)) {
            vel->value().y = speed;
        } else {
            vel->value().y = 0;
        }
    }
    if (pos) {
        if (event.type == event.MouseButtonPressed) {
            auto &textureManager = engine::Manager::getTextureManager();
            auto &entityManager = engine::Manager::getEntityManager();
            auto bullet = std::make_shared<Bullet>("bullet", component::position{pos->value().x + 30, pos->value().y}, textureManager->getTextureByName(this->_bulletTextureName));
            entityManager->addPrefab(bullet);
        }
    }
}

void Player::colliding(const size_t &entity, const size_t &entityCollidingWith)
{

}
