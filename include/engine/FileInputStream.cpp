//
// Created by nicol on 03/03/2023.
//

#include "FileInputStream.hpp"

void uranus::FileInputStream::open(const std::string &filename) {
    _fileInputStream.open(filename);
}

long long uranus::FileInputStream::read(void *data, long long size) {
    return _fileInputStream.read(data, size);
}

long long uranus::FileInputStream::seek(long long position) {
    return _fileInputStream.seek(position);
}

long long uranus::FileInputStream::tell() {
    return _fileInputStream.tell();
}

long long uranus::FileInputStream::getSize() {
    return _fileInputStream.getSize();
}

sf::InputStream &uranus::FileInputStream::getInputStream() {
    return _fileInputStream;
}
