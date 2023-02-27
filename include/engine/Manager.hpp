/*
** EPITECH PROJECT, 2023
** Manager.hpp
** File description:
** Manager.hpp
*/

#ifndef URANUS_MANAGER_HPP
#define URANUS_MANAGER_HPP

#include "RenderWindow.hpp"

namespace engine {
    class Manager {
    public:
        ~Manager() = default;

        Manager(const Manager &) = delete;

        Manager &operator=(const Manager &) = delete;

        static engine::RenderWindow *getWindow();

        static ecs::Registry *getRegistry();

    private:
        Manager() = default;

        static engine::RenderWindow *_window;

        static ecs::Registry *_registry;
    };
}

#endif //URANUS_MANAGER_HPP
