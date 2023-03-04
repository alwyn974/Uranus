//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_TIME_HPP
#define URANUS_TIME_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Time class
     */
    class Time {
    public:
        /**
         * @brief Default constructor
         */
        Time() = default;

        /**
         * @brief Default destructor
         */
        ~Time() = default;

        /**
         * @brief Constructor from sf::Time
         * @param time Time to copy
         */
        explicit Time(const sf::Time& time);

        /**
         * @brief Get the SFML Time
         * @return The SFML Time
         */
        sf::Time getTime();

        /**
         * @brief Get the time as seconds
         * @return Time as seconds
         */
        float asSeconds() const;

        /**
         * @brief Get the time as milliseconds
         * @return Time as milliseconds
         */
        int asMilliseconds() const;

        /**
         * @brief Get the time as microseconds
         * @return Time as microseconds
         */
        long long asMicroseconds() const;

    private:
        sf::Time _time /**< SFML time */;
    };
}


#endif //URANUS_TIME_HPP
