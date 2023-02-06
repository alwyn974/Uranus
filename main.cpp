//
// Created by nicol on 09/01/2023.
//

#include "Window.hpp"
#include "Systems.hpp"
#include "Components.hpp"

int main() {
    sf::RenderWindow *window = Window::getWindow();
    registry r;
    std::function<void(registry &, const size_t &)> delete_pos = delete_position;
    r.register_component<component::position>(delete_pos);
    std::function<void(registry &, const size_t &)> delete_vel = delete_velocity;
    r.register_component<component::velocity>(delete_vel);
    std::function<void(registry &, const size_t &)> delete_draw = delete_drawable;
    r.register_component<component::drawable>(delete_draw);
    std::function<void(registry &, const size_t &)> delete_cont = delete_controllable;
    r.register_component<component::controllable>(delete_cont);

    Entity e1(r.spawn_entity());
    Entity e2(r.spawn_entity());
    Entity e3(r.spawn_entity());

    r.add_component(e1, component::position{0, 0});
    r.add_component(e1, component::velocity{0, 0});
    r.add_component(e1, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Blue});
    r.add_component(e1, component::controllable{});

    r.add_component(e2, component::position{100, 100});
    r.add_component(e2, component::velocity{0.01, 0.01});
    r.add_component(e2, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Red});

    r.add_component(e3, component::position{200, 200});
    r.add_component(e3, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Green});

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                r.remove_component<component::drawable>(e1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
                r.add_component(e1, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Blue});
        }
        window->clear();
        control_system(r);
        position_system(r);
        draw_system(r);
        window->display();
    }
    r.kill_entity(e1);
    r.kill_entity(e2);
    r.kill_entity(e3);
    return 0;
}

