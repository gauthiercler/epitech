//
// Created by valentin on 10/02/18.
//

#include <iostream>
#include <nobyte/NoByte.hpp>
#include <thread>
#include <rnetwork/exceptions/AcceptError.hpp>
#include "shared/RequestBuilder.hpp"
#include "rnetwork/packet/PacketBase.hpp"
#include "Net.hpp"
#include "Client.hpp"

bool zia::modules::Net::config(const zia::api::Conf &conf) {
    try {
        _port = std::stol(std::get<std::string>(conf.at("port").v));
        _sslPort = std::stol(std::get<std::string>(conf.at("ssl_port").v));
        _certPath = std::get<std::string>(conf.at("cert_path").v);
        _keyPath = std::get<std::string>(conf.at("key_path").v);
        _nbThread = std::stol(std::get<std::string>(conf.at("nb_workers").v));
    } catch (std::exception &e) {
        std::cerr << "[WARNING] Error during the configuration of the network" << std::endl;
        return (false);
    }
    return (true);
}

bool zia::modules::Net::run(zia::api::Net::Callback cb) {
    try {
        std::cout << "[INFO][NET] Start listening on port " << _port << std::endl;
        std::cout << "[INFO][NET] Start listening on port " << _sslPort << " (ssl)" << std::endl;
        _callback = cb;
        _acceptor = std::make_shared<rnetwork::tcp::Acceptor>(_ioService, rnetwork::Endpoint("0.0.0.0", _port));
        _acceptor->async_accept(std::bind(&zia::modules::Net::handleClient, this, _acceptor, std::placeholders::_1, std::placeholders::_2));
        _sslAcceptor = std::make_shared<rnetwork::tcp::SSLAcceptor>(_ioService, rnetwork::Endpoint("0.0.0.0", _sslPort), _certPath, _keyPath);
        _sslAcceptor->async_accept(std::bind(&zia::modules::Net::handleClient, this, _sslAcceptor, std::placeholders::_1, std::placeholders::_2));
        for (unsigned int i = 0; i < _nbThread - 1; ++i)
            new std::thread([&]() {
                start();
            });
        start();
        _ioService.run();
    } catch (const std::exception &e) {
        std::cerr << "[ERROR][NET] " << e.what() << std::endl;
    }
    return false;
}

bool zia::modules::Net::send(zia::api::ImplSocket *sock,
                             const zia::api::Net::Raw &resp) {
    std::string message = noByte::toString(resp);
    sock->sendMessage(message);
    return true;
}

bool zia::modules::Net::stop() {
    return false;
}

void zia::modules::Net::handleClient(std::shared_ptr<rnetwork::tcp::Acceptor> acceptor,
                                     std::shared_ptr<rnetwork::IClient> socket,
                                     bool status) {
    if (status) {
        std::cout << "[INFO][NET] New client from  " << socket->getEndpoint() << std::endl;
        auto client = std::make_shared<zia::modules::net::Client>(socket);
        acceptor->async_accept(std::bind(&zia::modules::Net::handleClient, this, acceptor, std::placeholders::_1, std::placeholders::_2));
        client->onReady(_callback);
        client->start();
    } else
        std::cout << "[ERROR][NET] Unable to accept new client" << std::endl;
}

void zia::modules::Net::start() {
    std::cout << "[INFO][NET] Additional worker started" << std::endl;
    try {
        _ioService.run();
    } catch (const rnetwork::exceptions::AcceptError &e) {
        std::cerr << "[WARNING][NET] Failed to accept client. Worker will restart" << std::endl;
        start();
    } catch (const std::exception &e) {
        std::cerr << "[ERROR][NET] An error occurred. Worker will shutdown." << std::endl;
    }
    std::cout << "[INFO][NET] Worker stopped" << std::endl;
}

extern "C" zia::api::Net *zia::modules::create() {
    auto *net = new Net;

    return (net);
}