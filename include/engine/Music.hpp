//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_MUSIC_HPP
#define URANUS_MUSIC_HPP

#include "SFML/Audio.hpp"
#include "Time.hpp"
#include "InputStream.hpp"
#include "Vector3.hpp"
#include "SoundSource.hpp"

namespace uranus {
    /**
     * @brief Music class
     */
    class Music : public SoundSource {
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

            /**
             * @brief Constructor from sf::Music::TimeSpan
             * @param span Span to copy
             */
            explicit Span(sf::Music::TimeSpan span) : offset(span.offset), length(span.length) {};

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
        ~Music() override = default;

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
        void play() override;

        /**
         * @brief Pause the music
         */
        void pause() override;

        /**
         * @brief Stop the music
         */
        void stop() override;

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
        Status getStatus() const override;

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
         * @return True if the music is looping, false otherwise
         */
        bool getLoop() const;

        /**
         * @brief Set the pitch of the sound
         * @param pitch Pitch of the sound
         */
        void setPitch(float pitch) override;

        /**
         * @brief Set the volume of the sound
         * @param volume Volume of the sound
         */
        void setVolume(float volume) override;

        /**
         * @brief Set the 3D position of the sound in the audio scene
         * @param position Position of the sound
         */
        void setPosition(float x, float y, float z) override;

        /**
         * @brief Set the 3D position of the sound in the audio scene
         * @param position Position of the sound
         */
        void setPosition(const Vector3f &position) override;

        /**
         * @brief Make the sound's position relative to the listener or absolute
         * @param relative True to set the position relative, false to set it absolute
         */
        void setRelativeToListener(bool relative) override;

        /**
         * @brief Set the minimum distance of the sound
         * @param distance Minimum distance of the sound
         */
        void setMinDistance(float distance) override;

        /**
         * @brief Set the attenuation factor of the sound
         * @param attenuation Attenuation factor of the sound
         */
        void setAttenuation(float attenuation) override;

        /**
         * @brief Get the pitch of the sound
         * @return Pitch of the sound
         */
        float getPitch() const override;

        /**
         * @brief Get the volume of the sound
         * @return Volume of the sound
         */
        float getVolume() const override;

        /**
         * @brief Get the 3D position of the sound in the audio scene
         * @return Position of the sound
         */
        const Vector3f &getPosition() const override;

        /**
         * @brief Tell whether the sound's position is relative to the listener or is absolute
         * @return True if the position is relative, false if it's absolute
         */
        bool isRelativeToListener() const override;

        /**
         * @brief Get the minimum distance of the sound
         * @return Minimum distance of the sound
         */
        float getMinDistance() const override;

        /**
         * @brief Get the attenuation factor of the sound
         * @return Attenuation factor of the sound
         */
        float getAttenuation() const override;
    private:
        sf::Music _music /**< SFML music */;
        Vector3f _position; /**< Position of the sound */
    };
}



#endif //URANUS_MUSIC_HPP
