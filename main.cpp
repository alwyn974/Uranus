//
// Created by nicol on 09/01/2023.
//


#include "engine/Engine.hpp"
#include "SceneMain.hpp"

#include "Player.hpp"
#include "Enemy.hpp"
#include "Map.hpp"

int main()
{
//    engine::system::gameInit();
//
////    auto texture = std::make_shared<engine::Texture>("ship.png");
////    auto texture2 = std::make_shared<engine::Texture>("enemy.png");
////    Player player(texture, std::string("bullet.png"));
////    Enemy enemy(texture2);
//
//    auto &sceneManager = engine::Manager::getSceneManager();
//    sceneManager->addScene(std::make_shared<SceneMain>());
//    sceneManager->changeScene("Main");
////    sceneManager->changeScene(std::make_shared<SceneMain>());
//
//    engine::system::gameLoop();
//    return 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    auto &textureManager = engine::Manager::getTextureManager();
    textureManager->addTexture("./assets/r-typesheet8.gif", "Foreground");
    textureManager->addTexture("./assets/r-typesheet8.gif", "Background");
    Map const map("./map.json", textureManager);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(map);
        window.display();
    }
}