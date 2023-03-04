/*
** EPITECH PROJECT, 2023
** Map.hpp
** File description:
** Map.hpp
*/

#ifndef PARSER_MAP_HPP
#define PARSER_MAP_HPP

#include "uranus/engine/Engine.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <uranus/external/tileson/Tileson.hpp>

class Tile {
    public:
        explicit Tile(const std::string &name, sf::VertexArray &quad);

        inline const std::string &getName() const { return _name; };
        inline const sf::VertexArray &getQuad() const { return _quad; };

    private:
        std::string _name;
        sf::VertexArray _quad;
};

class Layer {
    public:
        explicit Layer(const std::string &name);

        inline const std::string &getName() const { return _name; };
        inline std::vector<Tile> &getTiles()  { return _tiles; };
        inline const std::vector<Tile> &getTiles() const { return this->_tiles; };

    private:
        std::string _name;
        std::vector<Tile> _tiles;
};

class Map: public sf::Drawable, public sf::Transformable {
    public:
        explicit Map(const std::string& path, std::shared_ptr<engine::TextureManager> &textureMng);

        void loadMap();
        void loadTiles(tson::Layer *layer);
        void loadTexture(std::shared_ptr<engine::TextureManager> &textureMng);
        tson::Tileset *getTilesetByTileId(uint32_t id);
        static sf::Vector2i getTilePosition(uint32_t id, tson::Tileset *tileset);


    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        std::unique_ptr<tson::Map> _map;
        std::vector<Layer> _layers;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
};

#endif //PARSER_MAP_HPP