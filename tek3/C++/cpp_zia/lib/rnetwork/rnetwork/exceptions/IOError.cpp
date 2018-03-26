#include "IOError.hpp"

rnetwork::exceptions::IOError::IOError(const std::string &what) :
        runtime_error(what) {}
