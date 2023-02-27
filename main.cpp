//
// Created by nicol on 09/01/2023.
//

#include "Enemy.hpp"
#include "Player.hpp"

#include "engine/Engine.hpp"

int main()
{
    ecs::Registry r;
    engine::system::gameInit(r);

    std::shared_ptr<engine::Texture> texture = std::make_shared<engine::Texture>("ship.png");
    std::shared_ptr<engine::Texture> texture2 = std::make_shared<engine::Texture>("enemy.png");
    Player player(r, texture, std::string("bullet.png"));
    Enemy enemy(r, texture2);

    engine::system::gameLoop(r);
    return 0;
}


