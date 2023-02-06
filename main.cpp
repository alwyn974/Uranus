//
// Created by nicol on 09/01/2023.
//

#include "Window.hpp"
#include "Systems.hpp"
#include "Components.hpp"

void moveLRUD(registry &r, size_t entity) {
    auto &vel = r.get_component<component::velocity>(entity);
    auto &input = r.get_component<component::inputKeyboard>(entity);
    if (vel && input) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Left) != input->keys.end()) {
            std::cout << "Left" << std::endl;
            vel->x = -1;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Right) != input->keys.end()) {
            std::cout << "Right" << std::endl;
            vel->x = 1;
        } else {
            vel->x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Up) != input->keys.end()) {
            std::cout << "Up" << std::endl;
            vel->y = -1;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Down) != input->keys.end()) {
            std::cout << "Down" << std::endl;
            vel->y = 1;
        } else {
            vel->y = 0;
        }
    }
}

void moveZQSD(registry &r, const size_t &entity) {
    auto &vel = r.get_component<component::velocity>(entity);
    auto &input = r.get_component<component::inputKeyboard>(entity);
    if (vel && input) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Q) != input->keys.end()) {
            std::cout << "Q" << std::endl;
            vel->x = -1;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::D) != input->keys.end()) {
            std::cout << "D" << std::endl;
            vel->x = 1;
        } else {
            vel->x = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::Z) != input->keys.end()) {
            std::cout << "Z" << std::endl;
            vel->y = -1;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && std::find(input->keys.begin(), input->keys.end(), sf::Keyboard::Key::S) != input->keys.end()) {
            std::cout << "S" << std::endl;
            vel->y = 1;
        } else {
            vel->y = 0;
        }
    }
}


void manage_input(registry &r, const size_t entity) {
    moveZQSD(r, entity);
}

void manage_input2(registry &r, const size_t entity) {
    moveLRUD(r, entity);
}

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
    std::function<void(registry &, const size_t &)> delete_inputK = delete_inputKeyboard;
    r.register_component<component::inputKeyboard>(delete_inputK);
    std::function<void(registry &, const size_t &)> delete_inputM = delete_inputMouse;
    r.register_component<component::inputMouse>(delete_inputM);

    Entity e1(r.spawn_entity());
    Entity e2(r.spawn_entity());
    Entity e3(r.spawn_entity());

    r.add_component(e1, component::position{0, 0});
    r.add_component(e1, component::velocity{0, 0});
    r.add_component(e1, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Blue});
    r.add_component(e1, component::inputKeyboard{std::vector<sf::Keyboard::Key>{sf::Keyboard::Key::Z, sf::Keyboard::Key::Q ,sf::Keyboard::Key::S, sf::Keyboard::Key::D}, manage_input});

    r.add_component(e2, component::position{100, 100});
    r.add_component(e2, component::velocity{0, 0});
    r.add_component(e2, component::drawable{new sf::RectangleShape(sf::Vector2f(100, 100)), sf::Color::Red});
    r.add_component(e2, component::inputKeyboard{std::vector<sf::Keyboard::Key>{sf::Keyboard::Key::Left, sf::Keyboard::Key::Up ,sf::Keyboard::Key::Right, sf::Keyboard::Key::Down}, manage_input2});

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
            input_system(r);
        }
        window->clear();
//        control_system(r);
        position_system(r);
        draw_system(r);
        window->display();
    }
    r.kill_entity(e1);
    r.kill_entity(e2);
    r.kill_entity(e3);
    return 0;
}

