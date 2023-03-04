//
// Created by nicol on 04/03/2023.
//

#include "Sound.hpp"

uranus::Sound::Sound(const SoundBuffer &buffer) {
    _sound.setBuffer(buffer.getBuffer());
}

void uranus::Sound::play() {
    _sound.play();
}

void uranus::Sound::pause() {
    _sound.pause();
}

void uranus::Sound::stop() {
    _sound.stop();
}

void uranus::Sound::setBuffer(const SoundBuffer &buffer) {
    _sound.setBuffer(buffer.getBuffer());
}

void uranus::Sound::setLoop(bool loop) {
    _sound.setLoop(loop);
}

void uranus::Sound::setPlayingOffset(Time timeOffset)
{
    _sound.setPlayingOffset(sf::seconds(timeOffset.asSeconds()));
}

//TODO: Check if this is correct
const uranus::SoundBuffer *uranus::Sound::getBuffer() const {
    return &_buffer;
}

void uranus::Sound::getLoop() const {
    _sound.getLoop();
}

uranus::Time uranus::Sound::getPlayingOffset() const {
    return Time(_sound.getPlayingOffset());
}

uranus::SoundSource::Status uranus::Sound::getStatus() const {
    return static_cast<uranus::SoundSource::Status>(_sound.getStatus());
}

void uranus::Sound::resetBuffer() {
    _sound.resetBuffer();
}
