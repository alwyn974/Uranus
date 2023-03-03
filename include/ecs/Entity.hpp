//
// Created by nicol on 09/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP

#include <cstddef>

namespace ecs {

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
        inline operator std::size_t() const { return _id; };

        /**
         * @brief Overloading the operator() to get the id of the entity
         * @return Id of the entity
         */
        inline operator std::size_t &() { return _id; }

    private:
        /**
         * @brief Constructor of the Entity class
         */
        explicit Entity(size_t id) : _id(id) {}

        size_t _id; /*< Id of the entity */
    };
}

#endif // B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP
