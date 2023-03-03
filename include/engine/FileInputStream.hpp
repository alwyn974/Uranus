//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_FILEINPUTSTREAM_HPP
#define URANUS_FILEINPUTSTREAM_HPP

#include "InputStream.hpp"

namespace uranus {
    /**
     * @brief File input stream class that inherits from InputStream
     */
    class FileInputStream : public InputStream {
    public:
        /**
         * @brief Default constructor
         */
        FileInputStream() = default;

        /**
         * @brief Default destructor
         */
        ~FileInputStream() = default;

        /**
         * @brief Open the stream from a file
         * @param filename Filename to open
         */
        void open(const std::string &filename);

        /**
         * @brief Read data from the stream
         * @param data Data to read
         * @param size Size of the data
         * @return Number of bytes read
         */
        long long read(void *data, long long size) override;

        /**
         * @brief Seek to a position in the stream
         * @param position Position to seek to
         * @return Position actually reached
         */
        long long seek(long long position) override;

        /**
         * @brief Get the current position in the stream
         * @return Current position in the stream
         */
        long long tell() override;

        /**
         * @brief Get the size of the stream
         * @return Size of the stream
         */
        long long getSize() override;
    private:
        sf::FileInputStream _fileInputStream; /**< SFML FileInputStream */
    };
}


#endif //URANUS_FILEINPUTSTREAM_HPP
