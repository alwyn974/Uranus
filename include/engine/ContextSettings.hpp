//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_CONTEXTSETTINGS_HPP
#define URANUS_CONTEXTSETTINGS_HPP

namespace uranus {
    /**
     * @brief Settings for the context
     */
    struct ContextSettings {
        enum Attribute {
            DEFAULT = 0, /**< Default attribute */
            CORE = 1 << 0, /**< Core attribute */
            DEBUG = 1 << 1, /**< Debug attribute */
        };

        explicit ContextSettings(unsigned int depth = 0, unsigned int stencil = 0, unsigned int antialiasing = 0, unsigned int majorVersion = 1, unsigned int minorVersion = 0, unsigned int attributeFlags = DEFAULT, bool sRgbCapable = false):
                depthBits(depth), stencilBits(stencil), antialiasingLevel(antialiasing), majorVersion(majorVersion), minorVersion(minorVersion), attributeFlags(attributeFlags), sRgbCapable(sRgbCapable) {}

        unsigned int depthBits; /**< Depth buffer bits */
        unsigned int stencilBits; /**< Stencil buffer bits */
        unsigned int antialiasingLevel; /**< Antialiasing level */
        unsigned int majorVersion; /**< Major version */
        unsigned int minorVersion; /**< Minor version */
        unsigned int attributeFlags; /**< Attribute */
        bool sRgbCapable; /**< sRGB capable */
    };
}


#endif //URANUS_CONTEXTSETTINGS_HPP
