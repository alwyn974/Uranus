/*
** EPITECH PROJECT, 2023
** SceneGame.hpp
** File description:
** SceneGame.hpp
*/

#ifndef URANUS_SCENEGAME_HPP
#define URANUS_SCENEGAME_HPP

#include "uranus/engine/Engine.hpp"

class SceneGame : public engine::Scene {
public:
    explicit SceneGame();

    ~SceneGame() override = default;

    void init() override;

private:
};

#endif // URANUS_SCENEGAME_HPP
