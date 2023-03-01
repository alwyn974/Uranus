//
// Created by bareth on 27/02/23.
//

#ifndef PARSER_MAP_HPP
#define PARSER_MAP_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include "extern/tileson.hpp"
#include "engine/Engine.hpp"

class Map: public sf::Drawable, public sf::Transformable {
    public:
        explicit Map(std::string path, std::shared_ptr<engine::TextureManager> &textureMng);

        void loadMap();
        void loadTiles(tson::Layer *layer);
        void loadTexture(std::shared_ptr<engine::TextureManager> &textureMng);
        tson::Tileset *getTilesetByTileId(uint32_t id);
        sf::Vector2i getTilePosition(uint32_t id, tson::Tileset *tileset);


    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        std::unique_ptr<tson::Map> _map;
        std::vector<std::pair<std::string, sf::VertexArray>> _tiles;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
};

#endif //PARSER_MAP_HPP