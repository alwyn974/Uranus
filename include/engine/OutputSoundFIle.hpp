//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_OUTPUTSOUNDFILE_HPP
#define URANUS_OUTPUTSOUNDFILE_HPP

#include "SFML/Audio.hpp"

namespace uranus {
    /**
     * @brief This class is used to write sound samples to a file.
     */
    class OutputSoundFIle {
        /**
         * @brief Default constructor
         */
        OutputSoundFIle() = default;

        /**
         * @brief Default destructor
         */
        ~OutputSoundFIle() = default;

        /**
         * @brief Open a sound file for writing.
         * @param filename Path of the file to open
         * @param channelCount Number of channels
         * @param sampleRate Sample rate, in samples per second
         * @return True if the file was successfully opened
         */
        bool open(const std::string &filename, unsigned int channelCount, unsigned int sampleRate);

        /**
         * @brief Write audio samples to the file.
         * @param samples Pointer to the sample array to write
         * @param sampleCount Number of samples to write
         * @return True if the samples were successfully written
         */
        bool write(const short *samples, std::size_t sampleCount);
    private:
        sf::OutputSoundFile _outputSoundFile; /**< SFML OutputSoundFile */
    };
}


#endif //URANUS_OUTPUTSOUNDFILE_HPP
