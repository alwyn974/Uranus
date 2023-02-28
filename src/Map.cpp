//
// Created by bareth on 27/02/23.
//

#include <fstream>
#include "Map.hpp"

Map::Map(std::string path, std::shared_ptr<engine::TextureManager> &textureMng)
{
    tson::Tileson nlohman {std::make_unique<tson::NlohmannJson>()};

    this->_map = nlohman.parse(path);
    if (this->_map->getStatus() == tson::ParseStatus::OK) {
        this->loadMap();
        this->loadTexture(textureMng);
    } else
        std::cerr << "Error while parsing the map: " << this->_map->getStatusMessage() << std::endl;
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    for (auto &layer : this->_layers) {
        states.texture = this->_textures.at(layer.first).get();
        target.draw(layer.second, states);
    }
}

void Map::loadMap() {
    for (auto &layer : this->_map->getLayers()) {
        if (layer.getType() == tson::LayerType::TileLayer) {
            this->loadTiles(&layer);
        }
    }
}

void Map::loadTiles(tson::Layer *layer)
{
    sf::VertexArray vertices(sf::Quads,  layer->getSize().x * layer->getSize().y * 4);
    int i = 0;
    for (int y = 0; y < layer->getSize().y; y++) {
        for (int x = 0; x < layer->getSize().x; x++) {
            tson::Tile *tile = layer->getTileData(x, y);
            if (!tile)
                continue;
            auto tileId = tile->getId();
            if (tileId != 0) {
                sf::Vertex *quad = &vertices[i * 4];
                const sf::Vector2i tileSize(this->_map->getTileSize().x, this->_map->getTileSize().y);

                quad[0].position = sf::Vector2f(x  * tileSize.x, y * tileSize.y);
                quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
                quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

                quad[0].texCoords = sf::Vector2f(tile->getDrawingRect().x, tile->getDrawingRect().y);
                quad[1].texCoords = sf::Vector2f(tile->getDrawingRect().x + tile->getDrawingRect().width, tile->getDrawingRect().y);
                quad[2].texCoords = sf::Vector2f(tile->getDrawingRect().x + tile->getDrawingRect().width, tile->getDrawingRect().y + tile->getDrawingRect().height);
                quad[3].texCoords = sf::Vector2f(tile->getDrawingRect().x, tile->getDrawingRect().y + tile->getDrawingRect().height);
                i++;
            }
        }
    }
    this->_layers.emplace(layer->getName(), vertices);

}

void Map::loadTexture(std::shared_ptr<engine::TextureManager> &textureMng)
{
    for (auto &layer : this->_map->getLayers()) {
        this->_textures.emplace(layer.getName(), textureMng->getTextureByName(layer.getName()));
    }
}

