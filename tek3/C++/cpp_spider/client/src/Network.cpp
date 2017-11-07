/*
** Network.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/Network.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:15:04 2017 Gauthier Cler
** Last update Sun Oct 08 22:15:05 2017 Gauthier Cler
*/

#include <boost/property_tree/json_parser.hpp>
#include <chrono>
#include <iostream>
#include "CommunicationManager.hpp"
#include "Network.hpp"
#include <fstream>
#include <thread>

Client::Network::Network(const std::string &name, CommunicationManager &cm, Client::AOutStream::StreamType type,
			 const std::string &ip, const unsigned short &port)
		: AOutStream(name, cm, type), _net(Spider::Network::Client::connect(ip, port, false)), _state(State::OK), _ping(std::chrono::system_clock::now()) {
  _net->setDataCallback(std::bind(&Client::Network::handleData, this, std::placeholders::_1));
  _listenerThread = std::thread(&Client::Network::listen, this);
}

void Client::Network::sendPing() {
  boost::property_tree::ptree json;
  long long int timestamp =
    std::chrono::duration_cast<std::chrono::milliseconds>
      (std::chrono::system_clock::now().time_since_epoch()).count();
  std::ostringstream out;

  json.put("type", "PING");
  json.put("data", timestamp);
  _state = State::WAITING;
  boost::property_tree::json_parser::write_json(out, json);
  write(out.str());
  _ping = std::chrono::system_clock::now();
}

bool Client::Network::isAlive() {
  if (_state == State::OK)
    sendPing();
  else if (_state == State::WAITING && isTimingOut())
    _state = State::DISCONNECTED;
  return (_state != State::DISCONNECTED);
}

bool Client::Network::write(const std::string &data) {
  if (_state != State::DISCONNECTED) {
    try {
      _net->syncSend(data);
    } catch (std::exception &e) {
      std::cout << "Got exception : " << e.what() << std::endl;
      _state = State::DISCONNECTED;
      return false;
    } catch (...) {
      std::cout << "Unknown exception" << std::endl;
      _state = State::DISCONNECTED;
      return false;
    }
  }
  return (_state != State::DISCONNECTED);
}

bool Client::Network::isOpen() const {
  return (_state != State::DISCONNECTED);
}

void Client::Network::handleData(std::string &&data) {
  boost::property_tree::ptree json;
  std::istringstream iData(data);

  boost::property_tree::json_parser::read_json(iData, json);
  std::cout << iData.str() << std::endl;
  if (json.get<std::string>("type") == "PONG") {
    _state = State::OK;
  } else
    _cm.addCommand(std::move(json));
}

bool Client::Network::isTimingOut() {
  return (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - _ping).count() >
	  PINGTIMEOUT);
}

bool Client::Network::hasData() {
  return false;
}

const std::string Client::Network::extractData() {
  return std::move(std::string(""));
}

void Client::Network::clear() {

}

void Client::Network::listen() {
  try {
    _net->listen();
  } catch(std::exception &e) {
    std::cout << "Error : " << e.what() << std::endl;
  } catch (...) {
    std::cout << "Unknown exception" << std::endl;
  }
}

Client::Network::~Network() {
  _listenerThread.join();
}
