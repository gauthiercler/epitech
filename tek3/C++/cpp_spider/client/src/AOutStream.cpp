#include "AOutStream.hpp"

Client::AOutStream::AOutStream(const std::string &name, CommunicationManager &cm, StreamType type)
: _name(name), _cm(cm), _type(type)
{}

const std::string &Client::AOutStream::getName() const {
  return (_name);
}
