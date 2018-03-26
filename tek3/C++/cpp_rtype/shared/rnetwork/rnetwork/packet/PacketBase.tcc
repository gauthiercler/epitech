#include "rnetwork/packet/PacketBase.hpp"

template<typename T>
std::shared_ptr<T> rnetwork::packet::PacketBase::generateClient(rnetwork::async::IOService &ioService) const {
    return std::make_shared<T>(&_fromLowLevel, ioService);
}
