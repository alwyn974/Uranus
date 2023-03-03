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
         * @param X X coordinate of the position
         * @param Y Y coordinate of the position
         * @param Z Z coordinate of the position
         */
        static void setPosition(float X, float Y, float Z);

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
         * @param X X coordinate of the direction
         * @param Y Y coordinate of the direction
         * @param Z Z coordinate of the direction
         */
        static void setDirection(float X, float Y, float Z);

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
         * @param X X coordinate of the up vector
         * @param Y Y coordinate of the up vector
         * @param Z Z coordinate of the up vector
         */
        static void setUpVector(float X, float Y, float Z);

        /**
         * @brief Get the up vector of the listener in the scene
         * @return Up vector of the listener
         */
        static Vector3f getUpVector();
    };
}


#endif //URANUS_LISTENER_HPP
