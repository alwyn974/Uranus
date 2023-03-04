/*
** EPITECH PROJECT, 2023
** Rect.hpp
** File description:
** Rect.hpp
*/

#ifndef URANUS_RECT_HPP
#define URANUS_RECT_HPP

#include "uranus/engine/Dependencies.hpp"

namespace engine {

    template<typename T>
    class Rect : public sf::Rect<T> {};

    typedef Rect<int> IntRect;
    typedef Rect<float> FloatRect;

} // namespace engine

#endif // URANUS_RECT_HPP
