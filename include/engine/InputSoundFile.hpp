//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_INPUTSOUNDFILE_HPP
#define URANUS_INPUTSOUNDFILE_HPP

#include <SFML/Audio.hpp>
#include "Time.hpp"

namespace uranus {
    /**
     * @brief InputSoundFile class
     */
    class InputSoundFile {
    public:
        /**
         * @brief Default constructor
         */
        InputSoundFile() = default;

        /**
         * @brief Default destructor
         */
        ~InputSoundFile() = default;

        /**
         * @brief Open a sound file
         * @param path Path of the sound file
         * @return True if the sound file is opened
         */
        bool openFromFile(const std::string &path);

        /**
         * @brief Open a sound file from a memory
         * @param data Data of the sound file
         * @param sizeInBytes Size of the data in bytes
         * @return True if the sound file is opened
         */
        bool openFromMemory(const void *data, std::size_t sizeInBytes);

        /**
         * @brief Open a sound file from a stream
         * @param stream Stream of the sound file
         * @return True if the sound file is opened
         */
        bool openFromStream(sf::InputStream &stream);

        /**
         * @brief Get the total number of samples in the file
         * @return Total number of samples
         */
        unsigned long long getSampleCount() const;

        /**
         * @brief Get the number of channels used by the sound file
         * @return Number of channels
         */
        unsigned int getChannelCount() const;

        /**
         * @brief Get the duration of the sound file
         * @return Duration of the sound file
         */
        Time getDuration() const;

        /**
         * @brief Get the read offset of the file in time
         * @return Read offset of the file in time
         */
        Time getTimeOffset() const;

        /**
         * @brief Get the read offset of the file in samples
         * @return Read offset of the file in samples
         */
        unsigned long long getSampleOffset() const;

        /**
         * @brief Change the current read offset of the file in time
         * @param timeOffset New read offset of the file in time
         */
        void seek(Time timeOffset);

        /**
         * @brief Read audio samples from the file
         * @param samples Array to fill with the samples
         * @param maxCount Maximum number of samples to read
         * @return Number of samples actually read
         */
        unsigned long long read(sf::Int16 *samples, unsigned long long maxCount);
    private:
        sf::InputSoundFile _file /*< SFML InputSoundFile */;
    };
}


#endif //URANUS_INPUTSOUNDFILE_HPP
