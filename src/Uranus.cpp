/*
** EPITECH PROJECT, 2023
** Uranus.cpp
** File description:
** Uranus.cpp
*/

// #include "uranus/Uranus.hpp"

#include "game/scene/SceneGame.hpp"
#include "game/scene/SceneMain.hpp"
#include "uranus/engine/Engine.hpp"

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
