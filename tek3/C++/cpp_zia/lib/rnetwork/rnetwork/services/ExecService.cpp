#include "ExecService.hpp"

rnetwork::services::ExecService rnetwork::services::ExecService::_instance;

void rnetwork::services::ExecService::update() {}

rnetwork::services::ExecService::ExecService() :
        _name("ExecService") {}

const std::string &rnetwork::services::ExecService::name() const {
    return _name;
}

rnetwork::services::ExecService &rnetwork::services::ExecService::Instance() {
    return _instance;
}
