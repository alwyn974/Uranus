/*
** EPITECH PROJECT, 2023
** SceneMain.hpp
** File description:
** SceneMain.hpp
*/

#ifndef URANUS_SCENEMAIN_HPP
#define URANUS_SCENEMAIN_HPP

#include "uranus/engine/Engine.hpp"

class SceneMain : public engine::Scene {
public:
    explicit SceneMain();

    ~SceneMain() override = default;

    void init() override;

private:
};

#endif // URANUS_SCENEMAIN_HPP
