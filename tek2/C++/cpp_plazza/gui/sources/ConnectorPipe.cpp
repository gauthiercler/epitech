/*
** NamedPipe.cpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/sources/NamedPipe.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 12 16:00:25 2017 Anas Buyumad
** Last update Wed Apr 12 16:00:26 2017 Anas Buyumad
*/

#include <sys/stat.h>
#include <Error.hpp>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <thread>
#include                "ConnectorPipe.hpp"

plazza::ConnectorPipe::ConnectorPipe() : _fd(-1) {

}

plazza::ConnectorPipe::~ConnectorPipe() {

}

void plazza::ConnectorPipe::setFd(const int fd) {
  this->_fd = fd;
}

int plazza::ConnectorPipe::getFd(void) const {
  return this->_fd;
}

void plazza::ConnectorPipe::setName(const std::string &name) {
  this->_name = name;
}

const std::string &plazza::ConnectorPipe::getName(void) const {
  return this->_name;
}

void plazza::ConnectorPipe::setMode(const plazza::ConnectorPipe::Fmode mode) {
  this->_mode = mode;
}

const plazza::ConnectorPipe::Fmode &plazza::ConnectorPipe::getMode(void) const {
  return this->_mode;
}

void plazza::ConnectorPipe::create(const std::string &name) {
  if (mkfifo(name.c_str(), 0644) == -1) {
    std::cout << "Error : " << strerror(errno) << std::endl;
    throw plazza::Error("Couldn't create named pipe " + name + ".");
  }
}

void
plazza::ConnectorPipe::connect(const std::string &name, const plazza::ConnectorPipe::Fmode mode) {
  switch (mode) {
    case IN :
      this->setFd(open(name.c_str(), O_RDONLY | O_NONBLOCK));
      if (this->getFd() == -1) {
	throw plazza::Error("Couldn't open " + name + ".");
      }
      break ;
    case OUT :
      this->setFd(open(name.c_str(), O_WRONLY | O_NONBLOCK));
      if (this->getFd() == -1) {
	throw plazza::Error("Couldn't open " + name + ".");
      }
      break ;
  }
  this->setName(name);
  this->setMode(mode);
}

void plazza::ConnectorPipe::disconnect() {
  if (this->getFd() != -1) {
    if (close(this->getFd()) == -1) {
      std::cout << "Error : " << strerror(errno) << std::endl;
      throw plazza::Error("Couldn't close fd " + std::to_string(this->getFd()) + ".");
    }
    this->setFd(-1);
  }
}

void plazza::ConnectorPipe::destroy() {
  if (this->getFd() != -1) {
    this->disconnect();
  }
  if (unlink(this->getName().c_str()) == -1) {
    throw plazza::Error("Couldn't unlink " + this->getName() + ".");
  }
}

ssize_t plazza::ConnectorPipe::sendData(const plazza::Data &data, const int callback_depth) const {
  ssize_t 	writtenBytes;

  if (callback_depth <= 0) {
    return -1;
  }
  try {
    writtenBytes = write(this->getFd(), &data, sizeof(data));
    if (writtenBytes == -1) {
      throw plazza::Error("Couldn't send data through pipe " + std::to_string(this->getFd()) + ".");
    }
  }
  catch (plazza::Error) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return this->sendData(data, callback_depth - 1);
  }
  return writtenBytes;
}

ssize_t plazza::ConnectorPipe::receiveData(plazza::Data &data) const {
  ssize_t 	readBytes;

  readBytes = read(this->getFd(), &data, sizeof(data));
  if (readBytes == -1 && errno != EAGAIN)
    throw plazza::Error("Couldn't read data through pipe " + std::to_string(this->getFd()) + ".");
  return (readBytes == -1 && errno == EAGAIN) ? 0 : readBytes;
}

ssize_t plazza::ConnectorPipe::transfertData(plazza::Data &data) const {
  if (this->getMode() == plazza::ConnectorPipe::IN) {
    return this->receiveData(data);
  }
  else if (this->getMode() == plazza::ConnectorPipe::OUT) {
    return this->sendData(data, 10);
  }
  return -1;
}
