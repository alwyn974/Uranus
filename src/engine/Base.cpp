/*
** EPITECH PROJECT, 2023
** Base.cpp
** File description:
** Base.cpp
*/

#include "uranus/engine/Base.hpp"
#include "uranus/engine/Manager.hpp"

engine::Base::Base(const std::string &uniqueName)
{
    auto &r = engine::Manager::getRegistry();
    this->_entityId = r->spawnEntity();
    this->_uniqueName = uniqueName;
}

const std::string &engine::Base::getUniqueName()
{
    return this->_uniqueName;
}
