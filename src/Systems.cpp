//
// Created by nicol on 23/01/2023.
//

#include "Systems.hpp"
#include "View.hpp"

void position_system(ecs::Registry &r)
{
    for (auto [idx, pos, vel] : View<component::position, component::velocity>(r)) {
        pos.x += vel.x;
        pos.y += vel.y;
    }
}

// void control_system(ecs::Registry &r) {
//     auto &velocities = r.getComponents<>()<component::velocity>();
//     auto &controllables = r.getComponents<>()<component::controllable>();
//     for ( size_t i = 0; i < velocities.size() && i < controllables.size(); ++i) {
//         auto &vel = velocities[i];
//         auto &controllable = controllables[i];
//         if (vel && controllable) {
//             if (sf::Keyboard::isKeyPressed (sf::Keyboard::Key::Left)) {
//                 vel->value().x = - 1 ;
//             } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Right ) ) {
//                 vel->value().x = 1;
//             } else {
//                 vel->value().x = 0;
//             }
//             if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Up ) ) {
//                 vel->value().y = - 1 ;
//             } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Down ) ) {
//                 vel->value().y = 1;
//             } else {
//                 vel->value().y = 0;
//             }
//         }
//     }
// }

void draw_system(ecs::Registry &r)
{
    sf::RenderWindow *window = Window::getWindow();
    for (auto [idx, pos, drawable] : View<component::position, component::drawable>(r)) {
        drawable.shape->setPosition(pos.x, pos.y);
        drawable.shape->setFillColor(drawable.color);
        window->draw(*drawable.shape);
    }
    for (auto [idx, pos, sprite] : View<component::position, component::sprite>(r)) {
        sprite.sprite->get().setPosition(pos.x, pos.y);
        window->draw(sprite.sprite->get());
    }
}

void input_system(ecs::Registry &r, sf::Event event)
{
    for (auto [idx, inputKeyboard] : View<component::inputKeyboard>(r))
        inputKeyboard.callback(r, idx, event);
    for (auto [idx, inputMouse] : View<component::inputMouse>(r))
        inputMouse.callback(r, idx, event);
}

bool is_colliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.left < obj2.left + obj2.width && obj1.left + obj1.width > obj2.left && obj1.top < obj2.top + obj2.height &&
        obj1.top + obj1.height > obj2.top;
}

void collision_system(ecs::Registry &r)
{
    static sf::RenderWindow* window = Window::getWindow();
    for (auto [entity1, pos1, collision1] : View<component::position, component::collisionable>(r)) {
        sf::Vector2f size(collision1.width, collision1.height);
        sf::RectangleShape rect(size);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
        rect.setPosition(pos1.x + collision1.x, pos1.y + collision1.y);
        window->draw(rect);
        for (auto [entity2, pos2, collision2] : View<component::position, component::collisionable>(r)) {
            if (entity1 == entity2) continue;
            const sf::FloatRect obj1{collision1.x + pos1.x, collision1.y + pos1.y, collision1.width, collision1.height};
            const sf::FloatRect obj2{collision2.x + pos2.x, collision2.y + pos2.y, collision2.width, collision2.height};
            if (is_colliding(obj1, obj2)) {
                collision1.callback(r, entity1, entity2);
            }
        }
    }
}

void loop_system(ecs::Registry &r)
{
    for (auto [idx, loop] : View<component::loop>(r))
        loop.update(r, idx);
}
