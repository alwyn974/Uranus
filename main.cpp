/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include "uranus/Uranus.hpp"

#include "uranus/engine/Engine.hpp"
#include "uranus/game/scene/SceneMain.hpp"
#include "uranus/game/scene/SceneGame.hpp"
#include "uranus/game/Player.hpp"
#include "uranus/game/Enemy.hpp"

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
