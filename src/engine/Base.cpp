/*
** EPITECH PROJECT, 2023
** Base.cpp
** File description:
** Base.cpp
*/

#include "engine/Base.hpp"
#include "engine/Manager.hpp"

engine::Base::Base()
{
    auto &r = engine::Manager::getRegistry();
    this->_entityId = r->spawnEntity();
}
