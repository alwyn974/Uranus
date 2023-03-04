/*
** EPITECH PROJECT, 2023
** Map.cpp
** File description:
** Map.cpp
*/

#include "uranus/engine/map/Map.hpp"

Map::Map(const std::string &path, std::shared_ptr<engine::TextureManager> &textureMng) {
    tson::Tileson nlohman{std::make_unique<tson::NlohmannJson>()};

    this->_map = nlohman.parse(path);
    if (this->_map->getStatus() == tson::ParseStatus::OK) {
        this->loadTexture(textureMng);
        this->loadMap();
    } else
        std::cerr << "Error while parsing the map: " << this->_map->getStatusMessage() << std::endl;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const Layer &layer: this->_layers) {
        for (const Tile &tile: layer.getTiles()) {
            auto texture = this->_textures.find(tile.getName());
            if (texture != this->_textures.end()) {
                states.texture = texture->second.get();
                target.draw(tile.getQuad(), states);
            }
        }
    }
}

void Map::loadMap() {
    for (auto &layer: this->_map->getLayers()) {
        if (layer.getType() == tson::LayerType::TileLayer) {
            this->_layers.emplace_back(layer.getName());
            this->loadTiles(&layer);
        }
    }
}

void Map::loadTiles(tson::Layer *layer) {
    for (int y = 0; y < layer->getSize().y; y++) {
        for (int x = 0; x < layer->getSize().x; x++) {
            tson::Tile *tile = layer->getTileData(x, y);
            if (tile != nullptr) {
                auto tileset = this->getTilesetByTileId(tile->getId());
                if (tileset != nullptr) {
                    auto texture = this->_textures.find(tileset->getName());
                    if (texture != this->_textures.end()) {
                        sf::VertexArray quad(sf::Quads, 4);
                        const sf::Vector2f pos = {static_cast<float>(x * tileset->getTileSize().x), static_cast<float>(y * tileset->getTileSize().y)};
                        const sf::Vector2f size = {static_cast<float>(tileset->getTileSize().x), static_cast<float>(tileset->getTileSize().y)};
                        quad[0].position = sf::Vector2f(pos.x, pos.y);
                        quad[1].position = sf::Vector2f(pos.x + size.x, pos.y);
                        quad[2].position = sf::Vector2f(pos.x + size.x, pos.y + size.y);
                        quad[3].position = sf::Vector2f(pos.x, pos.y + size.y);

                        auto tilePos = static_cast<sf::Vector2f>(Map::getTilePosition(tile->getId(), tileset));
                        quad[0].texCoords = sf::Vector2f(tilePos.x * size.x, tilePos.y * size.y);
                        quad[1].texCoords = sf::Vector2f((tilePos.x + 1) * size.x, tilePos.y * size.y);
                        quad[2].texCoords = sf::Vector2f((tilePos.x + 1) * size.x, (tilePos.y + 1) * size.y);
                        quad[3].texCoords = sf::Vector2f(tilePos.x * size.x, (tilePos.y + 1) * size.y);

                        this->_layers.back().getTiles().emplace_back(tileset->getName(), quad);
                    }
                }
            }
        }
    }
}

void Map::loadTexture(std::shared_ptr<engine::TextureManager> &textureMng) {
    for (auto &tileset: this->_map->getTilesets()) {
        textureMng->addTexture(tileset.getImagePath().string(), tileset.getName());
        this->_textures.emplace(tileset.getName(), textureMng->getTextureByName(tileset.getName()));
    }
}

tson::Tileset *Map::getTilesetByTileId(uint32_t id) {
    for (auto &tileset: this->_map->getTilesets()) {
        if (static_cast<int>(id) >= tileset.getFirstgid() && static_cast<int>(id) < tileset.getFirstgid() + tileset.getTileCount())
            return &tileset;
    }
    return nullptr;
}

sf::Vector2i Map::getTilePosition(uint32_t tileId, tson::Tileset *tileset) {
    const int x = static_cast<int>(tileId - tileset->getFirstgid()) % tileset->getColumns();
    const int y = static_cast<int>(tileId - tileset->getFirstgid()) / tileset->getColumns();
    return {x, y};
}

Layer::Layer(const std::string &name) {
    this->_name = name;
}

Tile::Tile(const std::string &name, sf::VertexArray &quad) {
    this->_name = name;
    this->_quad = quad;
}
