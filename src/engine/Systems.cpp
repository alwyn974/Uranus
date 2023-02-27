//
// Created by nicol on 23/01/2023.
//

#include "engine/Systems.hpp"

void engine::system::position(ecs::Registry &r)
{
    for (auto [idx, pos, vel] : View<component::position, component::velocity>(r)) {
        pos.x += vel.x;
        pos.y += vel.y;
    }
}

void engine::system::draw(ecs::Registry &r)
{
    sf::RenderWindow *window = engine::Manager::getWindow();
    for (auto [idx, pos, drawable] : View<component::position, component::drawable>(r)) {
        drawable.shape->setPosition(pos.x, pos.y);
        drawable.shape->setFillColor(drawable.color);
        window->draw(*drawable.shape);
    }
    for (auto [idx, pos, sprite] : View<component::position, component::sprite>(r)) {
        sprite.sprite->setPosition(pos.x, pos.y);
        window->draw(*sprite.sprite);
    }
}

void engine::system::input(ecs::Registry &r, engine::Event event)
{
    for (auto [idx, inputKeyboard] : View<component::inputKeyboard>(r))
        inputKeyboard.callback(r, idx, event);
    for (auto [idx, inputMouse] : View<component::inputMouse>(r))
        inputMouse.callback(r, idx, event);
}

bool engine::system::isColliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.left < obj2.left + obj2.width && obj1.left + obj1.width > obj2.left && obj1.top < obj2.top + obj2.height &&
        obj1.top + obj1.height > obj2.top;
}

void engine::system::collision(ecs::Registry &r)
{
    static sf::RenderWindow* window = engine::Manager::getWindow();
    for (auto [entity1, pos1, collision1] : View<component::position, component::collisionable>(r)) {
        //start debug
        sf::Vector2f size(collision1.width, collision1.height);
        sf::RectangleShape rect(size);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
        rect.setPosition(pos1.x + collision1.x, pos1.y + collision1.y);
        window->draw(rect);
        //end debug
        for (auto [entity2, pos2, collision2] : View<component::position, component::collisionable>(r)) {
            if (entity1 == entity2) continue;
            const sf::FloatRect obj1{collision1.x + pos1.x, collision1.y + pos1.y, collision1.width, collision1.height};
            const sf::FloatRect obj2{collision2.x + pos2.x, collision2.y + pos2.y, collision2.width, collision2.height};
            if (isColliding(obj1, obj2)) {
                collision1.callback(r, entity1, entity2);
            }
        }
    }
}

void engine::system::loop(ecs::Registry &r)
{
    for (auto [idx, loop] : View<component::loop>(r))
        loop.update(r, idx);
}

void engine::system::gameLoop(ecs::Registry &r)
{
    static sf::RenderWindow* window = engine::Manager::getWindow();
    while (window->isOpen()) {
        engine::Event event;
        while (window->pollEvent(event)) {
            if (event.type == engine::Event::Closed)
                window->close();
            engine::system::input(r, event);
        }

        window->clear();
        engine::system::loop(r);
        engine::system::position(r);
        engine::system::collision(r);
        engine::system::draw(r);

        window->display();
    }
}

void engine::system::gameInit(ecs::Registry &r)
{
    engine::RenderWindow *window = engine::Manager::getWindow();
    window->setFramerateLimit(60);

    r.registerComponent<component::position>(deletePosition);
    r.registerComponent<component::velocity>(deleteVelocity);
    r.registerComponent<component::drawable>(deleteDrawable);
    r.registerComponent<component::controllable>(deleteControllable);
    r.registerComponent<component::inputKeyboard>(deleteInputKeyboard);
    r.registerComponent<component::inputMouse>(deleteInputMouse);
    r.registerComponent<component::sprite>(deleteSpriteComponent);
    r.registerComponent<component::loop>(deleteLoopComponent);
    r.registerComponent<component::collisionable>(deleteCollisionable);
}
