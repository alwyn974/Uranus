//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_MEMORYINPUTSTREAM_HPP
#define URANUS_MEMORYINPUTSTREAM_HPP

#include "InputStream.hpp"
#include "SFML/System.hpp"

namespace uranus {
    /**
     * @brief Memory input stream class that inherits from InputStream
     */
    class MemoryInputStream : public InputStream {
    public:
        /**
         * @brief Default constructor
         */
        MemoryInputStream() = default;

        /**
         * @brief Default destructor
         */
        ~MemoryInputStream() override = default;

        /**
         * @brief Open the stream from its data
         * @param data Data to open
         * @param sizeInBytes Size of the data in bytes
         */
        void open(const void *data, std::size_t sizeInBytes);

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

        /**
         * @brief Get the SFML InputStream
         * @return SFML InputStream
         */
        sf::InputStream &getInputStream() override;
    private:
        sf::MemoryInputStream _stream; /**< SFML MemoryInputStream */
    };
}


#endif //URANUS_MEMORYINPUTSTREAM_HPP
