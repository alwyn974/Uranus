//
// Created by nicol on 04/03/2023.
//

#include "VideoMode.hpp"

uranus::VideoMode::VideoMode(unsigned int width, unsigned int height, unsigned int bitsPerPixel) : _mode(width, height, bitsPerPixel)
{
}

uranus::VideoMode::VideoMode(const sf::VideoMode& mode) : _mode(mode)
{
}

uranus::VideoMode uranus::VideoMode::getDesktopMode() {
    return VideoMode(sf::VideoMode::getDesktopMode());
}

const std::vector<uranus::VideoMode> uranus::VideoMode::getFullscreenModes() {
    std::vector<uranus::VideoMode> modes;
    for (const auto& mode : sf::VideoMode::getFullscreenModes()) {
        modes.emplace_back(mode);
    }
    return modes;
}

sf::VideoMode uranus::VideoMode::getVideoMode() const {
    return _mode;
}