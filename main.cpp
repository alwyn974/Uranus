//
// Created by nicol on 09/01/2023.
//

#include "Enemy.hpp"
#include "Player.hpp"

#include "engine/Engine.hpp"

int main()
{
    engine::system::gameInit();

    std::shared_ptr<engine::Texture> texture = std::make_shared<engine::Texture>("ship.png");
    std::shared_ptr<engine::Texture> texture2 = std::make_shared<engine::Texture>("enemy.png");
    Player player(texture, std::string("bullet.png"));
    Enemy enemy(texture2);

    engine::system::gameLoop();
    return 0;
}


