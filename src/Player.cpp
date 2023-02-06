/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Components.hpp"
#include "Bullet.hpp"

Player::Player(registry &r) : _entity(r.spawn_entity())
{
    r.add_component(this->_entity, component::position{0, 0});
    r.add_component(this->_entity, component::velocity{0, 0});
    r.add_component(this->_entity, component::sprite{new Sprite("ship.png")});
    r.add_component(this->_entity, component::inputKeyboard{.callback = [&](registry &r, size_t entity, const sf::Event event){this->move(r, entity, event);}});
}

void Player::move(registry &r, size_t entity, const sf::Event event)
{
    auto &pos = r.get_component<component::position>(entity);
    auto &vel = r.get_component<component::velocity>(entity);
    auto &input = r.get_component<component::inputKeyboard>(entity);
    const int speed = 2;
    if (vel && input) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            vel->x = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            vel->x = speed;
        } else {
            vel->x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            vel->y = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            vel->y = speed;
        } else {
            vel->y = 0;
        }

        if (event.type == event.KeyPressed && event.key.code == sf::Keyboard::Key::A) {
            Bullet bullet(r, component::position{pos->x, pos->y});
        }
    }
}
