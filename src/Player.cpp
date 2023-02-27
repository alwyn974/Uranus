/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Bullet.hpp"

Player::Player(std::shared_ptr<engine::Texture> &texture, std::string &&bulletPath)
{
    engine::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletPath);
    this->_bullet_texture = std::make_shared<engine::Texture>(bulletTexture);

    ecs::Registry *r = engine::Manager::getRegistry();
    ecs::Entity entity = r->spawnEntity();

    r->addComponent(entity, component::position {0, 0});
    r->addComponent(entity, component::velocity {0, 0});
    r->addComponent(entity, component::sprite {new engine::Sprite(texture)});
    r->addComponent(entity, component::inputKeyboard {.callback = [&](size_t entity, const engine::Event event) { this->move(entity, event); }});
}

void Player::move(size_t entity, const engine::Event event)
{
    ecs::Registry *r = engine::Manager::getRegistry();
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
            Bullet(component::position{pos->value().x, pos->value().y}, _bullet_texture);
        }
    }
}
