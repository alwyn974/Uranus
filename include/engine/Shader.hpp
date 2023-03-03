//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_SHADER_HPP
#define URANUS_SHADER_HPP

#include <SFML/Graphics.hpp>
#include "InputStream.hpp"
#include "Texture.hpp"

namespace uranus {
    /**
     * @brief Shader class
     */
    class Shader {
    public:
        struct CurrentTextureType {};

        /**
         * @brief Shader type
         */
        enum Type {
            Vertex,     /// Vertex shader
            Geometry,   /// Geometry shader
            Fragment    /// Fragment shader
        };

        /**
         * @brief Default constructor
         */
        Shader() = default;

        /**
         * @brief Default destructor
         */
        ~Shader() = default;

        /**
         * @brief Load the shader from a file
         * @param filename Filename of the shader
         * @param type Type of the shader
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromFile(const std::string &filename, Type type);

        /**
         * @brief Load the shader from a file
         * @param vertexShaderFilename Filename of the vertex shader
         * @param fragmentShaderFilename Filename of the fragment shader
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromFile(const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename);

        /**
         * @brief Load the shader from a file
         * @param vertexShaderFilename Filename of the vertex shader
         * @param geometryShaderFilename Filename of the geometry shader
         * @param fragmentShaderFilename Filename of the fragment shader
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromFile(const std::string &vertexShaderFilename, const std::string &geometryShaderFilename, const std::string &fragmentShaderFilename);

        /**
         * @brief Load the shader from memory
         * @param shader Shader to load
         * @param type Type of the shader
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromMemory(const std::string &shader, Type type);

        /**
         * @brief Load the shader from memory
         * @param vertexShader Vertex shader to load
         * @param fragmentShader Fragment shader to load
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromMemory(const std::string &vertexShader, const std::string &fragmentShader);

        /**
         * @brief Load the shader from memory
         * @param vertexShader Vertex shader to load
         * @param geometryShader Geometry shader to load
         * @param fragmentShader Fragment shader to load
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromMemory(const std::string &vertexShader, const std::string &geometryShader, const std::string &fragmentShader);

        /**
         * @brief Load the shader from a stream
         * @param stream Stream to load from
         * @param type Type of the shader
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromStream(InputStream &stream, Type type);

        /**
         * @brief Load the shader from a stream
         * @param vertexShaderStream Stream to load the vertex shader from
         * @param fragmentShaderStream Stream to load the fragment shader from
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromStream(InputStream &vertexShaderStream, InputStream &fragmentShaderStream);

        /**
         * @brief Load the shader from a stream
         * @param vertexShaderStream Stream to load the vertex shader from
         * @param geometryShaderStream Stream to load the geometry shader from
         * @param fragmentShaderStream Stream to load the fragment shader from
         * @return True if the shader was loaded successfully, false otherwise
         */
        bool loadFromStream(InputStream &vertexShaderStream, InputStream &geometryShaderStream, InputStream &fragmentShaderStream);

        /**
         * @brief Specify value for float uniform
         * @param name Name of the uniform variable
         * @param x Value of the uniform
         */
        void setUniform(const std::string &name, float x);

        /**
         * @brief Specify value for vec2 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Vec2 &v);

        /**
         * @brief Specify value for vec3 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Vec3 &v);

        /**
         * @brief Specify value for vec4 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Vec4 &v);

        /**
         * @brief Specify value for int uniform
         * @param name Name of the uniform variable
         * @param x Value of the uniform
         */
        void setUniform(const std::string &name, int x);

        /**
         * @brief Specify value for ivec2 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Ivec2 &v);

        /**
         * @brief Specify value for ivec3 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Ivec3 &v);

        /**
         * @brief Specify value for ivec4 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Ivec4 &v);

        /**
         * @brief Specify value for bool uniform
         * @param name Name of the uniform variable
         * @param x Value of the uniform
         */
        void setUniform(const std::string &name, bool x);

        /**
         * @brief Specify value for bvec2 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Bvec2 &v);

        /**
         * @brief Specify value for bvec3 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Bvec3 &v);

        /**
         * @brief Specify value for bvec4 uniform
         * @param name Name of the uniform variable
         * @param v Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Bvec4 &v);

        /**
         * @brief Specify value for mat3 uniform
         * @param name Name of the uniform variable
         * @param m Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Mat3 &m);

        /**
         * @brief Specify value for mat4 uniform
         * @param name Name of the uniform variable
         * @param m Value of the uniform
         */
        void setUniform(const std::string &name, const sf::Glsl::Mat4 &m);

        /**
         * @brief Specify value for sampler2D uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniform(const std::string &name, const std::shared_ptr<Texture> &texture);

        /**
         * @brief Specify value for sampler2D uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniform(const std::string &name, CurrentTextureType);

        /**
         * @brief Specify value for float[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const float* scalarArray, std::size_t length);

        /**
         * @brief Specify value for vec2[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const sf::Glsl::Vec2* vectorArray, std::size_t length);

        /**
         * @brief Specify value for vec3[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const sf::Glsl::Vec3* vectorArray, std::size_t length);

        /**
         * @brief Specify value for vec4[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const sf::Glsl::Vec4* vectorArray, std::size_t length);

        /**
         * @brief Specify value for mat3[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const sf::Glsl::Mat3* matrixArray, std::size_t length);

        /**
         * @brief Specify value for mat4[] uniform
         * @param name Name of the uniform variable
         * @param texture Texture to bind
         */
        void setUniformArray(const std::string& name, const sf::Glsl::Mat4* matrixArray, std::size_t length);

        /**
         * @brief Get the native handle of the shader
         * @return Native handle of the shader
         */
        unsigned int getNativeHandle() const;

        /**
         * @brief Bind the shader for rendering
         * @param shader Shader to bind
         */
        static void bind(const Shader* shader);

        /**
         * @brief Tell whether shaders are available on the system
         * @return True if shaders are available, false otherwise
         */
        static bool isAvailable();

        /**
         * @brief Tell whether geometry shaders are available on the system
         * @return True if geometry shaders are available, false otherwise
         */
        static bool isGeometryAvailable();

        static CurrentTextureType CurrentTexture; /**< Represents the texture of the object being drawn */
    private:
        /**
         * @brief Register a callback to be called when the context is destroyed
         * @param callback Callback to register
         * @param args Arguments to pass to the callback
         */
        static void registerContextDestroyCallback(sf::ContextDestroyCallback callback, void* args);

        sf::Shader _shader; /**< SFML shader */
    };
}


#endif //URANUS_SHADER_HPP
