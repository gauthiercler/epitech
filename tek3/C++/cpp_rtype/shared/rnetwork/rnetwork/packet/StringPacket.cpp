#include "StringPacket.hpp"

rnetwork::packet::StringPacket::StringPacket(const std::string &string) :
        _data(string),
        _from("0.0.0.0", 0)
{}

std::size_t rnetwork::packet::StringPacket::size() const {
    return _data.length();
}

const unsigned char *rnetwork::packet::StringPacket::raw() const {
    return reinterpret_cast<const unsigned char *>(_data.c_str());
}

const rnetwork::Endpoint &rnetwork::packet::StringPacket::from() const {
    return _from;
}

std::shared_ptr<rnetwork::packet::IPacket> rnetwork::packet::StringPacket::snapshot() const {
    return std::make_shared<rnetwork::packet::StringPacket>(*this);
}

const std::string &rnetwork::packet::StringPacket::str() const {
    return _data;
}

std::ostream &operator<<(std::ostream &os, const rnetwork::packet::StringPacket &packet) {
    os << packet.str();
    return os;
}
