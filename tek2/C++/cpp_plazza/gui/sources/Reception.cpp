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
  if (closing_office != this->_offices.end())
    this->_processPool.kill(*closing_office);
  this->_offices.erase(closing_office);
}

void plazza::Reception::run(int ac, char *av[]) {
  QApplication app(ac, av);
  MainWindow window;
  window.setWindowTitle("Plazza");
  window.show();
  Command	command;

  while (window.isVisible()) {
    app.processEvents();
    window.getUi()->tableWidget->setRowCount(this->_offices.size());
    if (this->_offices.size() > 0 && window.getUi()->tableWidget->rowCount() > 0) {
      for (size_t idx = 0; idx < this->_offices.size(); idx++) {
	window.getUi()->tableWidget->setItem(idx, 0, new QTableWidgetItem(std::to_string(this->_offices.at(idx).getPid()).c_str()));
	window.getUi()->tableWidget->setItem(idx, 1, new QTableWidgetItem(std::to_string((this->_offices.at(idx).getFreeTaskSpots() <= this->getOfficeCapacity())
      ? this->getOfficeCapacity() : this->getOfficeCapacity() * 2 - this->_offices.at(idx).getFreeTaskSpots()).c_str()));
	window.getUi()->tableWidget->setItem(idx, 2, new QTableWidgetItem(std::to_string((this->_offices.at(idx).getFreeTaskSpots() < this->getOfficeCapacity() * 2)
											 ? this->getOfficeCapacity() * 2 - this->_offices.at(idx).getFreeTaskSpots() : 0).c_str()));
      }
    }
    if (window.isSended()) {
      command.setArgs({window.getFilename()});
      command.setType(window.getTypes().at(window.getUi()->comboBox->currentIndex()));
      for (auto &it : command.getArgs())
	this->assignTask(command.getType(), it);
      window.reset();
    }
    this->flushServerData(window);
  }
  window.close();
  this->close(window);
}

void plazza::Reception::close(MainWindow &window) {
  while (this->_offices.size()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->flushServerData(window);
  }
}

void plazza::Reception::flushServerData(MainWindow &window) {
  Data		data;

  while (this->_serverStream.transfertData(data) > 0) {
    switch (data.type) {
      case plazza::COMMAND :

	if (std::string(data.action) == plazza::DISPLAY) {
	  window.getUi()->textEdit->append(QObject::tr(data.value));
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
