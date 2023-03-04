//
// Created by nicol on 03/03/2023.
//

#include "MemoryInputStream.hpp"

void uranus::MemoryInputStream::open(const void *data, std::size_t size) {
    _stream.open(data, size);
}

long long uranus::MemoryInputStream::read(void *data, long long size) {
    return _stream.read(data, size);
}

long long uranus::MemoryInputStream::seek(long long position) {
    return _stream.seek(position);
}

long long uranus::MemoryInputStream::tell() {
    return _stream.tell();
}

long long uranus::MemoryInputStream::getSize() {
    return _stream.getSize();
}

sf::InputStream &uranus::MemoryInputStream::getInputStream() {
    return _stream;
}