#include <nobyte/NoByte.hpp>
#include "Client.hpp"
#include "rnetwork/packet/PacketBase.hpp"

zia::modules::net::Client::Client(std::shared_ptr<rnetwork::IClient> socket) :
    _socket(socket) {}

void zia::modules::net::Client::start() {
    _socket->async_receive(std::bind(&zia::modules::net::Client::handleData, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
}

void zia::modules::net::Client::handleData(rnetwork::packet::PacketBase &packetBase,
                                           bool status) {
    rnetwork::packet::StringPacket stringPacket("");

    if (status) {
        if (!_requestBuilder.isEnd()) {
            packetBase >> stringPacket;
            _requestBuilder.fill(stringPacket.str());
            _requestBuilder.parse();
            if (_requestBuilder.isEnd())
                ready();
        } else
            _socket->async_receive(std::bind(&zia::modules::net::Client::handleData, shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    } else
        std::clog << "[INFO] Client disconnected " << _socket->getEndpoint() << std::endl;
}

void zia::modules::net::Client::onReady(zia::api::Net::Callback onReady) {
    _onReady = std::move(onReady);
}

void zia::modules::net::Client::ready() {
    auto request = _requestBuilder.build();

    _onReady(request.inputRawData, generateNetInfo());
}

zia::api::NetInfo zia::modules::net::Client::generateNetInfo() const {
    zia::api::NetInfo info;

    info.ip.str = _socket->getEndpoint().host();
    info.ip.i = 0; // TODO Create real mask
    info.port = _socket->getEndpoint().port();
    info.sock = const_cast<Client *>(this);
    return std::move(info);
}

void zia::modules::net::Client::sendMessage(std::string &str) {
    rnetwork::packet::StringPacket packet(str);

    _socket->async_send(packet, [](bool) {});
}

std::string zia::modules::net::Client::receiveMessage() {
    rnetwork::packet::StringPacket packet("");

    *_socket->receive() >> packet;
    return packet.str();
}
