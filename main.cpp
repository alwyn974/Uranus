//
// Created by nicol on 09/01/2023.
//


#include "engine/Engine.hpp"
#include "game/SceneMain.hpp"

#include "game/Player.hpp"
#include "game/Enemy.hpp"

int main()
{
    engine::system::gameInit();

//    auto texture = std::make_shared<engine::Texture>("ship.png");
//    auto texture2 = std::make_shared<engine::Texture>("enemy.png");
//    Player player(texture, std::string("bullet.png"));
//    Enemy enemy(texture2);

    auto &sceneManager = engine::Manager::getSceneManager();
    sceneManager->addScene(std::make_shared<SceneMain>());
    sceneManager->changeScene("Main");
//    sceneManager->changeScene(std::make_shared<SceneMain>());

    engine::system::gameLoop();
    return 0;
}