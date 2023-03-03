/*
** EPITECH PROJECT, 2023
** Base.hpp
** File description:
** Base.hpp
*/

#ifndef URANUS_BASE_HPP
#define URANUS_BASE_HPP

#include "uranus/ecs/Entity.hpp"
#include "Dependencies.hpp"

namespace engine {
    class Base {
    public:

        virtual ~Base() = default;

        explicit Base(const std::string &uniqueName);

        const std::string &getUniqueName();

    protected:
        std::string _uniqueName;
        size_t _entityId;
    };
}

#endif //URANUS_BASE_HPP