#include <cstring>
#include "UDPHostPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::UDPHostPacket::UDPHostPacket() :
        PacketBase(op::UdpHostPacket, this->Size),
        _endpoint("0.0.0.0", 00)
{
    updatePacket();
}

rnetwork::packet::UDPHostPacket::UDPHostPacket(const rnetwork::Endpoint &endpoint) :
        PacketBase(op::UdpHostPacket, this->Size),
        _endpoint(endpoint)
{
    updatePacket();
}

void rnetwork::packet::UDPHostPacket::setEndpoint(const rnetwork::Endpoint &endpoint) {
    _endpoint = endpoint;
    updatePacket();
}

const rnetwork::Endpoint &rnetwork::packet::UDPHostPacket::getEndpoint() const {
    return _endpoint;
}

void rnetwork::packet::UDPHostPacket::updatePacket() {
    uint16_t *port;
    unsigned long length = 2 + _endpoint.host().length();

    delete[] _raw;
    _raw = new unsigned char[length + HEADER_SIZE];
    _size = length + HEADER_SIZE;
    port = reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]);
    setOp(op::UdpHostPacket);
    setLength(static_cast<uint16_t>(length));
    *port = ntohs(_endpoint.port());
    std::memcpy(&_raw[HEADER_SIZE + 2], _endpoint.host().c_str(), _endpoint.host().length());
}

std::string rnetwork::packet::UDPHostPacket::getRawHost() const {
    return std::move(std::string(reinterpret_cast<char *>(&_raw[HEADER_SIZE + 2]), getLength() - 2));
}

uint16_t rnetwork::packet::UDPHostPacket::getRawPort() const {
    return ntohs(*reinterpret_cast<uint16_t *>(&_raw[HEADER_SIZE]));
}


rnetwork::packet::UDPHostPacket::UDPHostPacket(const rnetwork::packet::PacketBase &base) :
        PacketBase(base),
        _endpoint(getRawHost(), getRawPort())
{
}
