//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_VERTEXBUFFER_HPP
#define URANUS_VERTEXBUFFER_HPP

#include "Vertex.hpp"
#include "PrimitiveType.hpp"

namespace uranus {
    /**
     * @brief A vertex buffer is a buffer that contains vertices.
     */
    class VertexBuffer {
    public:
        /**
         * @brief Usage of the buffer
         */
        enum Usage {
            Stream, /**< The buffer is updated once and used at most a few times. */
            Dynamic, /**< The buffer is updated once and used many times. */
            Static /**< The buffer is updated once and used many times. */
        };
        /**
         * @brief Default constructor
         */
        VertexBuffer() = default;

        /**
         * @brief Constructor from a primitive type
         * @param type Type of the primitive
         */
        explicit VertexBuffer(sf::PrimitiveType type);

        /**
         * @brief Constructor from a usage
         * @param type Type of the primitive
         */
        explicit VertexBuffer(Usage usage);

        /**
         * @brief Constructor from a primitive type and a usage
         * @param type Type of the primitive
         * @param usage Usage of the buffer
         */
        VertexBuffer(PrimitiveType type, Usage usage);

        /**
         * @brief Copy constructor
         * @param vertexBuffer Vertex buffer to copy
         */
        VertexBuffer(const VertexBuffer& vertexBuffer) = default;

        /**
         * @brief Default destructor
         */
        ~VertexBuffer() = default;

        /**
         * @brief Create the vertex buffer
         * @param vertexCount Number of vertices
         * @return True if the vertex buffer has been created, false otherwise
         */
        bool create(std::size_t vertexCount);

        /**
         * @brief Get the vertex count of the buffer
         * @return Vertex count of the buffer
         */
        std::size_t getVertexCount() const;

        /**
         * @brief Update the whole buffer from an array of vertices
         * @param vertices Array of vertices
         * @return True if the vertex buffer has been updated, false otherwise
         */
        bool update(const Vertex* vertices);

        /**
         * @brief Update a part of the buffer from an array of vertices
         * @param vertices Array of vertices
         * @param vertexCount Number of vertices to update
         * @param offset Offset of the update
         * @return True if the vertex buffer has been updated, false otherwise
         */
        bool update(const Vertex* vertices, std::size_t vertexCount, std::size_t offset = 0);

        /**
         * @brief Default assignment operator
         * @param vertexBuffer Vertex buffer to copy
         * @return Reference to the vertex buffer
         */
        VertexBuffer& operator=(const VertexBuffer& vertexBuffer) = default;

        /**
         * @brief Swap the content of this vertex buffer with those of another one
         * @param vertexBuffer Vertex buffer to swap with
         */
        void swap(VertexBuffer& vertexBuffer);

        /**
         * @brief Get the native handle of the vertex buffer
         * @return Native handle of the vertex buffer
         */
        unsigned int getNativeHandle() const;

        /**
         * @brief set the primitive type of the vertex buffer
         * @param type Primitive type
         */
        void setPrimitiveType(PrimitiveType type);

        /**
         * @brief Get the primitive type of the vertex buffer
         * @return Primitive type
         */
        PrimitiveType getPrimitiveType() const;

        /**
         * @brief Set the usage of the vertex buffer
         * @param usage Usage
         */
        void setUsage(Usage usage);

        /**
         * @brief Get the usage of the vertex buffer
         * @return Usage
         */
        Usage getUsage() const;

        /**
         * @brief Bind the vertex buffer for rendering
         * @param vertexBuffer Vertex buffer to bind
         */
        static void bind(const VertexBuffer *vertexBuffer);

        /**
         * @brief Check if vertex buffer are supported
         * @return True if vertex buffer are supported, false otherwise
         */
        static bool isAvailable();

    private:
        /**
         * @brief Register a callback to be called when the context is destroyed
         * @param callback Callback to register
         * @param args Arguments to pass to the callback
         */
        static void registerContextDestroyCallback(sf::ContextDestroyCallback callback, void* args);

        sf::VertexBuffer _vertexBuffer; /**< SFML vertex buffer */
        std::size_t _vertexCount; /**< Number of vertices */
        PrimitiveType _primitiveType; /**< Primitive type */
        Usage _usage; /**< Usage of the buffer */
    };
}


#endif //URANUS_VERTEXBUFFER_HPP
