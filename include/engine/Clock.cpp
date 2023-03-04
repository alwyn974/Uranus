//
// Created by nicol on 02/03/2023.
//

#include "Clock.hpp"

uranus::Time uranus::Clock::getElapsedTime() const {
    return uranus::Time(m_clock.getElapsedTime());
}

uranus::Time uranus::Clock::restart() {
    return uranus::Time(m_clock.restart());
}