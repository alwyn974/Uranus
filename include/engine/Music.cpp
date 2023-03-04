//
// Created by nicol on 03/03/2023.
//

#include "Music.hpp"

bool uranus::Music::openFromFile(const std::string &filename) {
   return _music.openFromFile(filename);
}

bool uranus::Music::openFromMemory(const void *data, std::size_t sizeInBytes) {
   return _music.openFromMemory(data, sizeInBytes);
}

bool uranus::Music::openFromStream(InputStream &stream) {
   return _music.openFromStream(stream.getInputStream());
}

uranus::Time uranus::Music::getDuration() const {
   return Time(_music.getDuration());
}

uranus::Music::TimeSpan uranus::Music::getLoopPoints() const {
   return TimeSpan(_music.getLoopPoints());
}

void uranus::Music::play() {
   _music.play();
}

void uranus::Music::pause() {
   _music.pause();
}

void uranus::Music::stop() {
   _music.stop();
}

unsigned int uranus::Music::getChannelCount() const {
   return _music.getChannelCount();
}

uranus::Music::Status uranus::Music::getStatus() const {
   return static_cast<Status>(_music.getStatus());
}

unsigned int uranus::Music::getSampleRate() const {
   return _music.getSampleRate();
}

uranus::Time uranus::Music::getPlayingOffset() const {
   return Time(_music.getPlayingOffset());
}

void uranus::Music::setPlayingOffset(Time timeOffset) {
    _music.setPlayingOffset(timeOffset.getTime());
}

void uranus::Music::setLoop(bool loop) {
    _music.setLoop(loop);
}

bool uranus::Music::getLoop() const {
    return _music.getLoop();
}

void uranus::Music::setPitch(float pitch) {
    _music.setPitch(pitch);
}

void uranus::Music::setVolume(float volume) {
    _music.setVolume(volume);
}

void uranus::Music::setPosition(const Vector3f &position) {
    _position = position;
    _music.setPosition(position.x, position.y, position.z);
}

void uranus::Music::setPosition(float x, float y, float z) {
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _music.setPosition(x, y, z);
}

void uranus::Music::setRelativeToListener(bool relative) {
    _music.setRelativeToListener(relative);
}

void uranus::Music::setMinDistance(float distance) {
    _music.setMinDistance(distance);
}

void uranus::Music::setAttenuation(float attenuation) {
    _music.setAttenuation(attenuation);
}

float uranus::Music::getPitch() const {
    _music.getPitch();
}

float uranus::Music::getVolume() const {
    return _music.getVolume();
}

const uranus::Vector3f &uranus::Music::getPosition() const {
    return _position;
}

bool uranus::Music::isRelativeToListener() const {
    return _music.isRelativeToListener();
}

float uranus::Music::getMinDistance() const {
    return _music.getMinDistance();
}

float uranus::Music::getAttenuation() const {
    return _music.getAttenuation();
}

