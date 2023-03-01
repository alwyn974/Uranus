/*
** EPITECH PROJECT, 2023
** Button.hpp
** File description:
** Button.hpp
*/

#ifndef URANUS_BUTTON_HPP
#define URANUS_BUTTON_HPP

#include "engine/Engine.hpp"

namespace ui {

    class Button : public engine::Base {
    public:
        Button(const std::string &uniqueName, component::position pos, std::shared_ptr<engine::Texture> &texture);

        void loop(size_t);

        void handleKeyboard(size_t entity, const engine::Event event);

        virtual void pressed();

    private:
        engine::Clock _clockPressed;
        bool _hover;
        bool _pressed;
    };


}

#endif //URANUS_BUTTON_HPP
