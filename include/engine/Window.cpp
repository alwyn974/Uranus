//
// Created by nicol on 04/03/2023.
//

#include "Window.hpp"

uranus::Window::Window(VideoMode mode, const std::string &title, unsigned int style, const ContextSettings &settings) : _window(mode.getVideoMode(), title, style, settings), _settings(settings)
{
}

void uranus::Window::create(VideoMode mode, const std::string &title, unsigned int style, const ContextSettings &settings)
{
    _settings = settings;
    _window.create(mode.getVideoMode(), title, style, settings);
}

void uranus::Window::create(sf::WindowHandle handle, const ContextSettings &settings) {
    _settings = settings;
    _window.create(handle, settings);
    onCreate();
}

void uranus::Window::close() {
    _window.close();
}

bool uranus::Window::isOpen() const {
    return _window.isOpen();
}

const uranus::ContextSettings &uranus::Window::getSettings() const {
    return _settings;
}

bool uranus::Window::pollEvent(Event &event) {
    return _window.pollEvent(event);
}

void uranus::Window::waitEvent(Event &event) {
    _window.waitEvent(event);
}

uranus::Vector2i uranus::Window::getPosition() const {
    return Vector2i(_window.getPosition());
}

void uranus::Window::setPosition(const Vector2i &position) {
    _window.setPosition(position);
}

uranus::Vector2u uranus::Window::getSize() const {
    return Vector2u(_window.getSize());
}

void uranus::Window::setSize(const Vector2u &size) {
    _window.setSize(size);
    onResize();
}

void uranus::Window::setTitle(const std::string &title) {
    _window.setTitle(title);
}

void uranus::Window::setIcon(unsigned int width, unsigned int height, const Uint8 *pixels) {
    _window.setIcon(width, height, pixels);
}

void uranus::Window::setVisible(bool visible) {
    _window.setVisible(visible);
}

void uranus::Window::setMouseCursorVisible(bool visible) {
    _window.setMouseCursorVisible(visible);
}

void uranus::Window::setMouseCursorGrabbed(bool grabbed) {
    _window.setMouseCursorGrabbed(grabbed);
}

void uranus::Window::setMouseCursor(const Cursor &cursor) {
    _window.setMouseCursor(cursor.getCursor());
}

void uranus::Window::setKeyRepeatEnabled(bool enabled) {
    _window.setKeyRepeatEnabled(enabled);
}

void uranus::Window::setFramerateLimit(unsigned int limit) {
    _window.setFramerateLimit(limit);
}

void uranus::Window::setJoystickThreshold(float threshold) {
    _window.setJoystickThreshold(threshold);
}

void uranus::Window::setVerticalSyncEnabled(bool enabled) {
    _window.setVerticalSyncEnabled(enabled);
}

bool uranus::Window::setActive(bool active) {
    return _window.setActive(active);
}

void uranus::Window::requestFocus() {
    _window.requestFocus();
}

bool uranus::Window::hasFocus() const {
    return _window.hasFocus();
}

void uranus::Window::display() {
    _window.display();
}

sf::WindowHandle uranus::Window::getSystemHandle() const {
    return _window.getSystemHandle();
}

const sf::Window &uranus::Window::getWindow() const {
    return _window;
}

void uranus::Window::onCreate() {
    setActive(true);
}

void uranus::Window::onResize() {

}


