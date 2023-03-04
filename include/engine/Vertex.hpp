//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_VERTEX_HPP
#define URANUS_VERTEX_HPP

#include "SFML/Graphics.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace uranus {
    /**
     * @brief Vertex class
     */
    class Vertex : sf::Vertex {
    public:
        /**
         * @brief Default constructor
         */
        Vertex() = default;

        /**
         * @brief Constructor from a position
         * @param position Position of the vertex
         */
        explicit Vertex(const sf::Vector2f &position);

        /**
         * @brief Constructor from a position and a color
         * @param position Position of the vertex
         * @param color Color of the vertex
         */
        Vertex(const sf::Vector2f &position, const sf::Color &color);

        /**
         * @brief Constructor from a position and a texture coordinate
         * @param position Position of the vertex
         * @param texCoords Texture coordinates of the vertex
         */
        Vertex(const sf::Vector2f &position, const sf::Vector2f &texCoords);

        /**
         * @brief Constructor from a position, a color and a texture coordinate
         * @param position Position of the vertex
         * @param color Color of the vertex
         * @param texCoords Texture coordinates of the vertex
         */
        Vertex(const sf::Vector2f &position, const sf::Color &color, const sf::Vector2f &texCoords);

//        Vector2f position; /**< Position of the vertex */
//        Color color; /**< Color of the vertex */
//        Vector2f texCoords; /**< Coordinates of the texture's pixel to map to the vertex. */
//    private:
//        sf::Vertex _vertex; /**< SFML vertex */
    };
}


#endif //URANUS_VERTEX_HPP
