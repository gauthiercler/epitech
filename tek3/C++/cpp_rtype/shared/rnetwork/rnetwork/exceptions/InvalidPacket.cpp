#include "InvalidPacket.hpp"

rnetwork::exceptions::InvalidPacket::InvalidPacket(const std::string &what) :
        runtime_error(what) {}
