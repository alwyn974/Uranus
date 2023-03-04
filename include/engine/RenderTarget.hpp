//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_RENDERTARGET_HPP
#define URANUS_RENDERTARGET_HPP

#include "Color.hpp"
#include "GraphicView.hpp"
#include "Vector2.hpp"
#include "Rect.hpp"
#include "VertexBuffer.hpp"
#include "Drawable.hpp"
#include "RenderStates.hpp"

namespace uranus {
    /**
     * @brief RenderTarget class
     */
    class RenderTarget {
    public:
        /**
         * @brief Default destructor
         */
        virtual ~RenderTarget() = default;

        /**
         * @brief Clear the render target with a single color
         * @param color Color to clear with
         */
        void clear(const Color &color);

        /**
         * @brief Change the current active view for a view
         * @param view View to change to
         */
        void setView(const View &view);

        /**
         * @brief Get the current active view
         * @return Current active view
         */
        const View &getView() const;

        /**
         * @brief Get the default view
         * @return Default view
         */
        const View &getDefaultView() const;

        /**
         * @brief Get the viewport of a view
         * @param view View to get the viewport from
         * @return Viewport of the view
         */
        const IntRect &getViewport(const View &view) const;

        /**
         * @brief Convert a point from target coordinates to world coordinates, using the current view
         * @param point Point to convert
         * @return Converted point
         */
        Vector2f mapPixelToCoords(const Vector2i &point) const;

        /**
         * @brief Convert a point from target coordinates to target coordinates
         * @param point Point to convert
         * @param view View to convert from
         * @return Converted point
         */
        Vector2f mapPixelToCoords(const Vector2i &point, const View &view) const;

        /**
         * @brief Convert a point from world coordinates to target coordinates, using the current view
         * @param point Point to convert
         * @return Converted point
         */
        Vector2i mapCoordsToPixel(const Vector2f &point) const;

        /**
         * @brief Convert a point from world coordinates to target coordinates
         * @param point Point to convert
         * @param view View to convert from
         * @return Converted point
         */
        Vector2i mapCoordsToPixel(const Vector2f &point, const View &view) const;

        /**
         * @brief Draw a drawable object
         * @param drawable Drawable object to draw
         * @param states Render states to use
         */
        void draw(const Drawable &drawable, const RenderStates &states = RenderStates::Default);

        /**
         * @brief Draw primitives defined by an array of vertices
         * @param vertices Pointer to the vertices
         * @param type Type of primitives to draw
         * @param states Render states to use
         */
        void draw(const Vertex *vertices, std::size_t vertexCount, PrimitiveType type, const RenderStates &states = RenderStates::Default);

        /**
         * @brief Draw primitives defined by a vertex buffer
         * @param vertexBuffer Vertex buffer to draw
         * @param states Render states to use
         */
        void draw(const VertexBuffer &vertexBuffer, const RenderStates &states = RenderStates::Default);

        /**
         * @brief Draw primitives defined by a vertex buffer
         * @param vertexBuffer Vertex buffer to draw
         * @param firstVertex Index of the first vertex to draw
         * @param vertexCount Number of vertices to draw
         * @param states Render states to use
         */
        void draw(const VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount, const RenderStates &states = RenderStates::Default);

        /**
         * @brief Get the size of the render target
         * @return Size of the render target
         */
        virtual Vector2u getSize() const = 0;

        /**
         * @brief Activate or deactivate the render target for rendering
         * @param active True to activate, false to deactivate
         * @return True if the operation was successful, false otherwise
         */
        virtual bool setActive(bool active = true);

        /**
         * @brief Push the current OpenGL render states
         */
        void pushGLStates();

        /**
         * @brief Pop the current OpenGL render states
         */
        void popGLStates();

        /**
         * @brief Reset the current OpenGL render states
         */
        void resetGLStates();

    protected:
        /**
         * @brief Default constructor
         */
        RenderTarget() = default;

        /**
         * @brief Initialize the render target
         */
        void initialize();

    private:
    };
}


#endif //URANUS_RENDERTARGET_HPP
