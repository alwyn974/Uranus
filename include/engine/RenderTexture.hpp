//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_RENDERTEXTURE_HPP
#define URANUS_RENDERTEXTURE_HPP

#include "RenderTarget.hpp"
#include "Texture.hpp"

namespace uranus {
    /**
     * @brief RenderTexture class
     */
    class RenderTexture : public RenderTarget {
    public:
        /**
         * @brief Default constructor
         */
        RenderTexture() = default;

        /**
         * @brief Create a render texture
         */
         bool create(unsigned int width, unsigned int height, const sf::ContextSettings &settings = sf::ContextSettings());

         /**
          * @brief Get the maximum anti-aliasing level supported by the system
          * @return Maximum anti-aliasing level
          */
         static unsigned int getMaximumAntialiasingLevel();

        /**
         * @brief Enable or disable texture smoothing
         * @param smooth True to enable smoothing, false to disable it
         */
        void setSmooth(bool smooth);

        /**
         * @brief Tell whether the texture is smoothed or not
         * @return True if the texture is smoothed, false if it is not
         */
        bool isSmooth() const;

        /**
         * @brief Enable or disable texture repeating
         * @param repeated True to enable repeating, false to disable it
         */
        void setRepeated(bool repeated);

        /**
         * @brief Tell whether the texture is repeated or not
         * @return True if the texture is repeated, false if it is not
         */
        bool isRepeated() const;

        /**
         * @brief Generate a mipmap for the texture
         * @return True if the mipmap was generated, false if it was not
         */
        bool generateMipmap();

        /**
         * @brief Activate or deactivate the render texture for rendering
         * @param active True to activate, false to deactivate
         * @return True if operation was successful, false otherwise
         */
        bool setActive(bool active = true) const;

        /**
         * @brief Update the contents of the target texture
         */
        void display();

        /**
         * @brief Get the size of the render texture
         * @return Size of the render texture
         */
        virtual Vector2u getSize() const;

        /**
         * @brief Get the texture of the render texture
         * @return Texture of the render texture
         */
        const std::shared_ptr<Texture> &getTexture() const;

    private:
        sf::RenderTexture _renderTexture; /**< SFML RenderTexture */
        std::shared_ptr<Texture> _texture; /**< Texture of the render texture */
        Vector2u _size; /**< Size of the render texture */
        bool isSmoothed; /**< Is the render texture smoothed */
        bool isOnRepeat; /**< Is the render texture repeated */

    };
}

#endif //URANUS_RENDERTEXTURE_HPP
