//
// Created by nicol on 23/01/2023.
//

#include "Systems.hpp"

void position_system(registry &r) {
    auto &positions = r.get_components<component::position>();
    auto &velocities = r.get_components<component::velocity>();
    for (size_t i = 0; i < positions.size() && i < velocities.size() ; ++i) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        if (pos && vel) {
            pos->x += vel->x;
            pos->y += vel->y;
        }
    }
}

//void control_system(registry &r) {
//    auto &velocities = r.get_components<component::velocity>();
//    auto &controllables = r.get_components<component::controllable>();
//    for ( size_t i = 0; i < velocities.size() && i < controllables.size(); ++i) {
//        auto &vel = velocities[i];
//        auto &controllable = controllables[i];
//        if (vel && controllable) {
//            if (sf::Keyboard::isKeyPressed (sf::Keyboard::Key::Left)) {
//                vel->x = - 1 ;
//            } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Right ) ) {
//                vel->x = 1;
//            } else {
//                vel->x = 0;
//            }
//            if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Up ) ) {
//                vel->y = - 1 ;
//            } else if ( sf::Keyboard::isKeyPressed ( sf::Keyboard::Key::Down ) ) {
//                vel->y = 1;
//            } else {
//                vel->y = 0;
//            }
//        }
//    }
//}

void draw_system(registry &r) {
    auto &positions = r.get_components<component::position>();
    auto &drawables = r.get_components<component::drawable>();
    auto &sprites = r.get_components<component::sprite>();
    sf::RenderWindow *window = Window::getWindow();
    for (size_t i = 0; i < positions.size() && i < drawables.size(); ++i) {
        auto &pos = positions[i];
        auto &drawable = drawables[i];
        if (pos && drawable) {
            drawable->shape->setPosition(pos->x, pos->y);
            drawable->shape->setFillColor(drawable->color);
            window->draw(*drawable->shape);
        }
    }
     for (size_t i = 0; i < positions.size() && i < sprites.size(); ++i) {
        auto &pos = positions[i];
        auto &sprite = sprites[i];
        if (pos && sprite) {
            sprite->sprite->get().setPosition(pos->x, pos->y);
            window->draw(sprite->sprite->get());
        }
    }
}


void input_system(registry &r, sf::Event event) {
    auto &inputKeyboards = r.get_components<component::inputKeyboard>();
    auto &inputMouses = r.get_components<component::inputMouse>();
    for (size_t i = 0; i < inputKeyboards.size(); ++i) {
        auto &inputKeyboard = inputKeyboards[i];
        const size_t entity = inputKeyboards.get_index(inputKeyboard);
        if (inputKeyboard) {
            inputKeyboard->callback(r, entity, event);
        }
    }
    for (size_t i = 0; i < inputMouses.size(); ++i) {
        auto &inputMouse = inputMouses[i];
        const size_t entity = inputMouses.get_index(inputMouse);
        if (inputMouse) {
            inputMouse->callback(r, entity, event);
        }
    }
}

bool is_colliding(const sf::FloatRect &obj1, const sf::FloatRect &obj2)
{
    if (obj1.left >= obj2.left + obj2.width ||
         obj1.left+ obj1.width <= obj2.left ||
         obj1.top >= obj2.top + obj2.height ||
         obj1.top + obj1.height <= obj2.top) {
        return false;
    }
    return true;
}

void collision_system(registry &r) {
    auto &positions = r.get_components<component::position>();
    auto &collisions = r.get_components<component::collisionable>();
    sf::RenderWindow *window = Window::getWindow();
    for (size_t i = 0; i < positions.size() && i < collisions.size(); ++i) {
        auto &pos_ref = positions[i];
        auto &collision_ref = collisions[i];
        if (pos_ref.has_value() && collision_ref.has_value()) {
             for (size_t j = 0; j < positions.size() && j < collisions.size(); ++j) {
                auto &pos = positions[j];
                auto &collision = collisions[j];
                if (collision.has_value()) {
                    const sf::FloatRect obj1{collision->x + pos->x, collision->y + pos->y, collision->width, collision->height };
                    const sf::FloatRect obj2{collision_ref->x + pos_ref->x, collision_ref->y + pos_ref->y, collision_ref->width, collision_ref->height };
                    const size_t entity = collisions.get_index(collision_ref);
                    const size_t entity_colliding_with = collisions.get_index(collision);
                    if (i != j and is_colliding(obj1, obj2)) {
                        collision_ref->callback(r, entity, entity_colliding_with);
                    }
                }
             }

            sf::Vector2f size(collision_ref->width, collision_ref->height);
            sf::RectangleShape rect(size);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineColor(sf::Color::White);
            rect.setOutlineThickness(1);
            rect.setPosition(pos_ref->x + collision_ref->x, pos_ref->y + collision_ref->y);
            window->draw(rect);
        }
    }
}

void loop_system(registry &r)
{
    auto &loops = r.get_components<component::loop>();
    for (size_t i = 0; i < loops.size(); ++i) {
        auto &loop = loops[i];
        if (loop) {
            const size_t entity = loops.get_index(loop);
            loop->update(r, entity);
        }
    }
}