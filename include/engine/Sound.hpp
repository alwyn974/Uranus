//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_SOUND_HPP
#define URANUS_SOUND_HPP

#include "SoundSource.hpp"
#include "Time.hpp"
#include "SoundBuffer.hpp"

namespace uranus {
    /**
     * @brief Sound class
     */
    class Sound : public SoundSource {
        /**
         * @brief Default constructor.
         */
        Sound() = default;

        /**
         * @brief Construct a sound from a sound buffer.
         */
         explicit Sound(const SoundBuffer &buffer);

        /**
         * @brief Default copy constructor.
         */
        Sound(const Sound &copy) = default;

        /**
         * @brief Default destructor.
         */
        ~Sound();

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
         * @brief Set the sound buffer of the sound
         * @param buffer Sound buffer to set
         */
        void setBuffer(const SoundBuffer &buffer);

        /**
         * @brief Enable or disable the looping of the sound
         * @param loop True to enable looping, false to disable it
         */
        void setLoop(bool loop);

        /**
         * @brief Set the current playing position of the stream
         * @param timeOffset Current playing position
         */
        void setPlayingOffset(Time timeOffset);

        /**
         * @brief Get the sound buffer of the sound
         * @return Sound buffer of the sound
         */
        const SoundBuffer *getBuffer() const;

        /**
         * @brief Tells if the music is in loop mode or not
         */
        void getLoop() const;

        /**
         * @brief Get the current playing position of the stream
         * @return Current playing position
         */
        Time getPlayingOffset() const;

        /**
         * @brief Get the current status of the stream
         * @return Current status
         */
        Status getStatus() const;

        /**
         * @brief Default assignment operator.
         */
        Sound &operator=(const Sound &other) = default;

        /**
         * @brief Reset the sound buffer of the sound
         */
        void resetBuffer();

    private:
        sf::Sound _sound;  /**< SFML sound */
        SoundBuffer _buffer;  /**< SFML sound buffer */
    };
}


#endif //URANUS_SOUND_HPP
