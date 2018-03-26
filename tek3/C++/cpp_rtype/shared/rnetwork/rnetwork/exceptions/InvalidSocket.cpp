#include "InvalidSocket.hpp"

rnetwork::exceptions::InvalidSocket::InvalidSocket(const std::string &what) :
        runtime_error(what) {}
