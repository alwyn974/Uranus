/*
** EPITECH PROJECT, 2023
** Components.hpp
** File description:
** Components.hpp
*/

#ifndef URANUS_ENTITY_HPP
#define URANUS_ENTITY_HPP

#include "uranus/Core.hpp"
#include <cstddef>

namespace uranus::ecs {

    class Registry;

    /**
     * @brief Entity class, used to identify entities
     */
    class Entity {
        friend class Registry;

    public:
        /**
         * @brief Default destructor
         */
        ~Entity() = default;

        /**
         * @breif Overloading the operator() to get the const id of the entity
         * @return Const id of the entity
         */
        inline operator std::size_t() const { return _id; }; // NOLINT

        /**
         * @brief Overloading the operator() to get the id of the entity
         * @return Id of the entity
         */
        inline operator std::size_t&() { return _id; } // NOLINT

    private:
        /**
         * @brief Constructor of the Entity class
         */
        explicit Entity(size_t id) : _id(id) {}

        size_t _id; /**< Id of the entity */
    };
} // namespace uranus::ecs

#endif // URANUS_ENTITY_HPP
