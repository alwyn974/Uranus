//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_CLOCK_HPP
#define URANUS_CLOCK_HPP

#include <SFML/Graphics.hpp>
#include "Time.hpp"

namespace uranus {
    /**
     * @brief Clock class
     */
    class Clock {
    public:
        /**
         * @brief Default constructor
         */
        Clock() = default;

        /**
         * @brief Default destructor
         */
        ~Clock() = default;

        /**
         * @brief Get the elapsed time
         * @return Elapsed time
         */
        Time getElapsedTime() const;

        /**
         * @brief Restart the clock
         * @return Elapsed time
         */
        Time restart();

    private:
        sf::Clock m_clock; /*< SFML clock */
    };
}


#endif //URANUS_CLOCK_HPP
