/*
** ProcessPool.cpp for cpp_plazza in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_plazza/sources/ProcessPool.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 11 22:21:50 2017 Anas Buyumad
** Last update Tue Apr 11 22:21:50 2017 Anas Buyumad
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<algorithm>
#include        "ProcessManager.hpp"

plazza::ProcessManager::ProcessManager() {
}

plazza::ProcessManager::~ProcessManager() {
}

void plazza::ProcessManager::spawn(plazza::Office &office) {
  pid_t		pid;

  pid = fork();
  if (pid == 0) {
    office.init();
    office.run();
  }
  else if (pid > 0) {
    this->_processes.push_back(pid);
    office.setPid(pid);
    office.setPrivateKey("Office" + std::to_string(pid));
  }
  else {
    throw plazza::Error("Couldn't spawn process.");
  }
}

void plazza::ProcessManager::kill(const plazza::Office &office) {
  int		status;

  auto closing_process = std::find_if(this->_processes.begin(), this->_processes.end(), [&office](const pid_t pid) -> bool { return pid == office.getPid(); });
  waitpid(*closing_process, &status, WUNTRACED | WCONTINUED);
  this->_processes.erase(closing_process);
}
