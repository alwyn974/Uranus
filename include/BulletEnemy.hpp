/*
** EPITECH PROJECT, 2023
** BulletEnemy.hpp
** File description:
** BulletEnemy.hpp
*/


#ifndef URANUS_BULLETENEMY_HPP
#define URANUS_BULLETENEMY_HPP

#include "Bullet.hpp"

class BulletEnemy : public Bullet {
public:
    ~BulletEnemy() override = default;

    explicit BulletEnemy(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture);

    void move(size_t entity) override;

private:
};

#endif //URANUS_BULLETENEMY_HPP

