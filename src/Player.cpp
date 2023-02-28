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
    ecs::Entity entity = r->entityFromIndex(this->_entityId);

    r->addComponent(entity, component::position {0, 0});
    r->addComponent(entity, component::velocity {0, 0});
    r->addComponent(entity, component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(entity, component::inputKeyboard {[&](size_t entity, const engine::Event event) { this->move(entity, event);}});
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
