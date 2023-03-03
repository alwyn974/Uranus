/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/

#include "game/scene/SceneMain.hpp"
#include "game/bonus/DoubleBullet.hpp"
#include "game/Enemy.hpp"
#include "game/EnemyShooter.hpp"
#include "game/Player.hpp"
#include "game/ui/Button.hpp"

SceneMain::SceneMain() : Scene("Main") {}

void pressedPlay()
{
    auto &sceneManager = engine::Manager::getSceneManager();
    sceneManager->changeScene("Game");
}

void pressedQuit()
{
    auto &window = engine::Manager::getWindow();
    window->close();
}

void SceneMain::init()
{
    auto &entityManager = engine::Manager::getEntityManager();
    auto &textureManager = engine::Manager::getTextureManager();

    auto &r = engine::Manager::getRegistry();

    textureManager->addTexture("assets/ship.png", "ship");
    textureManager->addTexture("assets/enemy.png", "enemy");
    textureManager->addTexture("assets/enemy2.png", "enemyShooter");
    textureManager->addTexture("assets/bullet3.png", "bullet");
    textureManager->addTexture("assets/bulletEnemy.png", "bulletEnemy");
    textureManager->addTexture("assets/explosion.png", "explosion");
    textureManager->addTexture("assets/bonusDouble.png", "bonusDoubleBullet");
    textureManager->addTexture("assets/button.png", "button");
    textureManager->addTexture("assets/buttonPlay.png", "buttonPlay");
    textureManager->addTexture("assets/buttonQuit.png", "buttonQuit");
    textureManager->addTexture("assets/logo2.png", "logo");
    textureManager->addTexture("assets/background2.png", "background");

    uranus::ecs::Entity newEntity2 = r->spawnEntity();
    r->addComponent(newEntity2, uranus::ecs::component::Name {"background"});
    r->addComponent(newEntity2, uranus::ecs::component::Position {0, 0});
    r->addComponent(newEntity2, uranus::ecs::component::Sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName("background"))});

    auto buttonPlay =
        std::make_shared<ui::Button>("buttonPlay", uranus::ecs::component::Position {300, 300}, textureManager->getTextureByName("buttonPlay"), pressedPlay);
    entityManager->addPrefab(buttonPlay);

    auto buttonQuit =
        std::make_shared<ui::Button>("buttonQuit", uranus::ecs::component::Position {300, 380}, textureManager->getTextureByName("buttonQuit"), pressedQuit);
    entityManager->addPrefab(buttonQuit);

    uranus::ecs::Entity newEntity = r->spawnEntity();
    r->addComponent(newEntity, uranus::ecs::component::Name {"logo"});
    r->addComponent(newEntity, uranus::ecs::component::Position {220, 50});
    r->addComponent(newEntity, uranus::ecs::component::Sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName("logo"))});
}
