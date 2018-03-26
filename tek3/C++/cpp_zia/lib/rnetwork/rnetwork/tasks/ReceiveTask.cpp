#include "ReceiveTask.hpp"

rnetwork::tasks::ReceiveTask::ReceiveTask(std::shared_ptr<rnetwork::IReceiver> receiver, const std::function<void(rnetwork::packet::PacketBase &packet, bool status)> &callback) :
        _receiver(std::move(receiver)),
        _callback(callback) {}

rnetwork::tasks::ReceiveTask::ReceiveTask(const rnetwork::tasks::ReceiveTask &receiveTask) :
        _receiver(receiveTask._receiver),
        _callback(receiveTask._callback) {}

bool rnetwork::tasks::ReceiveTask::available() const {
    return service().canReceive(_receiver);
}

void rnetwork::tasks::ReceiveTask::registerService() const {
    service().regiserReciver(_receiver);
}

void rnetwork::tasks::ReceiveTask::unregisterService() const {
    service().unregisterReciver(_receiver);
}

rnetwork::services::NetworkService &rnetwork::tasks::ReceiveTask::service() const {
    return rnetwork::services::NetworkService::Instance();
}

void rnetwork::tasks::ReceiveTask::operator()() {
    bool status;
    auto packet = _receiver->receive(status);
    _callback(*packet, status);
}
