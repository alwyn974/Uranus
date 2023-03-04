//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_SOUNDSOURCE_HPP
#define URANUS_SOUNDSOURCE_HPP

#include "SFML/Audio.hpp"
#include "Vector3.hpp"

namespace uranus {
    /**
     * @brief SoundSource class, base class for all sound sources.
     */
    class SoundSource {
    public:
        enum Status {
            Playing,
            Paused,
            Stopped
        };

        /**
         * @brief Default copy constructor.
         */
        SoundSource(const SoundSource &copy) = default;

        /**
         * @brief Default destructor.
         */
        virtual ~SoundSource() = default;

        /**
         * @brief Set the pitch of the sound.
         * @param pitch Pitch to set.
         */
        void setPitch(float pitch);

        /**
        * @brief Set the volume of the sound
        * @param volume Volume of the sound
        */
        void setVolume(float volume);

        /**
         * @brief Set the 3D position of the sound in the audio scene
         * @param position Position of the sound
         */
        void setPosition(float x, float y, float z);

        /**
         * @brief Set the 3D position of the sound in the audio scene
         * @param position Position of the sound
         */
        void setPosition(const Vector3f &position);

        /**
         * @brief Make the sound's position relative to the listener or absolute
         * @param relative True to set the position relative, false to set it absolute
         */
        void setRelativeToListener(bool relative);

        /**
         * @brief Set the minimum distance of the sound
         * @param distance Minimum distance of the sound
         */
        void setMinDistance(float distance);

        /**
         * @brief Set the attenuation factor of the sound
         * @param attenuation Attenuation factor of the sound
         */
        void setAttenuation(float attenuation);

        /**
         * @brief Get the pitch of the sound
         * @return Pitch of the sound
         */
        float getPitch() const;

        /**
         * @brief Get the volume of the sound
         * @return Volume of the sound
         */
        float getVolume() const;

        /**
         * @brief Get the 3D position of the sound in the audio scene
         * @return Position of the sound
         */
        const Vector3f &getPosition() const;

        /**
         * @brief Tell whether the sound's position is relative to the listener or is absolute
         * @return True if the position is relative, false if it's absolute
         */
        bool isRelativeToListener() const;

        /**
         * @brief Get the minimum distance of the sound
         * @return Minimum distance of the sound
         */
        float getMinDistance() const;

        /**
         * @brief Get the attenuation factor of the sound
         * @return Attenuation factor of the sound
         */
        float getAttenuation() const;

        /**
         * @brief Play the sound
         */
        void play();

        /**
         * @brief Pause the sound
         */
        void pause();

        /**
         * @brief Stop the sound
         */
        void stop();

        /**
         * @brief Get the current status of the sound (stopped, paused, playing)
         * @return Current status of the sound
         */
        virtual Status getStatus() const;

        /**
         * @brief Default assignment operator.
         * @param other Other SoundSource to copy.
         * @return Reference to this SoundSource.
         */
        SoundSource &operator=(const SoundSource &other) = default;

    protected:
        /**
         * @brief Default constructor.
         */
        SoundSource() = default;
    };
}


#endif //URANUS_SOUNDSOURCE_HPP
