/*
** EPITECH PROJECT, 2023
** Player.cpp
** File description:
** Player.cpp
*/

#include "Player.hpp"

#include "Enemy.hpp"
#include "Bullet.hpp"

#include "Components.hpp"

Player::Player(registry &r) : _entity(r.spawn_entity())
{
    r.add_component(this->_entity, component::position {0, 0});
    r.add_component(this->_entity, component::velocity {0, 0});
    r.add_component(this->_entity, component::sprite {new Sprite("ship.png")});
    r.add_component(
        this->_entity, component::inputKeyboard {[&](registry &r, size_t entity, const sf::Event event) { this->handle_inputs(r, entity, event); }});
    r.add_component(this->_entity, component::loop {[&](registry &r, const size_t entity) { this->loop(r, entity); }});
}

void Player::handle_inputs(registry &r, size_t entity, const sf::Event event)
{
    auto &pos = r.get_component<component::position>(entity);
    auto &vel = r.get_component<component::velocity>(entity);
    const int speed = 2;
    if (vel) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            vel->x = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            vel->x = speed;
        } else {
            vel->x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
            vel->y = -speed;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            vel->y = speed;
        } else {
            vel->y = 0;
        }
    }
    if (pos) {
        if (event.type == event.MouseButtonPressed) {
            Bullet bullet(r, component::position{pos->x, pos->y});
//            Bullet bullet(r, component::position{pos->x, pos->y});
        }
    }
}

void Player::loop(registry &r, const size_t entity)
{
    auto &pos = r.get_component<component::position>(this->_entity);

//    std::cout << "player loop: " << this->_entity << std::endl;
//    std::cout << "lol" << std::endl;
}
