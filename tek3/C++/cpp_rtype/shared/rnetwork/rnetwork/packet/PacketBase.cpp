#include <cstring>
#include <rnetwork/exceptions/InvalidPacket.hpp>
#include <iostream>
#include "PacketBase.hpp"

rnetwork::packet::PacketBase::PacketBase(uint16_t op, std::size_t length) :
        _size(4 + length),
        _raw(new unsigned char[_size]),
        _from("0.0.0.0", 00)
{
    std::memset(_raw, 0, _size);
    setOp(op);
    setLength(length);
}


rnetwork::packet::PacketBase::PacketBase(unsigned char *raw, std::size_t size) :
        _size(size),
        _raw(new unsigned char[size]),
        _from("0.0.0.0", 0)
{
    std::memcpy(_raw, raw, size);
}

rnetwork::packet::PacketBase::PacketBase(unsigned char *raw, std::size_t size, SOCKADDR_IN *from) :
        PacketBase(raw, size)
{
    _from = rnetwork::Endpoint(from);
    _fromLowLevel = *from;
}

rnetwork::packet::PacketBase::PacketBase(const rnetwork::packet::PacketBase &packetBase) :
        _size(packetBase._size),
        _raw(new unsigned char[packetBase._size]),
        _from(packetBase._from)
{
    std::memcpy(_raw, packetBase._raw, packetBase._size);
}

rnetwork::packet::PacketBase::~PacketBase() {
    delete[] _raw;
}

rnetwork::packet::PacketBase &rnetwork::packet::PacketBase::operator=(const rnetwork::packet::PacketBase &packetBase) {
    if (this != &packetBase) {
        delete[] _raw;
        _raw = new unsigned char[packetBase._size];
        std::memcpy(_raw, packetBase._raw, packetBase._size);
        _size = packetBase._size;
        _from = packetBase._from;
    }
    return *this;
}

const unsigned char *rnetwork::packet::PacketBase::raw() const {
    return _raw;
}

std::size_t rnetwork::packet::PacketBase::size() const {
    return _size;
}

const rnetwork::Endpoint &rnetwork::packet::PacketBase::from() const {
    return _from;
}

std::shared_ptr<rnetwork::packet::IPacket> rnetwork::packet::PacketBase::snapshot() const {
    return std::make_shared<rnetwork::packet::PacketBase>(*this);
}

rnetwork::packet::PacketBase &rnetwork::packet::PacketBase::operator>>(rnetwork::packet::StringPacket &stringPacket) {
    stringPacket = rnetwork::packet::StringPacket(std::string(reinterpret_cast<const char *>(_raw), _size));
    return *this;
}

void rnetwork::packet::PacketBase::setLength(uint16_t length) {
    if (_size < PACKET_LENGTH_SIZE)
        throw rnetwork::exceptions::InvalidPacket("Not enough space for packet length");
    auto *lengthPtr = reinterpret_cast<uint16_t *>(_raw);
    *lengthPtr = ntohs(length);
}

void rnetwork::packet::PacketBase::setOp(uint16_t op) {
    if (_size < PACKET_LENGTH_SIZE + PACKET_OP_SIZE)
        throw rnetwork::exceptions::InvalidPacket("Not enough space for packet op code");
    auto *opPtr = reinterpret_cast<uint16_t *>(&_raw[PACKET_LENGTH_SIZE]);
    *opPtr = ntohs(op);
}

uint16_t rnetwork::packet::PacketBase::getLength() const {
    if (_size < PACKET_LENGTH_SIZE)
        throw rnetwork::exceptions::InvalidPacket("Not enough space for packet length");
    auto *lengthPtr = reinterpret_cast<uint16_t *>(_raw);
    return htons(*lengthPtr);
}

uint16_t rnetwork::packet::PacketBase::getOp() const {
    if (_size < PACKET_LENGTH_SIZE + PACKET_OP_SIZE)
        throw rnetwork::exceptions::InvalidPacket("Not enough space for packet op code");
    auto *opPtr = reinterpret_cast<uint16_t *>(&_raw[PACKET_LENGTH_SIZE]);
    return htons(*opPtr);
}

void rnetwork::packet::PacketBase::setRemote(const rnetwork::Endpoint &remote) {
    _from = remote;
}

const rnetwork::Endpoint &rnetwork::packet::PacketBase::getRemote() const {
    return _from;
}

rnetwork::packet::PacketBase::PacketBase(rnetwork::packet::PacketBase&& packetBase) noexcept :
    PacketBase(packetBase._raw, packetBase.size())
{
    _fromLowLevel = std::move(packetBase._fromLowLevel);
    packetBase._raw = nullptr;
}
