/*
** EPITECH PROJECT, 2023
** Scene.cpp
** File description:
** Scene.cpp
*/

#include "uranus/engine/components/Scene.hpp"

engine::Scene::Scene(const std::string &name)
{
    this->_name = name;
}

const std::string &engine::Scene::getName() const
{
    return this->_name;
}
