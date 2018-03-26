#include "AcceptError.hpp"

rnetwork::exceptions::AcceptError::AcceptError(const std::string &what) :
        runtime_error(what) {}
