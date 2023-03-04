/*
** EPITECH PROJECT, 2023
** TextureManager.hpp
** File description:
** TextureManager.hpp
*/

#ifndef URANUS_TEXTUREMANAGER_HPP
#define URANUS_TEXTUREMANAGER_HPP

#include "uranus/engine/components/Texture.hpp"

namespace engine {
    class TextureManager {
    public:
        void addTexture(const std::string &path, const std::string &name);

        std::shared_ptr<engine::Texture> &getTextureByName(const std::string &textureName);

    private:
        std::vector<std::shared_ptr<engine::Texture>> _textures;
    };

} // namespace engine

#endif // URANUS_TEXTUREMANAGER_HPP
