/*
** EPITECH PROJECT, 2023
** EnemyShooter.hpp
** File description:
** EnemyShooter.hpp
*/

#ifndef URANUS_ENEMYSHOOTER_HPP
#define URANUS_ENEMYSHOOTER_HPP

#include "Enemy.hpp"

class EnemyShooter : public Enemy {
public:
    explicit EnemyShooter(const std::string &uniqueName, uranus::ecs::component::Position pos, std::shared_ptr<engine::Texture> &texture);

    void loop(size_t entity) override;

private:
    engine::Clock _shootClock;
    engine::Clock _movementClock;
};

#endif // URANUS_ENEMYSHOOTER_HPP
