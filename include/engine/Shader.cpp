//
// Created by nicol on 03/03/2023.
//

#include "Shader.hpp"

bool uranus::Shader::loadFromFile(const std::string &filename, Type type) {
    return _shader.loadFromFile(filename, static_cast<sf::Shader::Type>(type));
}

bool uranus::Shader::loadFromFile(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) {
    return _shader.loadFromFile(vertexShaderPath, fragmentShaderPath);
}

bool uranus::Shader::loadFromFile(const std::string &vertexShaderFilename, const std::string &geometryShaderFilename, const std::string &fragmentShaderFilename) {
    return _shader.loadFromFile(vertexShaderFilename, geometryShaderFilename, fragmentShaderFilename);
}

bool uranus::Shader::loadFromMemory(const std::string &shader, Type type) {
    return _shader.loadFromMemory(shader, static_cast<sf::Shader::Type>(type));
}

bool uranus::Shader::loadFromMemory(const std::string &vertexShader, const std::string &fragmentShader) {
    return _shader.loadFromMemory(vertexShader, fragmentShader);
}

bool uranus::Shader::loadFromMemory(const std::string &vertexShader, const std::string &geometryShader, const std::string &fragmentShader) {
    return _shader.loadFromMemory(vertexShader, geometryShader, fragmentShader);
}

bool uranus::Shader::loadFromStream(uranus::InputStream &stream, Type type) {
    return _shader.loadFromStream(stream.getInputStream(), static_cast<sf::Shader::Type>(type));
}

bool uranus::Shader::loadFromStream(uranus::InputStream &vertexShaderStream, uranus::InputStream &fragmentShaderStream) {
    return _shader.loadFromStream(vertexShaderStream.getInputStream(), fragmentShaderStream.getInputStream());
}

bool uranus::Shader::loadFromStream(uranus::InputStream &vertexShaderStream, uranus::InputStream &geometryShaderStream, uranus::InputStream &fragmentShaderStream) {
    return _shader.loadFromStream(vertexShaderStream.getInputStream(), geometryShaderStream.getInputStream(), fragmentShaderStream.getInputStream());
}

void uranus::Shader::setUniform(const std::string &name, float x) {
    _shader.setUniform(name, x);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Vec2 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Vec3 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Vec4 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, int x) {
    _shader.setUniform(name, x);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Ivec2 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Ivec3 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Ivec4 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, bool x) {
    _shader.setUniform(name, x);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Bvec2 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Bvec3 &v) {
    _shader.setUniform(name, v);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Bvec4 &v) {
    _shader.setUniform(name, v);
}


void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Mat3 &m) {
    _shader.setUniform(name, m);
}

void uranus::Shader::setUniform(const std::string &name, const sf::Glsl::Mat4 &m) {
    _shader.setUniform(name, m);
}

void uranus::Shader::setUniform(const std::string &name, const std::shared_ptr<Texture> &texture) {
    _shader.setUniform(name, texture->getTexture());
}

void uranus::Shader::setUniform(const std::string &name, CurrentTextureType) {
    _shader.setUniform(name, sf::Shader::CurrentTexture);
}

void uranus::Shader::setUniformArray(const std::string &name, const float *scalarArray, std::size_t length) {
    _shader.setUniformArray(name, scalarArray, length);
}

void uranus::Shader::setUniformArray(const std::string &name, const sf::Glsl::Vec2 *vectorArray, std::size_t length) {
    _shader.setUniformArray(name, vectorArray, length);
}

void uranus::Shader::setUniformArray(const std::string &name, const sf::Glsl::Vec3 *vectorArray, std::size_t length) {
    _shader.setUniformArray(name, vectorArray, length);
}

void uranus::Shader::setUniformArray(const std::string &name, const sf::Glsl::Vec4 *vectorArray, std::size_t length) {
    _shader.setUniformArray(name, vectorArray, length);
}

void uranus::Shader::setUniformArray(const std::string &name, const sf::Glsl::Mat3 *matrixArray, std::size_t length) {
    _shader.setUniformArray(name, matrixArray, length);
}

void uranus::Shader::setUniformArray(const std::string &name, const sf::Glsl::Mat4 *matrixArray, std::size_t length) {
    _shader.setUniformArray(name, matrixArray, length);
}

unsigned int uranus::Shader::getNativeHandle() const {
    return _shader.getNativeHandle();
}

void uranus::Shader::bind(const Shader *shader) {
    sf::Shader::bind(shader ? &shader->_shader : nullptr);
}

bool uranus::Shader::isAvailable() {
    return sf::Shader::isAvailable();
}

bool uranus::Shader::isGeometryAvailable() {
    return sf::Shader::isGeometryAvailable();
}

const sf::Shader &uranus::Shader::getShader() const {
    return _shader;
}




