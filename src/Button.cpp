/*
** EPITECH PROJECT, 2023
** Button.cpp
** File description:
** Button.cpp
*/

#include "Button.hpp"


Button::Button(ecs::Registry &r, const std::string spritePath, std::function<void(ecs::Registry &r, const size_t)> buttonPressed) : _entity(r.spawnEntity())
{
    r.addComponent(this->_entity, component::position {400, 400});
    r.addComponent(this->_entity, component::sprite {new Sprite(spritePath)});

    r.addComponent(this->_entity, component::inputKeyboard {.callback = [&](ecs::Registry &r, size_t entity, const sf::Event event) { this->loop(r, entity, event); }});

    r.addComponent(
        this->_entity, component::collisionable {0, 0, 100, 60, [&](ecs::Registry &r, const size_t &, const size_t &) { return; }});

    auto &sprite = r.getComponent<component::sprite>(this->_entity);
    this->_spriteSize = sprite->value().sprite->get().getGlobalBounds();
    this->_buttonPressed = buttonPressed;
}

void Button::loop(ecs::Registry &r, const size_t entity, const sf::Event event)
{
    sf::RenderWindow *window = Window::getWindow();
    auto &pos = r.getComponent<component::position>(entity);
    auto &collision = r.getComponent<component::collisionable>(entity);
    auto &sprite = r.getComponent<component::sprite>(entity);

    sf::FloatRect mouseRect{float(sf::Mouse::getPosition(*window).x), float(sf::Mouse::getPosition(*window).y), 0, 0};
    sf::FloatRect buttonRect{collision->value().x + pos->value().x, collision->value().y + pos->value().y, collision->value().width, collision->value().height};
    sf::FloatRect spriteSize = this->_spriteSize;

    if (is_colliding(mouseRect, buttonRect)) {
        sf::IntRect rect{int(spriteSize.width / 2), int(spriteSize.top), int(spriteSize.width / 2), int(spriteSize.height)};
        sprite->value().sprite->get().setTextureRect(rect);
        if (event.type == event.MouseButtonPressed) {
            this->_buttonPressed(r, entity);
        }
    } else {
        sf::IntRect rect{int(spriteSize.left), int(spriteSize.top), int(spriteSize.width / 2), int(spriteSize.height)};
        sprite->value().sprite->get().setTextureRect(rect);
    }
}
