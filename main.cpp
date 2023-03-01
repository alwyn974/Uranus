//
// Created by nicol on 09/01/2023.
//


#include "engine/Engine.hpp"

#include "game/SceneMain.hpp"
#include "game/SceneGame.hpp"

#include "game/Player.hpp"
#include "game/Enemy.hpp"

int main()
{
    engine::system::gameInit();

    auto &sceneManager = engine::Manager::getSceneManager();
    sceneManager->addScene(std::make_shared<SceneMain>());
    sceneManager->addScene(std::make_shared<SceneGame>());
    sceneManager->changeScene("Main");

    engine::system::gameLoop();
    return 0;
}