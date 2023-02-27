/*
** EPITECH PROJECT, 2023
** Base.hpp
** File description:
** Base.hpp
*/

#ifndef URANUS_BASE_HPP
#define URANUS_BASE_HPP

#include "../ecs/Entity.hpp"
#include "Dependencies.hpp"

namespace engine {
    class Base {
    public:
        explicit Base();

    protected:
        size_t _entityId;
    };
}

#endif //URANUS_BASE_HPP
