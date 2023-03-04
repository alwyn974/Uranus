//
// Created by nicol on 04/03/2023.
//

#include "VertexArray.hpp"
#include "VertexBuffer.hpp"

std::size_t uranus::VertexArray::getVertexCount() const
{
    return _vertexArray.size();
}

uranus::Vertex &uranus::VertexArray::operator[](std::size_t index)
{
    return _vertexArray[index];
}

const uranus::Vertex &uranus::VertexArray::operator[](std::size_t index) const
{
    return _vertexArray[index];
}

void uranus::VertexArray::clear()
{
    _vertexArray.clear();
}

void uranus::VertexArray::resize(std::size_t vertexCount)
{
    _vertexArray.resize(vertexCount);
}

void uranus::VertexArray::append(const Vertex &vertex)
{
    _vertexArray.push_back(vertex);
}

void uranus::VertexArray::setPrimitiveType(PrimitiveType type)
{
    _primitiveType = type;
}

uranus::FloatRect uranus::VertexArray::getBounds() const
{
    if (_vertexArray.empty())
        return {};
    FloatRect bounds;
    for (const auto &vertex : _vertexArray) {
        bounds.left = std::min(bounds.left, vertex.position.x);
        bounds.top = std::min(bounds.top, vertex.position.y);
        bounds.width = std::max(bounds.width, vertex.position.x);
        bounds.height = std::max(bounds.height, vertex.position.y);
    }
    return bounds;
}

void uranus::VertexArray::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(_vertexArray.data(), _vertexArray.size(), _primitiveType, states);
}
