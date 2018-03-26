#include <rnetwork/services/ExecService.hpp>
#include "InfiniteTask.hpp"

bool rnetwork::tasks::InfiniteTask::available() const {
    return false;
}

void rnetwork::tasks::InfiniteTask::registerService() const {
}

void rnetwork::tasks::InfiniteTask::unregisterService() const {
}

void rnetwork::tasks::InfiniteTask::operator()() {
}

rnetwork::services::IService &rnetwork::tasks::InfiniteTask::service() const {
    return services::ExecService::Instance();
}
