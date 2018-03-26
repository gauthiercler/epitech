#include "ExecTask.hpp"
#include "rnetwork/services/ExecService.hpp"

rnetwork::tasks::ExecTask::ExecTask(const std::function<void()> &task) : _task(task) {}

bool rnetwork::tasks::ExecTask::available() const {
    return true;
}

void rnetwork::tasks::ExecTask::operator()() {
    return _task();
}

void rnetwork::tasks::ExecTask::unregisterService() const {
}

void rnetwork::tasks::ExecTask::registerService() const {
}

rnetwork::services::IService &rnetwork::tasks::ExecTask::service() const {
    return rnetwork::services::ExecService::Instance();
}
