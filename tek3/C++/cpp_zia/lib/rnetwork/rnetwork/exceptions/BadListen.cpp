#include "BadListen.hpp"

rnetwork::exceptions::BadListen::BadListen(const std::string &what) :
        runtime_error(what) {}
