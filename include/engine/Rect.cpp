//
// Created by nicol on 01/03/2023.
//

#include "Rect.hpp"

template<typename T>
uranus::Rect<T>::Rect(T left, T top, T width, T height) : sf::Rect<T>(left, top, width, height)
{
}

template<typename T>
uranus::Rect<T>::Rect(const sf::Rect<T> &rect) : sf::Rect<T>(rect)
{
}
