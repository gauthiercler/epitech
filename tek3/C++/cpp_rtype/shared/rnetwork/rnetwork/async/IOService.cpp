#include <algorithm>
#include <rnetwork/tasks/InfiniteTask.hpp>
#include <iostream>
#include "IOService.hpp"

void rnetwork::async::IOService::registerService(rnetwork::services::IService &service) {
    std::lock_guard<std::mutex> lock(_serviceMutex);

    if (std::find_if(_services.begin(), _services.end(), [&](std::reference_wrapper<rnetwork::services::IService> ref) {
        return ref.get() == service;
    }) == _services.end())
        _services.emplace_back(std::ref(service));
}

void rnetwork::async::IOService::unregisterService(rnetwork::services::IService &service) {
    std::lock_guard<std::mutex> lock(_serviceMutex);
    auto end = std::remove_if(_services.begin(), _services.end(), [&](const rnetwork::services::IService &it) {
        return service == it;
    });
    _services.erase(end, _services.end());
}

void rnetwork::async::IOService::run() {
    _run = true;
    while (!_tasks.empty() && _run) {
        while (execTasks());
        updateServices();
    }
}

void rnetwork::async::IOService::updateServices() {
    if (_serviceMutex.try_lock()) {
        for (auto service : _services)
            service.get().update();
        _serviceMutex.unlock();
    }
}

bool rnetwork::async::IOService::execTasks() {
    bool run = false;
    std::shared_ptr<rnetwork::tasks::ITask> task;

    _taskMutex.lock();
    auto taskIt = std::find_if(_tasks.begin(), _tasks.end(), [&](const std::shared_ptr<rnetwork::tasks::ITask> &task) {
        return task->available();
    });
    if (taskIt != _tasks.end()) {
        task = *taskIt;
        _tasks.erase(taskIt);
        run = true;
    }
    _taskMutex.unlock();
    if (run) {
        (*task)();
        task->unregisterService();
        return true;
    }
    return false;
}

void rnetwork::async::IOService::registerTask(std::shared_ptr<rnetwork::tasks::ITask> task) {
    std::lock_guard<std::mutex> lock(_taskMutex);
    task->registerService();
    registerService(task->service());
    _tasks.emplace_back(task);
}

void rnetwork::async::IOService::unregisterTask(std::shared_ptr<rnetwork::tasks::ITask> task) {
    std::lock_guard<std::mutex> lock(_taskMutex);

    auto it = std::remove_if(_tasks.begin(), _tasks.end(), [&](const std::shared_ptr<rnetwork::tasks::ITask> &it) {
        return task == it;
    });
}

void rnetwork::async::IOService::stop() {
    _run = false;
}

void rnetwork::async::IOService::forceInfinite() {
    auto task = std::make_shared<tasks::InfiniteTask>();
    registerTask(task);
}
