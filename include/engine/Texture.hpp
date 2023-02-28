/*
** EPITECH PROJECT, 2023
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef URANUS_TEXTURE_HPP
#define URANUS_TEXTURE_HPP

#include "Dependencies.hpp"

namespace engine {

class Texture: public sf::Texture {
public:
    ~Texture() = default;
    explicit Texture(const std::string &path, const std::string &name);

    [[nodiscard]] const std::string &getName() const;
private:
    std::string _name;
};

}

#endif //URANUS_TEXTURE_HPP
