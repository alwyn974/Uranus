//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_BLENDMODE_HPP
#define URANUS_BLENDMODE_HPP

#include <SFML/Graphics.hpp>

namespace uranus {
    /**
     * @brief Blend mode class
     */
    class BlendMode : public sf::BlendMode {
    public:
        enum Factor {
            ZERO, /// 0
            ONE, /// 1
            SRC_COLOR, /// source color
            ONE_MINUS_SRC_COLOR, /// 1 - source color
            DST_COLOR, /// destination color
            ONE_MINUS_DST_COLOR, /// 1 - destination color
            SRC_ALPHA, /// source alpha
            ONE_MINUS_SRC_ALPHA, /// 1 - source alpha
            DST_ALPHA, /// destination alpha
            ONE_MINUS_DST_ALPHA, /// 1 - destination alpha
        };

        enum Equation {
            ADD, /// source + destination
            SUBTRACT, /// source - destination
            REVERSE_SUBTRACT, /// destination - source
        };

        /**
         * @brief Default constructor
         */
        BlendMode() = default;

        /**
         * @brief Constructor from the given parameters
         * @param srcFactor Specifies how to compute the source factor for the color and alpha channels
         * @param dstFactor Specifies how to compute the destination factor for the color and alpha channels
         * @param equation Specifies how to combine the source and destination factors for the color and alpha channels
         */
        BlendMode(Factor srcFactor, Factor dstFactor, Equation equation = ADD);

        /**
         * @brief Constructor from the given parameters
         * @param srcFactor Specifies how to compute the source factor for the color channels
         * @param dstFactor Specifies how to compute the destination factor for the color channels
         * @param srcAlphaFactor Specifies how to compute the source factor for the alpha channel
         * @param dstAlphaFactor Specifies how to compute the destination factor for the alpha channel
         * @param equation Specifies how to combine the source and destination factors for the color channels
         * @param alphaEquation Specifies how to combine the source and destination factors for the alpha channel
         */
        BlendMode(Factor srcFactor, Factor dstFactor, Factor srcAlphaFactor, Factor dstAlphaFactor, Equation equation = ADD, Equation alphaEquation = ADD);

        /**
         * @brief Default destructor
         */
        ~BlendMode() = default;
    };
}


#endif //URANUS_BLENDMODE_HPP
