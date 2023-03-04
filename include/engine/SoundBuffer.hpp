//
// Created by nicol on 04/03/2023.
//

#ifndef URANUS_SOUNDBUFFER_HPP
#define URANUS_SOUNDBUFFER_HPP

#include <SFML/Audio.hpp>
#include "InputStream.hpp"
#include "Time.hpp"

namespace uranus {
    /**
     * @brief SoundBuffer class
     */
    class SoundBuffer {
    public:
        /**
         * @brief Default constructor.
         */
        SoundBuffer() = default;

        /**
         * @brief Default copy constructor.
         */
        SoundBuffer(const SoundBuffer &copy) = default;

        /**
         * @brief Default destructor.
         */
        ~SoundBuffer() = default;

        /**
         * @brief Load the sound buffer from a file.
         * @param filename Filename of the sound buffer to load.
         * @return True if the sound buffer was loaded successfully, false otherwise.
         */
        bool loadFromFile(const std::string &filename);

        /**
         * @brief Load the sound buffer from a memory.
         * @param data Pointer to the data to load.
         * @param sizeInBytes Size of the data to load, in bytes.
         * @return True if the sound buffer was loaded successfully, false otherwise.
         */
        bool loadFromMemory(const void *data, std::size_t sizeInBytes);

        /**
         * @brief Load the sound buffer from a custom stream.
         * @param stream Stream to read from.
         * @return True if the sound buffer was loaded successfully, false otherwise.
         */
        bool loadFromStream(InputStream &stream);

        /**
         * @brief Load the sound buffer from an array of samples.
         * @param samples Pointer to the array of samples.
         * @param sampleCount Number of samples pointed by the array.
         * @param channelCount Number of channels (1 = mono, 2 = stereo).
         * @param sampleRate Sample rate (number of samples to play per second).
         * @return True if the sound buffer was loaded successfully, false otherwise.
         */
        bool loadFromSamples(const short *samples, std::size_t sampleCount, unsigned int channelCount, unsigned int sampleRate);

        /**
         * @brief Save the sound buffer to a file.
         * @param filename Filename of the sound buffer to save.
         * @return True if the sound buffer was saved successfully, false otherwise.
         */
        bool saveToFile(const std::string &filename) const;

        /**
         * @brief Get the array of audio samples stored in the buffer.
         * @return Pointer to the array of samples.
         */
        const short *getSamples() const;

        /**
         * @brief Get the number of samples stored in the buffer.
         * @return Number of samples.
         */
        unsigned long long getSampleCount() const;

        /**
         * @brief Get the number of channels used by the sound.
         * @return Number of channels (1 = mono, 2 = stereo).
         */
        unsigned int getSampleRate() const;

        /**
         * @brief Get the number of channels used by the sound.
         * @return Number of channels (1 = mono, 2 = stereo).
         */
        unsigned int getChannelCount() const;

        /**
         * @brief Get the total duration of the sound.
         * @return Sound duration.
         */
        Time getDuration() const;

        /**
         * @brief Default assignment operator.
         */
        SoundBuffer &operator=(const SoundBuffer &other) = default;

        /**
         * @brief Get the SFML SoundBuffer.
         * @return SFML SoundBuffer.
         */
        const sf::SoundBuffer &getBuffer() const;
    private:
        sf::SoundBuffer _buffer; /**< SFML SoundBuffer */
    };
}


#endif //URANUS_SOUNDBUFFER_HPP
