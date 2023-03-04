//
// Created by nicol on 03/03/2023.
//

#include "InputSoundFile.hpp"

bool uranus::InputSoundFile::openFromFile(const std::string &path) {
    return _file.openFromFile(path);
}

bool uranus::InputSoundFile::openFromMemory(const void *data, std::size_t sizeInBytes) {
    return _file.openFromMemory(data, sizeInBytes);
}

bool uranus::InputSoundFile::openFromStream(InputStream &stream) {
    return _file.openFromStream(stream.getInputStream());
}

unsigned long long uranus::InputSoundFile::getSampleCount() const {
    return _file.getSampleCount();
}

unsigned int uranus::InputSoundFile::getChannelCount() const {
    return _file.getChannelCount();
}

uranus::Time uranus::InputSoundFile::getDuration() const {
    return Time(_file.getDuration());
}

uranus::Time uranus::InputSoundFile::getTimeOffset() const {
    return Time(_file.getTimeOffset());
}

unsigned long long uranus::InputSoundFile::getSampleOffset() const {
    return _file.getSampleOffset();
}

void uranus::InputSoundFile::seek(Time timeOffset) {
    _file.seek(timeOffset.asSeconds());
}

unsigned long long uranus::InputSoundFile::read(short *samples, unsigned long long sampleCount) {
    return _file.read(samples, sampleCount);
}