//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_VERTEXARRAY_HPP
#define URANUS_VERTEXARRAY_HPP

#include <SFML/Graphics.hpp>
#include "Vertex.hpp"
#include "Rect.hpp"
#include "PrimitiveType.hpp"
#include "Drawable.hpp"

namespace uranus {
    /**
     * @brief Vertex array class
     */
    class VertexArray : public Drawable {
        /**
         * @brief Default constructor
         */
        VertexArray() = default;

        /**
         * @brief Default destructor
         */
        ~VertexArray() = default;

        /**
         * @brief Get the vertex count
         * @return The number of vertices in the array
         */
        std::size_t getVertexCount() const;

        /**
         * @brief Get a vertex
         * @param index Index of the vertex to get
         * @return The vertex at index
         */
        Vertex &operator[](std::size_t index);

        /**
         * @brief Get a vertex
         * @param index Index of the vertex to get
         * @return The vertex at index
         */
        const Vertex &operator[](std::size_t index) const;

        /**
         * @brief Clear the vertex array
         */
        void clear();

        /**
         * @brief Resize the vertex array
         * @param vertexCount New size of the vertex array
         */
        void resize(std::size_t vertexCount);

        /**
         * @brief Append a vertex to the array
         * @param vertex Vertex to append
         */
        void append(const Vertex &vertex);

        /**
         * @brief Set the type of primitives
         * @param type Type of primitives
         */
        void setPrimitiveType(PrimitiveType type);

        /**
         * @brief Compute the bounding rectangle of the vertex array
         * @return The bounding rectangle of the vertex array
         */
        FloatRect getBounds() const;

    private:
        /**
         * @brief Draw the vertex array
         * @param target Render target
         * @param states Render states
         */
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        sf::VertexArray _vertexArray; /**< SFML vertex array */
    };
}


#endif //URANUS_VERTEXARRAY_HPP
