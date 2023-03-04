/*
** EPITECH PROJECT, 2023
** Shape.hpp
** File description:
** Shape.hpp
*/

#ifndef URANUS_SHAPE_HPP
#define URANUS_SHAPE_HPP

#include "Drawable.hpp"
#include "Transformable.hpp"

namespace uranus {
    /**
     * @brief Shape class
     */
    class Shape : public Drawable, public Transformable {
    public:
        /**
         * @brief Default destructor
         */
        virtual ~Shape() = default;

        /**
         * @brief Set the texture of the shape
         * @param texture Texture of the shape
         * @param resetRect True to reset the texture rect, false otherwise
         */
        void setTexture(const std::shared_ptr<Texture> &texture, bool resetRect = false);

        /**
         * @brief Set the texture rect of the shape
         * @param textureRect Texture rect of the shape
         */
        void setTextureRect(const IntRect &textureRect);

        /**
         * @brief Set the fill color of the shape
         * @brief color Fill color of the shape
         */
        void setFillColor(const Color &color);

        /**
         * @brief Set the outline color of the shape
         * @param color Outline color of the shape
         */
        void setOutlineColor(const Color &color);

        /**
         * @brief Set the outline thickness of the shape
         * @param thickness Outline thickness of the shape
         */
        void setOutlineThickness(float thickness);

        /**
         * @brief Get the texture of the shape
         * @return Texture of the shape
         */
        const std::shared_ptr<Texture> &getTexture() const;

        /**
         * @brief Get the texture rect of the shape
         * @return Texture rect of the shape
         */
        const IntRect &getTextureRect() const;

        /**
         * @brief Get the fill color of the shape
         * @return Fill color of the shape
         */
        const Color &getFillColor() const;

        /**
         * @brief Get the outline color of the shape
         * @return Outline color of the shape
         */
        const Color &getOutlineColor() const;

        /**
         * @brief Get the outline thickness of the shape
         * @return Outline thickness of the shape
         */
        float getOutlineThickness() const;

        /**
         * @brief Get the local bounds of the shape
         * @return Local bounds of the shape
         */
        FloatRect getLocalBounds() const;

        /**
         * @brief Get the global bounds of the shape
         * @return Global bounds of the shape
         */
        FloatRect getGlobalBounds() const;

    protected:
        /**
         * @brief Default constructor
         */
        Shape() = default;

        /**
         * @brief Update the shape
         */
        void update();

    private:
        /**
         * @brief Draw the shape to a render target
         * @param target Render target to draw to
         * @param states Render states to use for drawing
         */
        virtual void draw(RenderTarget &target, RenderStates states) const;

        /**
         * @brief Update the fill colors of the shape
         */
        void updateFillColors();

        /**
         * @brief Update the texture coordinates of the shape
         */
        void updateTexCoords();

        /**
         * @brief Update the outline of the shape
         */
        void updateOutline();

        /**
         * @brief Update the outline colors of the shape
         */
        void updateOutlineColors();

        std::shared_ptr<Texture> _texture /**< Texture of the shape */;
        IntRect _textureRect /**< Texture rect of the shape */;
        Color _fillColor /**< Fill color of the shape */;
        Color _outlineColor /**< Outline color of the shape */;
        float _outlineThickness /**< Outline thickness of the shape */;
    };

}

#endif //URANUS_SHAPE_HPP
