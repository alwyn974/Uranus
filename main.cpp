//
// Created by nicol on 09/01/2023.
//

#include "Bullet.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Window.hpp"

#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

int main()
{
    sf::RenderWindow *window = Window::getWindow();
    window->setFramerateLimit(30);

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
    std::function<void(registry &, const size_t &)> delete_sprite = delete_sprite_component;
    r.register_component<component::sprite>(delete_sprite);
    std::function<void(registry &, const size_t &)> delete_loop = delete_loop_component;
    r.register_component<component::loop>(delete_loop);
    std::function<void(registry &, const size_t &)> delete_collision = delete_collisionable;
    r.register_component<component::collisionable>(delete_collision);



    Player player(r);
//    r.kill_entity(r.entity_from_index(0));
//    Enemy enemy(r, component::position{200, 200});
//    r.kill_entity(r.entity_from_index(0));



    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) window->close();

            input_system(r, event);
        }
        window->clear();
        loop_system(r);
        position_system(r);
        collision_system(r);
        draw_system(r);
        window->display();
    }
    return 0;
}
