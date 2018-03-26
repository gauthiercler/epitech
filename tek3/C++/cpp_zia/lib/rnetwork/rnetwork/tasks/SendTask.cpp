#include "SendTask.hpp"

rnetwork::tasks::SendTask::SendTask(std::shared_ptr<rnetwork::ISender> sender,
                                    std::shared_ptr<rnetwork::packet::IPacket> packet,
                                    const std::function<void(bool)> &callback) :
        _callback(callback),
        _packet(std::move(packet)),
        _sender(std::move(sender)) {}

bool rnetwork::tasks::SendTask::available() const {
    return service().canSend(_sender);
}

void rnetwork::tasks::SendTask::registerService() const {
    service().registerSender(_sender);
}

void rnetwork::tasks::SendTask::unregisterService() const {
    service().unregisterSender(_sender);
}

rnetwork::services::NetworkService &rnetwork::tasks::SendTask::service() const {
    return rnetwork::services::NetworkService::Instance();
}

void rnetwork::tasks::SendTask::operator()() {
    bool status = _sender->send(*_packet);
    _callback(status);
}
