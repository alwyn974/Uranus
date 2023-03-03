/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include "game/Enemy.hpp"
#include "game/Player.hpp"
#include "game/scene/SceneGame.hpp"
#include "game/scene/SceneMain.hpp"
#include "uranus/engine/Engine.hpp"
#include "uranus/Uranus.hpp"

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
