//
// Created by nicol on 04/03/2023.
//

#include "VertexBuffer.hpp"

uranus::VertexBuffer::VertexBuffer(PrimitiveType type) : _vertexBuffer(static_cast<sf::PrimitiveType>(type))
{
}

uranus::VertexBuffer::VertexBuffer(Usage usage) : _vertexBuffer(static_cast<sf::VertexBuffer::Usage>(usage))
{
}

uranus::VertexBuffer::VertexBuffer(PrimitiveType type, Usage usage) : _vertexBuffer(static_cast<sf::PrimitiveType>(type), static_cast<sf::VertexBuffer::Usage>(usage))
{
}

bool uranus::VertexBuffer::create(std::size_t vertexCount) {
   return _vertexBuffer.create(vertexCount);
}

std::size_t uranus::VertexBuffer::getVertexCount() const {
   return _vertexBuffer.getVertexCount();
}

bool uranus::VertexBuffer::update(const Vertex *vertices) {
   return _vertexBuffer.update(vertices);
}

bool uranus::VertexBuffer::update(const Vertex *vertices, std::size_t vertexCount, std::size_t offset) {
   return _vertexBuffer.update(vertices, vertexCount, offset);
}

void uranus::VertexBuffer::swap(VertexBuffer &vertexBuffer) {
    _vertexBuffer.swap(vertexBuffer._vertexBuffer);
}

unsigned int uranus::VertexBuffer::getNativeHandle() const {
    return _vertexBuffer.getNativeHandle();
}

void uranus::VertexBuffer::setPrimitiveType(PrimitiveType type) {
    _vertexBuffer.setPrimitiveType(static_cast<sf::PrimitiveType>(type));
}

uranus::PrimitiveType uranus::VertexBuffer::getPrimitiveType() const {
    return static_cast<PrimitiveType>(_vertexBuffer.getPrimitiveType());
}

void uranus::VertexBuffer::setUsage(Usage usage) {
    _vertexBuffer.setUsage(static_cast<sf::VertexBuffer::Usage>(usage));
}

uranus::VertexBuffer::Usage uranus::VertexBuffer::getUsage() const {
    return static_cast<Usage>(_vertexBuffer.getUsage());
}

void uranus::VertexBuffer::bind(const VertexBuffer *vertexBuffer) {
    sf::VertexBuffer::bind(vertexBuffer ? &vertexBuffer->_vertexBuffer : nullptr);
}

bool uranus::VertexBuffer::isAvailable() {
    return sf::VertexBuffer::isAvailable();
}

void uranus::VertexBuffer::draw(RenderTarget &target, RenderStates states) const {
    target.draw(_vertexBuffer, states);
}

