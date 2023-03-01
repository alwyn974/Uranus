/*
** EPITECH PROJECT, 2023
** SceneMain.cpp
** File description:
** SceneMain.cpp
*/


#include "game/scene/SceneMain.hpp"

#include "game/Enemy.hpp"
#include "game/EnemyShooter.hpp"
#include "game/Player.hpp"

#include "game/bonus/DoubleBullet.hpp"

#include "game/ui/Button.hpp"


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

    textureManager->addTexture("ship.png", "ship");
    textureManager->addTexture("enemy.png", "enemy");
    textureManager->addTexture("enemy2.png", "enemyShooter");
    textureManager->addTexture("bullet3.png", "bullet");
    textureManager->addTexture("bulletEnemy.png", "bulletEnemy");
    textureManager->addTexture("explosion.png", "explosion");
    textureManager->addTexture("bonusDouble.png", "bonusDoubleBullet");
    textureManager->addTexture("button.png", "button");
    textureManager->addTexture("buttonPlay.png", "buttonPlay");
    textureManager->addTexture("buttonQuit.png", "buttonQuit");
    textureManager->addTexture("logo.png", "logo");

    auto buttonPlay = std::make_shared<ui::Button>("buttonPlay", component::position{300, 300}, textureManager->getTextureByName("buttonPlay"), pressedPlay);
    entityManager->addPrefab(buttonPlay);

    auto buttonQuit = std::make_shared<ui::Button>("buttonQuit", component::position{300, 380}, textureManager->getTextureByName("buttonQuit"), pressedQuit);
    entityManager->addPrefab(buttonQuit);

    ecs::Entity newEntity = r->spawnEntity();
    r->addComponent(newEntity, component::name{"logo"});
    r->addComponent(newEntity, component::position {260, 50});
    r->addComponent(newEntity, component::sprite {std::make_shared<engine::Sprite>(textureManager->getTextureByName("logo"))});
}
