#include "ConnectionError.hpp"

rnetwork::exceptions::ConnectionError::ConnectionError(const std::string &what) :
        runtime_error(what) {}
