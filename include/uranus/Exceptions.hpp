/*
** EPITECH PROJECT, 2023
** Exceptions.hpp
** File description:
** Exceptions.hpp
*/

#ifndef URANUS_EXCEPTIONS_HPP
#define URANUS_EXCEPTIONS_HPP

#include "Core.hpp"

namespace uranus::ex {
    /**
     * @brief Thrown when an entity has an invalid index
     */
    class InvalidEntityIndex : public Exception {
    public:
        /**
         * @brief Construct a new Invalid Entity Index object
         * @param message the message to display
         */
        explicit InvalidEntityIndex(const std::string &message) : Exception(message) {};
    };
} // namespace uranus::ex

#endif // URANUS_EXCEPTIONS_HPP
