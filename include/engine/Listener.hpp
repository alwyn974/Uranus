//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_LISTENER_HPP
#define URANUS_LISTENER_HPP

#include "SFML/Audio.hpp"
#include "Vector3.hpp"

namespace uranus {
    /**
     * @brief Listener class
     */
    class Listener {
    public:
        /**
         * @brief Change the global volume of all sounds and musics
         * @param volume Volume to set
         */
        static void setGlobalVolume(float volume);

        /**
         * @brief Get the global volume of all sounds and musics
         * @return Global volume
         */
        static float getGlobalVolume();

        /**
         * @brief Set the position of the listener in the scene
         * @param position Position to set
         */
        static void setPosition(const Vector3f &position);

        /**
         * @brief Set the position of the listener in the scene
         * @param x x coordinate of the position
         * @param y y coordinate of the position
         * @param z z coordinate of the position
         */
        static void setPosition(float x, float y, float z);

        /**
         * @brief Get the position of the listener in the scene
         * @return Position of the listener
         */
        static Vector3f getPosition();

        /**
         * @brief Set the direction of the listener in the scene
         * @param direction Direction to set
         */
        static void setDirection(const Vector3f &direction);

        /**
         * @brief Set the direction of the listener in the scene
         * @param x x coordinate of the direction
         * @param y y coordinate of the direction
         * @param z z coordinate of the direction
         */
        static void setDirection(float x, float y, float z);

        /**
         * @brief Get the direction of the listener in the scene
         * @return Direction of the listener
         */
        static Vector3f getDirection();

        /**
         * @brief Set the up vector of the listener in the scene
         * @param upVector Up vector to set
         */
        static void setUpVector(const Vector3f &upVector);

        /**
         * @brief Set the up vector of the listener in the scene
         * @param x x coordinate of the up vector
         * @param y y coordinate of the up vector
         * @param z z coordinate of the up vector
         */
        static void setUpVector(float x, float y, float z);

        /**
         * @brief Get the up vector of the listener in the scene
         * @return Up vector of the listener
         */
        static Vector3f getUpVector();
    };
}


#endif //URANUS_LISTENER_HPP
