/*
** EPITECH PROJECT, 2023
** Network.hpp
** File description:
** Network.hpp
*/

#ifndef URANUS_NETWORK_HPP
#define URANUS_NETWORK_HPP

#include "client.hpp"

#include <thread>
#include <boost/asio.hpp>
// Singleton window class
class Network {
public:
    ~Network() = default;
    Network(const Network &) = delete;
    Network &operator=(const Network &) = delete;

    static saturnity::UdpClient *getNetwork(boost::asio::io_context &ioContext);

private:
    Network() = default;
    static boost::asio::io_context ioContext;

    static saturnity::UdpClient *_network;
};

#endif //URANUS_NETWORK_HPP
