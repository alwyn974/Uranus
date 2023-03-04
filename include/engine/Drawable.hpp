/*
** EPITECH PROJECT, 2023
** Drawable.hpp
** File description:
** Drawable.hpp
*/


#ifndef URANUS_DRAWABLE_HPP
#define URANUS_DRAWABLE_HPP

#include "RenderTarget.hpp"

namespace uranus {
    class Drawable {
    public:
        /**
         * @brief Default destructor
         */
        virtual ~Drawable() = default;
    protected:
        /**
         * @brief Draw the object to a render target
         * @param target Render target to draw to
         * @param states Render states to use for drawing
         */
        virtual void draw(RenderTarget &target, RenderStates states) const = 0;
    };
}


#endif //URANUS_DRAWABLE_HPP
