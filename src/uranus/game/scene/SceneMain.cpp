/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "uranus/game/scene/SceneMain.hpp"

#include "uranus/game/Enemy.hpp"
#include "uranus/game/EnemyShooter.hpp"
#include "uranus/game/Player.hpp"

#include "uranus/game/bonus/DoubleBullet.hpp"

#include "uranus/game/ui/Button.hpp"


SceneMain::SceneMain() : Scene("Main"){}


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

    ecs::Entity newEntity2 = r->spawnEntity();
    r->addComponent(newEntity2, component::name{"background"});
    r->addComponent(newEntity2, component::position {0, 0});
    r->addComponent(newEntity2, component::sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName("background"))});

    auto buttonPlay = std::make_shared<ui::Button>("buttonPlay", component::position{300, 300}, textureManager->getTextureByName("buttonPlay"), pressedPlay);
    entityManager->addPrefab(buttonPlay);

    auto buttonQuit = std::make_shared<ui::Button>("buttonQuit", component::position{300, 380}, textureManager->getTextureByName("buttonQuit"), pressedQuit);
    entityManager->addPrefab(buttonQuit);

    ecs::Entity newEntity = r->spawnEntity();
    r->addComponent(newEntity, component::name{"logo"});
    r->addComponent(newEntity, component::position {220, 50});
    r->addComponent(newEntity, component::sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName("logo"))});


}
