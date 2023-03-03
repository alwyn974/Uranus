/*
** EPITECH PROJECT, 2023
** TextureManager.cpp
** File description:
** TextureManager.cpp
*/

#include "engine/TextureManager.hpp"

std::shared_ptr<engine::Texture> &engine::TextureManager::getTextureByName(const std::string &textureName)
{
    for (std::shared_ptr<engine::Texture> &textureItem : this->_textures) {
        if (textureItem->getName() == textureName) {
            return textureItem;
        }
    }
}

void engine::TextureManager::addTexture(const std::string &path, const std::string &textureName)
{
    auto texture = std::make_shared<engine::Texture>(path, textureName);
    this->_textures.push_back(texture);
}
