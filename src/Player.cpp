/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "Player.hpp"

#include "Bullet.hpp"
#include "Components.hpp"

Player::Player(ecs::Registry &r, std::shared_ptr<sf::Texture> &texture, std::string &&bulletPath) : _entity(r.spawnEntity())
{
    sf::Texture bulletTexture;
    bulletTexture.loadFromFile(bulletPath);
    this->_bullet_texture = std::make_shared<sf::Texture>(bulletTexture);

    r.addComponent(this->_entity, component::position {0, 0});
    r.addComponent(this->_entity, component::velocity {0, 0});
    r.addComponent(this->_entity, component::sprite {new engine::Sprite()});

    r.addComponent(this->_entity, component::inputKeyboard {.callback = [&](ecs::Registry &r, size_t entity, const sf::Event event) { this->move(r, entity, event); }});
}

void Player::move(ecs::Registry &r, size_t entity, const sf::Event event)
{
    auto &pos = r.getComponent<component::position>(entity);
    auto &vel = r.getComponent<component::velocity>(entity);
    const int speed = 2;
    if (vel) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            vel->value().x = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            vel->value().x = speed;
        } else {
            vel->value().x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
            vel->value().y = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            vel->value().y = speed;
        } else {
            vel->value().y = 0;
        }
    }
    if (pos) {
        if (event.type == event.MouseButtonPressed) {
            Bullet(r, component::position{pos->value().x, pos->value().y}, _bullet_texture);
        }
    }
}
