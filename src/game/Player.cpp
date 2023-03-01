/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "game/Player.hpp"
#include "game/Bullet.hpp"

Player::Player(const std::string &uniqueName, std::shared_ptr<engine::Texture> &texture,
               const std::string &bulletTextureName) : Base(uniqueName)
{
    this->_bulletTextureName = bulletTextureName;
    this->_doubleBullet = false;

    auto &r = engine::Manager::getRegistry();
    ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

    r->addComponent(newEntity, component::name{uniqueName});
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
    auto &vel = r->getComponent<component::velocity>(entity);
    auto &pos = r->getComponent<component::position>(entity);
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
        if (event.mouseButton.button == sf::Mouse::Left && event.type == event.MouseButtonPressed) {
           this->shoot();
        }
    }
}

void Player::colliding(const size_t &entity, const size_t &entityCollidingWith)
{

}

void Player::enableDoubleBullet()
{
    this->_doubleBullet = true;
}

void Player::shoot()
{
    auto &r = engine::Manager::getRegistry();
    auto &textureManager = engine::Manager::getTextureManager();
    auto &entityManager = engine::Manager::getEntityManager();

    auto &pos = r->getComponent<component::position>(this->_entityId);

    if (this->_doubleBullet) {
        auto bullet = std::make_shared<Bullet>("bullet", component::position{pos->value().x + 30, pos->value().y + 10}, textureManager->getTextureByName(this->_bulletTextureName));
        entityManager->addPrefab(bullet);
        auto bullet2 = std::make_shared<Bullet>("bullet", component::position{pos->value().x + 30, pos->value().y - 10}, textureManager->getTextureByName(this->_bulletTextureName));
        entityManager->addPrefab(bullet2);
    } else {
        auto bullet = std::make_shared<Bullet>("bullet", component::position{pos->value().x + 30, pos->value().y}, textureManager->getTextureByName(this->_bulletTextureName));
        entityManager->addPrefab(bullet);
    }
}
