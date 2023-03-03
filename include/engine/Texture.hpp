/*
** EPITECH PROJECT, 2023
** Texture.hpp
** File description:
** Texture.hpp
*/

#ifndef URANUS_TEXTURE_HPP
#define URANUS_TEXTURE_HPP

#include "Dependencies.hpp"
#include "Vector2.hpp"

namespace uranus {
    /**
     * @brief Enum for the coordinate type
     */
    enum CoordinateType {
        PIXELS,
        NORMALIZED
    };

/**
 * @brief Texture class
 */
class Texture {
public:
    /**
     * @brief Default constructor
     */
    explicit Texture() = default;

    /**
     * @brief Constructor from a path
     * @param path Path of the texture
     */
    explicit Texture(const std::string &path);

    /**
     * @brief Copy constructor
     * @param texture to copy
     */
    Texture(const Texture &texture) = default;

    /**
     * @brief Default destructor
     */
    ~Texture() = default;

    /**
     * @brief Create the texture
     * @param width Width of the texture
     * @param height Height of the texture
     * @return True if the texture is created, false otherwise
     */
    bool create(unsigned int width, unsigned int height);

    /**
     * @brief Load the texture from a file
     * @param path Path of the texture
     * @return True if the texture is loaded, false otherwise
     */
    bool loadFromFile(const std::string &path);

    /**
     * @brief Load the texture from a memory
     * @param data Data of the texture
     * @param size Size of the data
     * @return True if the texture is loaded, false otherwise
     */
    bool loadFromMemory(const void *data, std::size_t size);

    /**
     * @brief Load the texture from a stream
     * @param stream Stream of the texture
     * @return True if the texture is loaded, false otherwise
     */
    bool loadFromStream(std::istream &stream);

    /**
     * @brief Load the texture from an image
     * @param image Image of the texture
     * @return True if the texture is loaded, false otherwise
     */
    bool loadFromImage(const sf::Image &image);

    /**
     * @brief Get the size of the texture
     * @return Size of the texture
     */
    Vector2u getSize() const;

    /**
     * @brief Copy the texture to an image
     * @return Image of the texture
     */
    sf::Image copyToImage() const;

    /**
     * @brief Update the texture
     * @param pixels Pixels of the texture
     */
    void update(const sf::Uint8 *pixels);

    /**
     * @brief Update the texture
     * @param pixels Pixels of the texture
     * @param width Width of the texture
     * @param height Height of the texture
     * @param x X position of the texture
     * @param y Y position of the texture
     */
    void update(const sf::Uint8 *pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

    /**
     * @brief Update the texture
     * @param texture Texture to update
     */
    void update(const Texture &texture);

    /**
     * @brief Update the texture
     * @param texture Texture to update
     * @param x X position of the texture
     * @param y Y position of the texture
     */
    void update(const Texture &texture, unsigned int x, unsigned int y);

    /**
     * @brief Update the texture
     * @param image Image to update
     */
    void update(const sf::Image &image);

    /**
     * @brief Update the texture
     * @param image Image to update
     * @param x X position of the texture
     * @param y Y position of the texture
     */
    void update(const sf::Image &image, unsigned int x, unsigned int y);

    /**
     * @brief Update the texture
     * @param window Window to update
     */
    void update(const sf::Window &window);


    /**
     * @brief Update the texture
     * @param window Window to update
     * @param x X position of the texture
     * @param y Y position of the texture
     */
    void update(const sf::Window &window, unsigned int x, unsigned int y);

    /**
     * @brief Enable or disable the smooth filter
     * @param smooth True to enable the smooth filter, false otherwise
     */
    void setSmooth(bool smooth);

    /**
     * @brief Check if the smooth filter is enabled
     * @return True if the smooth filter is enabled, false otherwise
     */
    bool isSmooth() const;

    /**
     * @brief Enable or disable the repeated texture
     * @param repeated True to enable the repeated texture, false otherwise
     */
    void setRepeated(bool repeated);

    /**
     * @brief Check if the repeated texture is enabled
     * @return True if the repeated texture is enabled, false otherwise
     */
    bool isRepeated() const;

    /**
     * @brief Enable or disable the sRGB conversion
     * @param srgb True to enable the sRGB conversion, false otherwise
     */
    void setSrgb(bool srgb);

    /**
     * @brief Check if the sRGB conversion is enabled
     * @return True if the sRGB conversion is enabled, false otherwise
     */
    bool isSrgb() const;

    /**
     * @brief Generate the mipmap
     * @return True if the mipmap is generated, false otherwise
     */
    bool generateMipmap() const;

    /**
     * @brief Overload of the assignment operator
     * @param texture Texture to assign
     * @return Reference to the texture
     */
    Texture &operator=(const Texture &texture) = default;

    /**
     * @brief Swap the texture content of this texture with those of another texture
     * @param texture Texture to swap
     */
    void swap(Texture &texture);

    /**
     * @brief Get the native handle of the texture
     * @return Native handle of the texture
     */
    unsigned int getNativeHandle() const;

    /**
     * @brief Bind the texture
     * @param texture Texture to bind
     * @param type Type of the texture
     */
    static void bind(const Texture texture, CoordinateType type = CoordinateType::NORMALIZED);

    /**
     * @brief Get the maximum size of the texture
     * @return Maximum size of the texture
     */
    static unsigned int getMaximumSize();
private:
    /**
     * @brief Register a context destroy callback
     * @param callback Callback to register
     * @param arg Argument of the callback
     */
    static void registerContextDestroyCallback(sf::ContextDestroyCallback callback, void *arg);

    sf::Texture _texture; /**< SFML texture */
};

}

#endif //URANUS_TEXTURE_HPP
