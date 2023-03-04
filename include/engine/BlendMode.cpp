//
// Created by nicol on 03/03/2023.
//

#include "BlendMode.hpp"

uranus::BlendMode::BlendMode(uranus::BlendMode::Factor srcFactor, uranus::BlendMode::Factor dstFactor, uranus::BlendMode::Equation equation) :
sf::BlendMode(static_cast<sf::BlendMode::Factor>(srcFactor), static_cast<sf::BlendMode::Factor>(dstFactor), static_cast<sf::BlendMode::Equation>(equation))
{

}

uranus::BlendMode::BlendMode(uranus::BlendMode::Factor colorSrcFactor, uranus::BlendMode::Factor colorDstFactor, uranus::BlendMode::Equation colorBlendEquation, uranus::BlendMode::Factor alphaSrcFactor, uranus::BlendMode::Factor alphaDstFactor, uranus::BlendMode::Equation alphaBlendEquation) :
sf::BlendMode(static_cast<sf::BlendMode::Factor>(colorSrcFactor), static_cast<sf::BlendMode::Factor>(colorDstFactor), static_cast<sf::BlendMode::Equation>(colorBlendEquation), static_cast<sf::BlendMode::Factor>(alphaSrcFactor), static_cast<sf::BlendMode::Factor>(alphaDstFactor), static_cast<sf::BlendMode::Equation>(alphaBlendEquation))
{

}

