/*
** Reception.cpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/sources/Reception.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 11 21:56:34 2017 Anas Buyumad
** Last update Tue Apr 11 21:56:34 2017 Anas Buyumad
*/

#include	<unistd.h>
#include	<algorithm>
#include	<thread>
#include	<future>
#include	<Utils.hpp>
#include	<Command.hpp>
#include	<CommandManager.hpp>
#include	"Config.hpp"
#include	"Reception.hpp"

plazza::Reception::Reception(const unsigned int officeCapacity) : _officeCapacity(officeCapacity) {
  this->_serverStream.create(plazza::SERVER_FIFO);
  this->_serverStream.connect(plazza::SERVER_FIFO, plazza::ConnectorPipe::IN);
}

plazza::Reception::~Reception() {
  this->_serverStream.disconnect();
  this->_serverStream.destroy();
}

unsigned int plazza::Reception::getOfficeCapacity() const {
  return this->_officeCapacity;
}

void plazza::Reception::createOffice() {
  this->_offices.emplace_back(this->getOfficeCapacity());
  this->_processPool.spawn(this->_offices.back());
}

void plazza::Reception::removeOffice(const pid_t office_id) {
  auto closing_office = std::find_if(this->_offices.begin(), this->_offices.end(), [&office_id](const Office &office) -> bool { return office.getPid() == office_id; });
  this->_processPool.kill(*closing_office);
  this->_offices.erase(closing_office);
}

void plazza::Reception::run() {
  auto future = std::async(std::launch::async, Utils::getLine);
  CommandManager manager;

  while (true) {
    if (future.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
      auto line = future.get();

      if (std::cin.eof())
	break;
      future = std::async(std::launch::async, Utils::getLine);
      auto commands = Utils::explode(line, ';');
      for (auto command : commands)
      {
	manager.parseCommand(command);
	plazza::Command c = manager.getCommand();
	for (auto it : c.getArgs()) {
	  this->assignTask(c.getType(), it);
	}

      }
    }
    this->flushServerData();
  }
  this->close();
}

void plazza::Reception::close() {
  while (this->_offices.size()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->flushServerData();
  }
}

void plazza::Reception::flushServerData() {
  Data		data;

  while (this->_serverStream.transfertData(data) > 0) {
    switch (data.type) {
      case plazza::COMMAND :

	if (std::string(data.action) == plazza::DISPLAY) {
	  std::cout << data.value << std::endl;
	}
	break ;

      case plazza::SIGNAL :

	if (std::string(data.action) == plazza::OFFICE_SHUTDOWN) {
	  this->removeOffice(data.sender_id);
	}

	if (std::string(data.action) == plazza::TASK_COMPLETED) {
	  this->completeTask(data.sender_id);
	}

	break ;
    }
    std::memset(&data.action, 0, sizeof(data.action));
    std::memset(&data.value, 0, sizeof(data.value));
    data.sender_id = -1;
  }
}

void plazza::Reception::sendTask(const plazza::Office &office, const Information type, const std::string &value) {
  Data		task;

  std::memset(&task, 0, sizeof(Data));
  task.sender_id = getpid();
  task.type = COMMAND;
  std::sprintf(task.action, "%d", static_cast<int>(type));
  std::sprintf(task.value, "%s", value.c_str());
  this->_officeStream.connect(office.getPrivateKey(), plazza::ConnectorPipe::OUT);
  this->_officeStream.transfertData(task);
  this->_officeStream.disconnect();
}

void plazza::Reception::assignTask(const Information type, const std::string &value) {
  for (auto &it : this->_offices) {
    if (it.getFreeTaskSpots() > 0) {
      it.setFreeTaskSpots(it.getFreeTaskSpots() - 1);
      this->sendTask(it, type, value);
      return ;
    }
  }
  this->createOffice();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  this->_offices.back().setFreeTaskSpots(this->_offices.back().getFreeTaskSpots() - 1);
  this->sendTask(this->_offices.back(), type, value);
}

void plazza::Reception::completeTask(const pid_t office_id) {
  auto doneOffice = std::find_if(this->_offices.begin(), this->_offices.end(), [&office_id](const Office &office) -> bool { return office.getPid() == office_id; });
  (*doneOffice).setFreeTaskSpots((*doneOffice).getFreeTaskSpots() + 1);
}
