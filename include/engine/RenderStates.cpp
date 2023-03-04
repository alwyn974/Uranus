//
// Created by nicol on 03/03/2023.
//

#include "RenderStates.hpp"

uranus::RenderStates::RenderStates(const BlendMode &blendMode) : _renderStates(blendMode)
{
}

//TODO: Check if this is correct
uranus::RenderStates::RenderStates(const std::shared_ptr<Texture> &texture) : _renderStates(&texture->getTexture())
{
}

uranus::RenderStates::RenderStates(const Transform &transform) : _renderStates(transform)
{
}

//TODO: Check if this is correct
uranus::RenderStates::RenderStates(const Shader &shader) : _renderStates(&shader.getShader())
{
}