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

    ~EnemyShooter() override = default;

    explicit EnemyShooter(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture);

    void loop(size_t entity) override;

private:
    engine::Clock _clock;
    engine::Clock _sineClock;
    float _tick;
};

#endif //URANUS_ENEMYSHOOTER_HPP
