//
// Created by nicol on 09/01/2023.
//

#include "Bullet.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Window.hpp"

#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"


#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

#include "ByteBuffer.hpp"

#include "Network.hpp"

using namespace saturnity;

size_t lul = 0;



std::list<std::string> split_str(size_t pos, std::string& s, std::string delimiter)
{
    std::string token;
    std::list<std::string> parsed;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        parsed.insert(parsed.cend(), token);
        //        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    return parsed;
}

std::vector<std::string> split(std::string &s, char delim)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) elems.push_back(item);
    return elems;
}

int main(int ac, char **av)
{
    boost::asio::io_context ioContext;


    sf::RenderWindow *window = Window::getWindow();
    window->setFramerateLimit(20);


    saturnity::UdpClient *network = Network::getNetwork(ioContext);
    std::cout << "moula" << std::endl;


    registry r;
    std::function<void(registry &, const size_t &)> delete_pos = delete_position;
    r.register_component<component::position>(delete_pos);
    std::function<void(registry &, const size_t &)> delete_vel = delete_velocity;
    r.register_component<component::velocity>(delete_vel);
    std::function<void(registry &, const size_t &)> delete_draw = delete_drawable;
    r.register_component<component::drawable>(delete_draw);
    std::function<void(registry &, const size_t &)> delete_cont = delete_controllable;
    r.register_component<component::controllable>(delete_cont);
    std::function<void(registry &, const size_t &)> delete_inputK = delete_inputKeyboard;
    r.register_component<component::inputKeyboard>(delete_inputK);
    std::function<void(registry &, const size_t &)> delete_inputM = delete_inputMouse;
    r.register_component<component::inputMouse>(delete_inputM);
    std::function<void(registry &, const size_t &)> delete_sprite = delete_sprite_component;
    r.register_component<component::sprite>(delete_sprite);
    std::function<void(registry &, const size_t &)> delete_loop = delete_loop_component;
    r.register_component<component::loop>(delete_loop);
    std::function<void(registry &, const size_t &)> delete_collision = delete_collisionable;
    r.register_component<component::collisionable>(delete_collision);

    Player player(r);
    Player player2(r);

    std::string he("p:55:88:99:");
    std::vector<std::string> li = split(he, ':');

    for (auto &element : li) {
        std::cout << "element: " << element << std::endl;
    }

    network->send("hello");
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) window->close();

            input_system(r, event);
        }
        window->clear();
        loop_system(r);
        position_system(r);
        collision_system(r);
        draw_system(r);
        window->display();
//        network->send("hello");


//        std::cout << "packet: *" << packet << "*" << lul << std::endl;
        network->receive();
        lul++;

        auto &pos_1 = r.get_component<component::position>(r.entity_from_index(0));
        auto &pos_2 = r.get_component<component::position>(r.entity_from_index(1));

        std::string packet = network->getBuffer();
        std::vector<std::string> parsed = split(packet, ':');

//        auto l_front = parsed.begin();

//        std::string str = std::string(*l_front);
        if (parsed.size() > 2) {

            std::cout << "packet: " << packet << std::endl;
            std::cout << "p: " << parsed.at(0) << ", x: " << parsed.at(1) << ", y: " << parsed.at(2) << std::endl;
            if (parsed.at(0).compare(std::string("p")) == 0) {
                pos_2->x = atof(parsed.at(1).c_str());
                pos_2->y = atof(parsed.at(2).c_str());
            }
        }

        network->send("p:" + std::to_string(int(pos_1->x)) + ":" + std::to_string(int(pos_1->y)) + ":");



//        std::string packet2 = network->getBuffer();
//        std::cout << "packet: *" << packet2 << "*" << lul << std::endl;
        ioContext.run_one();


    }
    return 0;
}
