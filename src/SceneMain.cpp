/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "SceneMain.hpp"

#include "Enemy.hpp"
#include "Player.hpp"


SceneMain::SceneMain() : Scene("Main")
{}

void SceneMain::init()
{
    auto texture = std::make_shared<engine::Texture>("ship.png");
    auto texture2 = std::make_shared<engine::Texture>("enemy.png");
    Player player(texture, std::string("bullet.png"));
    Enemy enemy(texture2);
}
