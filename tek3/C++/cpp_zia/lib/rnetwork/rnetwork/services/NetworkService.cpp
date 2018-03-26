#include <algorithm>
#include <cstring>
#include <iostream>
#include "NetworkService.hpp"

rnetwork::services::NetworkService rnetwork::services::NetworkService::_instance;

rnetwork::services::NetworkService::NetworkService() :
        _name("NetworkService") {}

void rnetwork::services::NetworkService::registerSender(std::shared_ptr<rnetwork::ISender> sender) {
    std::lock_guard<std::mutex> lock(_mutex);
    _senders.emplace_back(sender);
}

void rnetwork::services::NetworkService::unregisterSender(std::shared_ptr<rnetwork::ISender> sender) {
    std::lock_guard<std::mutex> lock(_mutex);
    auto it = std::find_if(_senders.begin(), _senders.end(), [&](std::shared_ptr<rnetwork::ISender> it) {
        return it == sender;
    });
    if (it != _senders.end())
        _senders.erase(it);
}

void rnetwork::services::NetworkService::regiserReciver(std::shared_ptr<rnetwork::IReceiver> reciver) {
    std::lock_guard<std::mutex> lock(_mutex);
    _receivers.emplace_back(reciver);
}

void rnetwork::services::NetworkService::unregisterReciver(std::shared_ptr<rnetwork::IReceiver> reciver) {
    std::lock_guard<std::mutex> lock(_mutex);
    auto it = std::find_if(_receivers.begin(), _receivers.end(), [&](std::shared_ptr<rnetwork::IReceiver> it) {
        return it == reciver;
    });
    if (it != _receivers.end())
        _receivers.erase(it);
}

const std::string &rnetwork::services::NetworkService::name() const {
    return _name;
}

void rnetwork::services::NetworkService::updateFdSets() {
    FD_ZERO(&_readFds);
    FD_ZERO(&_writeFds);
    _highestFd = -1;
    for (const auto &receiver : _receivers) {
        FD_SET(receiver->socket(), &_readFds);
        if (receiver->socket() > _highestFd)
            _highestFd = receiver->socket();
    }
    for (const auto &sender : _senders) {
        FD_SET(sender->socket(), &_writeFds);
        if (sender->socket() > _highestFd)
            _highestFd = sender->socket();
    }
    for (const auto &acceptor : _acceptors) {
        FD_SET(acceptor->socket(), &_readFds);
        if (acceptor->socket() > _highestFd)
            _highestFd = acceptor->socket();
    }
}

void rnetwork::services::NetworkService::update() {
    std::lock_guard<std::mutex> lock(_mutex);
    int nbChange;
    timeval timeout{};

    updateFdSets();
    if (_acceptors.size() == 0 && _receivers.size() == 0 && _senders.size() == 0)
        return;
    timeout.tv_usec = NET_TIMEOUT;
    nbChange = ::select(this->_highestFd + 1, &_readFds, &_writeFds, nullptr, &timeout);
    if (nbChange < 0) {
		if (errno != EINTR)
			throw std::runtime_error(std::string("Unable to listen to global network : ") + strerror(errno));
        else {
            FD_ZERO(&_readFds);
            FD_ZERO(&_writeFds);
        }
    }
}

bool rnetwork::services::NetworkService::canSend(std::shared_ptr<const rnetwork::ISender> sender) {
    std::lock_guard<std::mutex> lock(_mutex);

    auto it = std::find_if(_senders.begin(), _senders.end(), [&](std::shared_ptr<rnetwork::ISender> it) {
        return it == sender;
    });
    if (it != _senders.end() && FD_ISSET((*it)->socket(), &_writeFds)) {
        FD_CLR((*it)->socket(), &_writeFds);
        return true;
    } else
        return false;
}

bool rnetwork::services::NetworkService::canReceive(std::shared_ptr<const rnetwork::IReceiver> receiver) {
    std::lock_guard<std::mutex> lock(_mutex);

    auto it = std::find_if(_receivers.begin(), _receivers.end(), [&](std::shared_ptr<rnetwork::IReceiver> it) {
        return it == receiver;
    });
    if (it != _receivers.end() && FD_ISSET((*it)->socket(), &_readFds)) {
        FD_CLR((*it)->socket(), &_readFds);
        return true;
    } else
        return false;
}

rnetwork::services::NetworkService &rnetwork::services::NetworkService::Instance() {
    return _instance;
}

void rnetwork::services::NetworkService::registerAcceptor(std::shared_ptr<rnetwork::IAcceptor> acceptor) {
    std::lock_guard<std::mutex> lock(_mutex);
    _acceptors.emplace_back(acceptor);
}

void rnetwork::services::NetworkService::unregisterAcceptor(std::shared_ptr<rnetwork::IAcceptor> acceptor) {
    std::lock_guard<std::mutex> lock(_mutex);
    auto it = std::find_if(_acceptors.begin(), _acceptors.end(), [&](std::shared_ptr<rnetwork::IAcceptor> it) {
        return it == acceptor;
    });
    if (it != _acceptors.end())
        _acceptors.erase(it);
}

bool rnetwork::services::NetworkService::canAccept(std::shared_ptr<const rnetwork::IAcceptor> acceptor) {
    std::lock_guard<std::mutex> lock(_mutex);

    auto it = std::find_if(_acceptors.begin(), _acceptors.end(), [&](std::shared_ptr<rnetwork::IAcceptor> it) {
        return it == acceptor;
    });
    if (it != _acceptors.end() && FD_ISSET((*it)->socket(), &_readFds)) {
        FD_CLR((*it)->socket(), &_readFds);
        return true;
    } else
        return false;
}
