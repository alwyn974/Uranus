//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_MUSIC_HPP
#define URANUS_MUSIC_HPP

#include "SFML/Audio.hpp"
#include "Time.hpp"
#include "InputStream.hpp"
#include "Vector3.hpp"

namespace uranus {
    /**
     * @brief Music class
     */
    class Music {
    public:
        /**
         * @brief Span struct defining a time range
         * @tparam T Type of the span
         */
        template<typename T>
        struct Span {
            /**
             * @brief Default constructor
             */
            Span() = default;

            /**
             * @brief Initialization constructor
             * @param off Offset of the span
             * @param len Length of the span
             */
            Span(T off, T len) : offset(off), length(len) {};

            T offset; /**< Offset of the span */
            T length; /**< Length of the span */
        };

        typedef Span<Time> TimeSpan; /**< Time span */
        /**
         * @brief Default constructor
         */
        Music() = default;

        /**
         * @brief Default destructor
         */
        ~Music() = default;

        /**
         * @brief Open a music from a file
         * @param path Path to the file
         * @return True if the file was opened successfully
         */
        bool openFromFile(const std::string &path);

        /**
         * @brief Open a music from a memory
         * @param data Pointer to the data
         * @param size Size of the data
         * @return True if the data was opened successfully
         */
        bool openFromMemory(const void *data, std::size_t size);

        /**
         * @brief Open a music from a stream
         * @param stream Stream to read from
         * @return True if the stream was opened successfully
         */
        bool openFromStream(InputStream &stream);

        /**
         * @brief Get the duration of the music
         * @return Duration of the music
         */
        Time getDuration() const;

        /**
         * @brief Sets the beginning and the end of the sound's looping sequence
         * @return Definition of the loop
         */
        TimeSpan getLoopPoints() const;

        /**
         * @brief Play the music
         */
        void play();

        /**
         * @brief Pause the music
         */
        void pause();

        /**
         * @brief Stop the music
         */
        void stop();

        /**
         * @brief Get the number of channels of the stream
         * @return Number of channels
         */
        unsigned int getChannelCount() const;

        /**
         * @brief Get the sample rate of the stream
         * @return Sample rate
         */
        unsigned int getSampleRate() const;

        /**
         * @brief Get the current status of the stream
         * @return Current status
         */
        sf::Sound::Status getStatus() const;

        /**
         * @brief Get the current playing position of the stream
         * @return Current playing position
         */
        Time getPlayingOffset() const;

        /**
         * @brief Set the current playing position of the stream
         * @param timeOffset Current playing position
         */
        void setPlayingOffset(Time timeOffset);

        /**
         * @brief Set if the music should loop or not
         * @param loop True if the music should loop, false otherwise
         */
        void setLoop(bool loop);

        /**
         * @brief Tells if the music is in loop mode or not
         */
        void getLoop() const;

        /**
         * @brief Set the pitch of the sound
         * @param pitch Pitch of the sound
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
        void setPosition(const sf::Vector3f &position);

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
    private:
        sf::Music _music /**< SFML music */;
    };
}



#endif //URANUS_MUSIC_HPP
