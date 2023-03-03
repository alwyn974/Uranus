//
// Created by nicol on 01/03/2023.
//

#include "Vector2.hpp"

template<typename T>
uranus::Vector2<T>::Vector2(T x, T y) : sf::Vector2<T>(x, y)
{
}

template<typename T>
uranus::Vector2<T>::Vector2(const sf::Vector2<T> &vector) : sf::Vector2<T>(vector)
{
}

