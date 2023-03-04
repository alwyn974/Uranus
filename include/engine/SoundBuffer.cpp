//
// Created by nicol on 04/03/2023.
//

#include "SoundBuffer.hpp"

bool uranus::SoundBuffer::loadFromFile(const std::string &filename) {
    return _buffer.loadFromFile(filename);
}

bool uranus::SoundBuffer::loadFromMemory(const void *data, std::size_t sizeInBytes) {
    return _buffer.loadFromMemory(data, sizeInBytes);
}

bool uranus::SoundBuffer::loadFromStream(InputStream &stream) {
    return _buffer.loadFromStream(stream.getInputStream());
}

bool uranus::SoundBuffer::loadFromSamples(const short *samples, std::size_t sampleCount, unsigned int channelCount, unsigned int sampleRate) {
    return _buffer.loadFromSamples(samples, sampleCount, channelCount, sampleRate);
}

bool uranus::SoundBuffer::saveToFile(const std::string &filename) const {
    return _buffer.saveToFile(filename);
}

const short *uranus::SoundBuffer::getSamples() const {
    return _buffer.getSamples();
}

unsigned long long uranus::SoundBuffer::getSampleCount() const {
    return _buffer.getSampleCount();
}

unsigned int uranus::SoundBuffer::getSampleRate() const {
    return _buffer.getSampleRate();
}

unsigned int uranus::SoundBuffer::getChannelCount() const {
    return _buffer.getChannelCount();
}

uranus::Time uranus::SoundBuffer::getDuration() const {
    return Time(_buffer.getDuration());
}

const sf::SoundBuffer &uranus::SoundBuffer::getBuffer() const {
    return _buffer;
}



