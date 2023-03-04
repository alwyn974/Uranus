/*
** EPITECH PROJECT, 2023
** TextureManager.cpp
** File description:
** TextureManager.cpp
*/

#include "uranus/engine/manager/TextureManager.hpp"

std::shared_ptr<engine::Texture> &engine::TextureManager::getTextureByName(const std::string &textureName)
{
    for (std::shared_ptr<engine::Texture> &textureItem : this->_textures) {
        if (textureItem->getName() == textureName) {
            return textureItem;
        }
    }
    throw std::runtime_error("Texture not found"); // TODO: change this, by fallback texture
}

void engine::TextureManager::addTexture(const std::string &path, const std::string &textureName)
{
    auto texture = std::make_shared<engine::Texture>(path, textureName);
    this->_textures.push_back(texture);
}
