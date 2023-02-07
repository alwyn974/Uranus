/*
** EPITECH PROJECT, 2023
** Bullet.cpp
** File description:
** Bullet.cpp
*/

#include "Network.hpp"
#include <iostream>

saturnity::UdpClient *Network::_network = nullptr;

saturnity::UdpClient *Network::getNetwork(boost::asio::io_context &ioContext)
{
    if (_network == nullptr) {
        _network = new saturnity::UdpClient(saturnity::UdpClient("192.168.0.106", "25565", ioContext));
    }
    return _network;
}
