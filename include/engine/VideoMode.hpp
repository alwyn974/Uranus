//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_VIDEOMODE_HPP
#define URANUS_VIDEOMODE_HPP

#include <SFML/Window.hpp>

namespace uranus {
    /**
     * @brief A class that represents a video mode.
     */
    class VideoMode {
    public:
        /**
         * @brief Default constructor
         */
        VideoMode() = default;

        /**
         * @brief Constructor from a width, a height and a bit per pixel
         * @param width Width of the video mode
         * @param height Height of the video mode
         * @param bpp Bits per pixel of the video mode
         */
        VideoMode(unsigned int width, unsigned int height, unsigned int bpp);

        /**
         * @brief Constructor from a sf::VideoMode
         */
        explicit VideoMode(const sf::VideoMode& mode);

        /**
         * @brief Get the current desktop video mode
         * @return Current desktop video mode
         */
        static VideoMode getDesktopMode();

        /**
         * @brief Retrieve all the video modes supported in fullscreen mode
         * @return All the video modes supported in fullscreen mode
         */
        static const std::vector<VideoMode> getFullscreenModes();

        /**
         * @brief Get the width of the video mode
         * @return Width of the video mode
         */
        unsigned int getWidth() const;

        /**
         * @brief Get the height of the video mode
         * @return Height of the video mode
         */
        unsigned int getHeight() const;

        /**
         * @brief Get the bits per pixel of the video mode
         * @return Bits per pixel of the video mode
         */
        unsigned int getBitsPerPixel() const;

        /**
         * @brief Get the SFML video mode
         * @return SFML video mode
         */
        sf::VideoMode getVideoMode() const;
    private:
        sf::VideoMode _mode /**< SFML video mode */;
    };
}


#endif //URANUS_VIDEOMODE_HPP
