#include <iostream>
#include "rnetwork/services/ExecService.hpp"
#include "DelayedTask.hpp"

rnetwork::tasks::DelayedTask::DelayedTask(const std::function<void()> &callback, unsigned long time) :
        _task(callback),
        _start(std::chrono::steady_clock::now()),
        _timeout(time)
{}

bool rnetwork::tasks::DelayedTask::available() const {
    auto current = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = current - _start;
    return duration.count() >= _timeout;
}

void rnetwork::tasks::DelayedTask::operator()() {
    return _task();
}

void rnetwork::tasks::DelayedTask::registerService() const {

}

void rnetwork::tasks::DelayedTask::unregisterService() const {

}

rnetwork::services::IService &rnetwork::tasks::DelayedTask::service() const {
    return rnetwork::services::ExecService::Instance();
}
