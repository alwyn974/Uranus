/*
** EPITECH PROJECT, 2023
** Scene.hpp
** File description:
** Scene.hpp
*/

#ifndef URANUS_SCENE_HPP
#define URANUS_SCENE_HPP

#include "uranus/engine/Dependencies.hpp"

namespace engine {

    class Scene {
    public:
        explicit Scene(const std::string &name);

        virtual ~Scene() = default;

        virtual void init() = 0;

        [[nodiscard]]
        const std::string &getName() const;

    private:
        std::string _name;
    };
} // namespace engine

#endif // URANUS_SCENE_HPP
