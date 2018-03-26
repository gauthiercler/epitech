#include "AcceptTask.hpp"

rnetwork::tasks::AcceptTask::AcceptTask(std::shared_ptr<rnetwork::IAcceptor> acceptor, const std::function<void(std::shared_ptr<rnetwork::IClient> client, bool status)> &callback) :
        _acceptor(std::move(acceptor)),
        _callback(callback)
{}

bool rnetwork::tasks::AcceptTask::available() const {
    return service().canAccept(_acceptor);
}

void rnetwork::tasks::AcceptTask::registerService() const {
    service().registerAcceptor(_acceptor);
}

void rnetwork::tasks::AcceptTask::unregisterService() const {
    service().unregisterAcceptor(_acceptor);
}

rnetwork::services::NetworkService &rnetwork::tasks::AcceptTask::service() const {
    return rnetwork::services::NetworkService::Instance();
}

void rnetwork::tasks::AcceptTask::operator()() {
    bool status;
    auto client = _acceptor->accept(status);
    _callback(client, status);
}
