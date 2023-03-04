//
// Created by nicol on 02/03/2023.
//

#include "Time.hpp"

uranus::Time::Time(const sf::Time &time) : _time(time)
{
}

sf::Time uranus::Time::getTime()
{
    return _time;
}

float uranus::Time::asSeconds() const
{
    return _time.asSeconds();
}

int uranus::Time::asMilliseconds() const
{
    return _time.asMilliseconds();
}

long long uranus::Time::asMicroseconds() const
{
    return _time.asMicroseconds();
}

