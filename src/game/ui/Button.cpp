/*
** EPITECH PROJECT, 2023
** Button.cpp
** File description:
** Button.cpp
*/

#include "game/ui/Button.hpp"

ui::Button::Button(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture, const std::function<void()> &callbackPressed)
    : Base(uniqueName)
{
    this->_hover = false;
    this->_pressed = false;
    this->_callbackPressed = callbackPressed;

    auto &r = engine::Manager::getRegistry();
    uranus::ecs::Entity newEntity = r->entityFromIndex(this->_entityId);

//    std::cout << this->_entityId << std::endl;

    r->addComponent(newEntity, uranus::ecs::component::name{uniqueName});
    r->addComponent(newEntity, uranus::ecs::component::Position{pos.x, pos.y});
    r->addComponent(newEntity, uranus::ecs::component::Velocity {0, 0});
    r->addComponent(newEntity, uranus::ecs::component::sprite {std::make_shared<engine::Sprite>(texture)});
    r->addComponent(newEntity, uranus::ecs::component::inputKeyboard {[&](size_t entity, const engine::Event event) { this->handleKeyboard(entity, event);}});

    std::array<bool, LAYER_SIZE> layer{true, false, false, false};
    std::array<bool, MASK_SIZE> mask{false, false, false, false};
    r->addComponent(newEntity, uranus::ecs::component::Sollisionable {0, 0, static_cast<float>(texture->getSize().x) / 3, static_cast<float>(texture->getSize().y), layer, mask, \
    [&](const size_t &entity, const size_t &entityCollidingWith) { return; }});

    r->addComponent(newEntity, uranus::ecs::component::loop {[&](const size_t entity) { this->loop(entity); }});

    r->addComponent(newEntity, uranus::ecs::component::Animation{3, 1, \
    [&](const size_t entity, const std::string &animationName) { return;}});

    engine::system::addNewAnimation(newEntity, "normal", false, 0.0);
    engine::system::insertAnimationFrame(newEntity, "normal", 0.0, 0);

    engine::system::addNewAnimation(newEntity, "hover", false, 0.0);
    engine::system::insertAnimationFrame(newEntity, "hover", 0.0, 1);

    engine::system::addNewAnimation(newEntity, "pressed", false, 0.0);
    engine::system::insertAnimationFrame(newEntity, "pressed", 0.0, 2);


    engine::system::playAnimation(newEntity, "normal");
}

void ui::Button::loop(size_t entity)
{
    if (this->_pressed) {
        if (this->_clockPressed.getElapsedTime().asSeconds() > 0.1)
            this->_pressed = false;
        return;
    }

    auto &r = engine::Manager::getRegistry();
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();
    auto &window = engine::Manager::getWindow();

    auto &collision = r->getComponent<uranus::ecs::component::Sollisionable>(entity);
    auto &pos = r->getComponent<uranus::ecs::component::Position>(entity);

    sf::Vector2f mousePosition{static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y)};
    sf::FloatRect mouseRect{mousePosition.x, mousePosition.y, 0, 0};

    const sf::FloatRect rect{collision->value().x + pos->value().x, collision->value().y + pos->value().y, collision->value().width,
                             collision->value().height};

    if (engine::system::isColliding(mouseRect, rect)) {
        this->_hover = true;
        engine::system::playAnimation(entity, "hover");
    } else {
        this->_hover = false;
        engine::system::playAnimation(entity, "normal");
    }
}

void ui::Button::handleKeyboard(size_t entity, const engine::Event event)
{
   if (!this->_hover || this->_pressed)
       return;
    if (event.mouseButton.button == sf::Mouse::Left && event.type == event.MouseButtonPressed) {
        engine::system::playAnimation(this->_entityId, "pressed");
        this->_pressed = true;
        this->_clockPressed.restart();
        this->_callbackPressed();
    }
}
