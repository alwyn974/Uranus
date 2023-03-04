//
// Created by nicol on 02/03/2023.
//

#ifndef URANUS_IMAGE_HPP
#define URANUS_IMAGE_HPP

#include "Color.hpp"
#include "Vector2.hpp"
#include "InputStream.hpp"
#include "Rect.hpp"

namespace uranus {
    /**
     * @brief Image class
     */
    class Image {
    public:
        /**
         * @brief Default constructor
         */
        Image() = default;

        /**
         * @brief Constructor from a sf::Image
         * @param image Image to copy
         */
        Image(const sf::Image &image);

        /**
         * @brief Default destructor
         */
        ~Image() = default;

        /**
         * @brief Create the image
         * @param width Width of the image
         * @param height Height of the image
         * @param color Color of the image
         */
        void create(unsigned int width, unsigned int height, const Color &color = Color::TRANSPARENT);

        /**
         * @brief Create the image from an array of pixels
         * @param width Width of the image
         * @param height Height of the image
         * @param pixels Array of pixels
         */
         void create(unsigned int width, unsigned int height, const unsigned char *pixels);

        /**
         * @brief Load the image from a file
         * @param path Path of the image
         * @return True if the image is loaded, false otherwise
         */
         bool loadFromFile(const std::string &path);

        /**
         * @brief Load the image from a memory
         * @param data Data of the image
         * @param size Size of the data
         * @return True if the image is loaded, false otherwise
         */
        bool loadFromMemory(const void *data, std::size_t size);

        /**
         * @brief Load the image from a stream
         * @param stream Stream of the image
         * @return True if the image is loaded, false otherwise
         */
        bool loadFromStream(InputStream &stream);

        /**
         * @brief Save the image to a file
         * @param path Path of the image
         * @return True if the image is saved, false otherwise
         */
        bool saveToFile(const std::string &path) const;

        /**
         * @brief Get the size of the image
         * @return Size of the image
         */
        Vector2u getSize() const;

        /**
         * @brief Create a transparency mask from a specified color-key
         * @param color Color of the mask
         * @param alpha Alpha of the mask
         */
        void createMaskFromColor(const Color &color, unsigned char alpha = 0);

        /**
         * @brief Copy pixels from another image onto this one
         * @param image Image to copy
         * @param destX X position of the destination
         * @param destY Y position of the destination
         * @param sourceRect Rectangle of the source
         * @param applyAlpha Apply the alpha of the source
         */
        void copy(const Image &image, unsigned int destX, unsigned int destY, const IntRect &sourceRect, bool applyAlpha = false);

        /**
         * @brief Set a pixel of the image
         * @param x X position of the pixel
         * @param y Y position of the pixel
         * @param color Color of the pixel
         */
        void setPixel(unsigned int x, unsigned int y, const Color &color);

        /**
         * @brief Get a pixel of the image
         * @param x X position of the pixel
         * @param y Y position of the pixel
         * @return Color of the pixel
         */
        Color getPixel(unsigned int x, unsigned int y) const;

        /**
         * @brief Get the array of pixels of the image
         * @return Array of pixels of the image
         */
        const unsigned char *getPixelsPtr() const;

        /**
         * @brief Flip the image horizontally
         */
        void flipHorizontally();

        /**
         * @brief Flip the image vertically
         */
        void flipVertically();

        /**
         * @brief Get the SFML image
         * @return SFML image
         */
        const sf::Image &getImage() const;
    private:
        sf::Image _image; /**< SFML image */
    };
}



#endif //URANUS_IMAGE_HPP
