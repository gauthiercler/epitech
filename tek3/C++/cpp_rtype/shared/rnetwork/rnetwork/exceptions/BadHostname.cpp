#include "BadHostname.hpp"

rnetwork::exceptions::BadHostname::BadHostname(const std::string &hostname) :
        logic_error("Unable to resolve " + hostname) {}
