/*
** Office.cpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/sources/Office.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 11 21:57:27 2017 Anas Buyumad
** Last update Tue Apr 11 21:57:27 2017 Anas Buyumad
*/

#include		<unistd.h>
#include <Config.hpp>
#include		"Office.hpp"

plazza::Office::Office(const unsigned int capacity) : _pid(0), _capacity(capacity), _workersPool(std::bind(&Office::workerCallback, this, std::placeholders::_1)),  _freeTaskSpots(capacity * 2) {
}

plazza::Office::~Office() {
}

pid_t plazza::Office::getPid() const {
  return this->_pid;
}

size_t plazza::Office::getCapacity() const {
  return this->_capacity;
}

const std::string &plazza::Office::getPrivateKey() const {
  return this->_privateKey;
}

std::time_t plazza::Office::getUnactiveSpan() const {
  return this->_unactiveSpan;
}

size_t plazza::Office::getFreeWorkers() const {
//  if (this->_workersPool.getNbFreeWorkers() == 0) {
//    if (this->_workersPool.getQueueLength() < this->getCapacity()) {
//      return this->getCapacity() - this->_workersPool.getQueueLength();
//    }
//  }
  return this->_workersPool.getNbFreeWorkers();
}

size_t plazza::Office::getFreeTaskSpots() const {
  return this->_freeTaskSpots;
}

void plazza::Office::setPid(const pid_t pid) {
  this->_pid = pid;
}

void plazza::Office::setCapacity(const unsigned int capacity) {
  this->_capacity = capacity;
}

void plazza::Office::setPrivateKey(const std::string &key) {
  this->_privateKey = key;
}

void plazza::Office::setFreeTaskSpots(const size_t amount) {
  this->_freeTaskSpots = amount;
}

void plazza::Office::init(void) {
  this->_serverStream.connect(plazza::SERVER_FIFO, plazza::ConnectorPipe::OUT);
  this->setPid(getpid());
  this->setPrivateKey("Office" + std::to_string(this->getPid()));
  this->_privateStream.create(this->getPrivateKey());
  this->_privateStream.connect(this->getPrivateKey(), plazza::ConnectorPipe::IN);
  this->_workersPool.createWorkers(this->_capacity);
}

void plazza::Office::run(void) {
  this->_unactiveSpan = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  while (this->isActive())
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->getTask();
  }
  this->close();
}

void plazza::Office::close(void) {
  Data		data;

  std::memset(&data, 0, sizeof(Data));
  data.sender_id = this->getPid();
  data.type = SIGNAL;
  std::sprintf(data.action, "%s", plazza::OFFICE_SHUTDOWN.c_str());
  std::sprintf(data.value, " ");
  this->_serverStream.transfertData(data);
  this->_workersPool.stop();
  this->_serverStream.disconnect();
  this->_privateStream.disconnect();
  this->_privateStream.destroy();
  std::exit(0);
}

plazza::Office::Office(plazza::Office &&office) :

  _pid(std::move(office._pid)),
  _capacity(std::move(office._capacity)),
  _unactiveSpan(std::move(office._unactiveSpan)),
  _serverStream(std::move(office._serverStream)),
  _privateStream(std::move(office._privateStream)),
  _workersPool(std::move(office._workersPool)),
  _freeTaskSpots(std::move(office._freeTaskSpots)),
  _privateKey(std::move(office._privateKey))
  {

  }

void plazza::Office::getTask(void) {
  Data		data;

  while (this->_privateStream.transfertData(data) > 0) {
    switch (data.type) {

      case plazza::COMMAND :

	this->assignTask(data);

	break ;

      case plazza::SIGNAL :

	break ;
    }
    std::memset(&data.action, 0, sizeof(data.action));
    std::memset(&data.value, 0, sizeof(data.value));
    data.sender_id = -1;
  }
}

void plazza::Office::assignTask(const Data &data) {
  this->_unactiveSpan = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  this->setFreeTaskSpots(this->getFreeTaskSpots() - 1);
  this->_workersPool.addJob(data.value, static_cast<Information>(std::stoi(data.action)));
  this->completeTask();
}

void plazza::Office::completeTask(void) {
  Data		data;

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::memset(&data, 0, sizeof(Data));
  this->setFreeTaskSpots(this->getFreeTaskSpots() + 1);
  data.sender_id = this->getPid();
  data.type = SIGNAL;
  std::sprintf(data.action, "%s", plazza::TASK_COMPLETED.c_str());
  std::sprintf(data.value, " ");
  this->_serverStream.transfertData(data);
}

plazza::Office &plazza::Office::operator=(const plazza::Office &office) {
  this->_pid = office._pid;
  this->_capacity = office._capacity;
  this->_freeTaskSpots = office._freeTaskSpots;
  this->_privateKey = office._privateKey;
  return *this;
}

bool plazza::Office::isActive(void) const {
  if (this->_workersPool.getNbFreeWorkers() == this->_capacity && this->_workersPool.getQueueLength() == 0) {
    if (std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - this->_unactiveSpan >= 5) {
      return false;
    }
  }
  return true;
}

void plazza::Office::workerCallback(const std::vector<std::string> &results) const {
  Data		data;

  std::memset(&data, 0, sizeof(Data));
  data.sender_id = this->getPid();
  data.type = COMMAND;

  for (auto &it : results) {
    std::sprintf(data.action, "%s", plazza::DISPLAY.c_str());
    std::sprintf(data.value, "%s", it.c_str());

    this->_serverStream.transfertData(data);
  }
}

