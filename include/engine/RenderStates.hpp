//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_RENDERSTATES_HPP
#define URANUS_RENDERSTATES_HPP

#include <SFML/Graphics.hpp>
#include "Texture.hpp"
#include "Transform.hpp"
#include "BlendMode.hpp"
#include "Shader.hpp"

namespace uranus {
    /**
     * @brief Render states class that inherits from RenderStates
     */
    class RenderStates {
    public:
        /**
         * @brief Default constructor
         */
        RenderStates() = default;

        /**
         * @brief Constructor from a BlendMode
         * @param blendMode BlendMode to construct from
         */
        RenderStates(const BlendMode &blendMode);

        /**
         * @brief Constructor from a Transform
         * @param transform Transform to construct from
         */
        RenderStates(const Transform &transform);

        /**
         * @brief Constructor from a Texture
         * @param texture Texture to construct from
         */
        RenderStates(const Texture &texture);

        /**
         * @brief Constructor from a Shader
         * @param shader Shader to construct from
         */
        RenderStates(const Shader &shader);

        /**
         * @brief Constructor from a BlendMode, a Transform, a Texture and a Shader
         * @param blendMode BlendMode to construct from
         * @param transform Transform to construct from
         * @param texture Texture to construct from
         * @param shader Shader to construct from
         */
        RenderStates(const BlendMode &blendMode, const Transform &transform, const Texture &texture, const Shader &shader);

        /**
         * @brief Default destructor
         */
        ~RenderStates() = default;

        static const RenderStates Default; /**< Default render states */
    };
}


#endif //URANUS_RENDERSTATES_HPP
