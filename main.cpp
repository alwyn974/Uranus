//
// Created by nicol on 09/01/2023.
//

#include "Bullet.hpp"
#include "Components.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Systems.hpp"
#include "Window.hpp"
#include "Button.hpp"

void buttonPressed(ecs::Registry &r, const size_t entity) {
    std::cout << "pressed!" << std::endl;
}

int main()
{
    sf::RenderWindow *window = Window::getWindow();
    window->setFramerateLimit(30);
    ecs::Registry r;
    std::function<void(ecs::Registry &, const size_t &)> delete_pos = deletePosition;
    r.registerComponent<component::position>(delete_pos);
    std::function<void(ecs::Registry &, const size_t &)> delete_vel = deleteVelocity;
    r.registerComponent<component::velocity>(delete_vel);
    std::function<void(ecs::Registry &, const size_t &)> delete_draw = deleteDrawable;
    r.registerComponent<component::drawable>(delete_draw);
    std::function<void(ecs::Registry &, const size_t &)> delete_cont = deleteControllable;
    r.registerComponent<component::controllable>(delete_cont);
    std::function<void(ecs::Registry &, const size_t &)> delete_inputK = deleteInputKeyboard;
    r.registerComponent<component::inputKeyboard>(delete_inputK);
    std::function<void(ecs::Registry &, const size_t &)> delete_inputM = deleteInputMouse;
    r.registerComponent<component::inputMouse>(delete_inputM);
    std::function<void(ecs::Registry &, const size_t &)> delete_sprite = deleteSpriteComponent;
    r.registerComponent<component::sprite>(delete_sprite);
    std::function<void(ecs::Registry &, const size_t &)> delete_loop = deleteLoopComponent;
    r.registerComponent<component::loop>(delete_loop);
    std::function<void(ecs::Registry &, const size_t &)> delete_collision = deleteCollisionable;
    r.registerComponent<component::collisionable>(delete_collision);

    Player player(r);
    Enemy enemy(r);
    Button button(r, "icon.png", buttonPressed);

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
