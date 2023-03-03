//
// Created by nicol on 03/03/2023.
//

#ifndef URANUS_INPUTSTREAM_HPP
#define URANUS_INPUTSTREAM_HPP

#include <SFML/System.hpp>

namespace uranus {
    /**
     * @brief Input stream class
     */
    class InputStream {
    public:
        /**
         * @brief Default destructor
         */
        virtual ~InputStream() = default;

        /**
         * @brief Read data from the stream
         * @param data Buffer to store the data
         * @param size Size of the data
         * @return Number of bytes read or -1 if an error occurred
         */
        virtual long long read(void *data, long long size) = 0;

        /**
         * @brief Change the current read position
         * @param position Position to seek to
         * @return Position actually reached or -1 if an error occurred
         */
        virtual long long seek(long long position) = 0;

        /**
         * @brief Get the current read position
         * @return Current read position or -1 if an error occurred
         */
        virtual long long tell() = 0;

        /**
         * @brief Get the total number of bytes available for reading
         * @return Total number of bytes available or -1 if an error occurred
         */
        virtual long long getSize() = 0;
    };
}


#endif //URANUS_INPUTSTREAM_HPP
