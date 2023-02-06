//
// Created by nicol on 09/01/2023.
//

#ifndef B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP
#define B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP

#include <cstddef>

class registry;

class Entity {
    friend class registry;
public:
    ~Entity() = default;
    operator std::size_t() const {return _id;}
    operator std::size_t &() {return _id;}
private:
    explicit Entity(size_t id) : _id(id) {}
    size_t _id;
};

#endif //B_CPP_500_RUN_5_2_BSRTYPE_NICOLAS_REBOULE_ENTITY_HPP
