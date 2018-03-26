#include "rnetwork.hpp"

bool rnetwork::init() {
#ifdef WIN32
    WSADATA wsa;
    int err = WSAStartup(MAKEWORD(2, 2), &wsa);
    if(err < 0)
    return false;
#endif
    return true;
}

void rnetwork::clean() {
#ifdef WIN32
    WSACleanup();
#endif
}
