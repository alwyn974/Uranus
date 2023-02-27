//
// Created by nicol on 09/01/2023.
//

#include "Bullet.hpp"
#include "Components.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Systems.hpp"

#include "Window.hpp"

#include "engine/Engine.hpp"

int main()
{
    engine::RenderWindow *window = Window::getWindow();
    sf::Clock clock;
    window->setFramerateLimit(60);
    ecs::Registry r;
    r.registerComponent<component::position>(deletePosition);
    r.registerComponent<component::velocity>(deleteVelocity);
    r.registerComponent<component::drawable>(deleteDrawable);
    r.registerComponent<component::controllable>(deleteControllable);
    r.registerComponent<component::inputKeyboard>(deleteInputKeyboard);
    r.registerComponent<component::inputMouse>(deleteInputMouse);
    r.registerComponent<component::sprite>(deleteSpriteComponent);
    r.registerComponent<component::loop>(deleteLoopComponent);
    r.registerComponent<component::collisionable>(deleteCollisionable);
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("ship.png");
    std::shared_ptr<sf::Texture> texture2 = std::make_shared<sf::Texture>();
    texture2->loadFromFile("enemy.png");
    Player player(r, texture, std::string("bullet.png"));
    Enemy enemy(r, texture2);
    sf::Font font;
    font.loadFromFile("LEMONMILK-Regular.otf");
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
        float const currentTime = clock.restart().asSeconds();
        float const fps = 1.F / (currentTime);
        sf::Text fpss = sf::Text("FPS: " + std::to_string(static_cast<int>(fps)), font);
        window->draw(fpss);
        std::cout << "Entities count: " << r.getEntityCounter() << std::endl;
        window->display();
    }
    return 0;
}


