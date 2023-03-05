/*
** EPITECH PROJECT, 2023
** Core.hpp
** File description:
** Core.hpp
*/

#ifndef URANUS_CORE_HPP
#define URANUS_CORE_HPP

/**
 * @brief This file is used to include some core files of the engine.
 * @file Core.hpp
 */

#include <spdlog/spdlog.h>
#include <array>
#include <exception>
#include <memory>
#include <string>
#include <imgui-SFML.h>
#include <imgui.h>

/**
 * @brief The uranus exception namespace.
 */
namespace uranus::ex {
    /**
     * @brief The exception class.
     */
    class Exception : public std::exception {
    public:
        /**
         * @brief The constructor of the exception class.
         * @param message The message of the exception.
         */
        explicit Exception(const std::string &message) : _message(message) {}

        /**
         * @brief Get the message of the exception.
         * @return the message of the exception.
         */
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message; /**< The message of the exception. */
    };
} // namespace uranus::ex

#endif // URANUS_CORE_HPP
