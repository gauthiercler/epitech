#include <cstring>
#include <iostream>
#include "UDPTokenPacket.hpp"
#include "Opcodes.hpp"

rnetwork::packet::UDPTokenPacket::UDPTokenPacket() :
        PacketBase(op::UdpTokenPacket, this->Size),
        _token("") {
}

rnetwork::packet::UDPTokenPacket::UDPTokenPacket(const std::string &token) :
        UDPTokenPacket()
{
    setToken(token);
}

rnetwork::packet::UDPTokenPacket::UDPTokenPacket(const rnetwork::packet::PacketBase &packet) :
        PacketBase(packet),
        _token(reinterpret_cast<const char *>(_raw) + HEADER_SIZE, getLength()) {}

rnetwork::packet::UDPTokenPacket &rnetwork::packet::UDPTokenPacket::operator=(const rnetwork::packet::UDPTokenPacket &packet) {
    if (this != &packet) {
        PacketBase::operator=(packet);
        _token = packet._token;
    }
    return *this;
}

void rnetwork::packet::UDPTokenPacket::setToken(const std::string &token) {
    _token = token;
    std::memset(&_raw[HEADER_SIZE], 0, getLength());
    std::memcpy(&_raw[HEADER_SIZE], token.c_str(), (token.length() < this->TokenSize) ? token.length() : this->TokenSize);
}

const std::string &rnetwork::packet::UDPTokenPacket::getToken() const {
    return _token;
}

std::shared_ptr<rnetwork::packet::IPacket> rnetwork::packet::UDPTokenPacket::snapshot() const {
    return std::make_shared<rnetwork::packet::UDPTokenPacket>(*this);
}

rnetwork::packet::PacketBase &operator>>(rnetwork::packet::PacketBase &base, rnetwork::packet::UDPTokenPacket &packet) {
    packet = rnetwork::packet::UDPTokenPacket(base);
    return base;
}
