#include "BadBind.hpp"

rnetwork::exceptions::BadBind::BadBind(const std::string &what) :
        runtime_error(what) {}
