//
// Created by nicol on 23/01/2023.
//

#include "Systems.hpp"

void position_system(ecs::Registry &r)
{
    auto &positions = r.getComponents<component::position>();
    auto &velocities = r.getComponents<component::velocity>();
    for (size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (pos && vel) {
            pos->value().x += vel->value().x;
            pos->value().y += vel->value().y;
        }
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
    auto &positions = r.getComponents<component::position>();
    auto &drawables = r.getComponents<component::drawable>();
    auto &sprites = r.getComponents<component::sprite>();
    sf::RenderWindow *window = Window::getWindow();
    for (size_t i = 0; i < positions.size() && i < drawables.size(); ++i) {
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (pos && drawable) {
            drawable->value().shape->setPosition(pos->value().x, pos->value().y);
            drawable->value().shape->setFillColor(drawable->value().color);
            window->draw(*drawable->value().shape);
        }
    }
    for (size_t i = 0; i < positions.size() && i < sprites.size(); ++i) {
        auto &pos = positions[i];
        auto &sprite = sprites[i];
        if (pos && sprite) {
            sprite->value().sprite->get().setPosition(pos->value().x, pos->value().y);
            window->draw(sprite->value().sprite->get());
        }
    }
}

void input_system(ecs::Registry &r, sf::Event event)
{
    auto &inputKeyboards = r.getComponents<component::inputKeyboard>();
    auto &inputMouses = r.getComponents<component::inputMouse>();
    for (size_t i = 0; i < inputKeyboards.size(); ++i) {
        auto &inputKeyboard = inputKeyboards[i];
        if (inputKeyboards.getIndex(inputKeyboard).has_value()) {
            const size_t entity = inputKeyboards.getIndex(inputKeyboard).value();
            if (inputKeyboard) { inputKeyboard->value().callback(r, entity, event); }
        }
    }
    for (size_t i = 0; i < inputMouses.size(); ++i) {
        auto &inputMouse = inputMouses[i];
        if (inputMouses.getIndex(inputMouse).has_value()) {
            const size_t entity = inputMouses.getIndex(inputMouse).value();
            if (inputMouse) { inputMouse->value().callback(r, entity, event); }
        }
    }
}

bool is_colliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    return obj1.left < obj2.left + obj2.width && obj1.left + obj1.width > obj2.left && obj1.top < obj2.top + obj2.height &&
        obj1.top + obj1.height > obj2.top;
}

void collision_system(ecs::Registry &r)
{
    auto positions = r.getComponents<component::position>();
    auto collisions = r.getComponents<component::collisionable>();
    sf::RenderWindow *window = Window::getWindow();
    for (size_t i = 0; i < positions.size() && i < collisions.size(); ++i) {
        auto pos_ref = r.getComponent<component::position>(i);
        auto collision_ref = r.getComponent<component::collisionable>(i);
        if (pos_ref && collision_ref) {
            for (size_t j = 0; j < positions.size() && j < collisions.size(); ++j) {
                auto &pos =  r.getComponent<component::position>(j);
                auto &collision =  r.getComponent<component::collisionable>(j);
                if (collision && pos) {
                    const sf::FloatRect obj1 {collision->value().x + pos->value().x, collision->value().y + pos->value().y, collision->value().width, collision->value().height};
                    const sf::FloatRect obj2 {collision_ref->value().x + pos_ref->value().x, collision_ref->value().y + pos_ref->value().y, collision_ref->value().width, collision_ref->value().height};
                    if (collisions.getIndex(collision_ref).has_value() && collisions.getIndex(collision).has_value()) {
                        const size_t entity = collisions.getIndex(collision_ref).value();
                        const size_t entity_colliding_with = collisions.getIndex(collision).value();
                        if (i != j and is_colliding(obj1, obj2)) {
                            collision_ref->value().callback(r, entity, entity_colliding_with);
                        }
                    }
                }
            }
            sf::Vector2f size(collision_ref->value().width, collision_ref->value().height);
            sf::RectangleShape rect(size);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(1);
            rect.setPosition(pos_ref->value().x + collision_ref->value().x,
                             pos_ref->value().y + collision_ref->value().y);
            window->draw(rect);
        }
    }
}

void loop_system(ecs::Registry &r)
{
    auto &loops = r.getComponents<component::loop>();
    for (size_t i = 0; i < loops.size(); ++i) {
        auto &loop = loops[i];
        if (loop) {
            if (loops.getIndex(loop).has_value()) {
                const size_t entity = loops.getIndex(loop).value();
                loop->value().update(r, entity);
            }
        }
    }
}
