/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include "uranus/Uranus.hpp"

#include "uranus/engine/Engine.hpp"
#include "game/scene/SceneMain.hpp"
#include "game/scene/SceneGame.hpp"
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
