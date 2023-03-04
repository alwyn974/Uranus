/*
** EPITECH PROJECT, 2023
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef URANUS_TEXTURE_HPP
#define URANUS_TEXTURE_HPP

#include "uranus/engine/Dependencies.hpp"

namespace engine {

    class Texture : public sf::Texture {
    public:
        explicit Texture(const std::string &path, const std::string &name);

        [[nodiscard]]
        const std::string &getName() const;

    private:
        std::string _name;
    };

} // namespace engine

#endif // URANUS_TEXTURE_HPP
