/*
** CommunicationManager.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/CommunicationManager.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:10:41 2017 Gauthier Cler
** Last update Sun Oct 08 22:10:41 2017 Gauthier Cler
*/

#include "CommunicationManager.hpp"
#include <fstream>
#include <iostream>

void Client::CommunicationManager::initialize() {
	std::cout << "Adding File..." << std::endl;
	this->addStream(std::move(std::make_unique<Client::File>(LOG_FILE, *this, Client::AOutStream::StreamType::FILE, FILE_NAME)));
	std::cout << "Adding Network..." << std::endl;
	this->addStream(std::move(std::make_unique<Client::Network>(SERVER_NAME, *this, Client::AOutStream::StreamType::NETWORK, SERVER_IP, SERVER_PORT)));
	std::cout << "Communication maanager is Initialized" << std::endl;
}

bool Client::CommunicationManager::addStream(std::unique_ptr<Client::AOutStream> stream) {
	auto streamName = (*stream).getName();
	auto streamIterator = std::find_if(_streams.begin(), _streams.end(), [streamName] (std::unique_ptr<Client::AOutStream> &Sstream) { return streamName == (*Sstream).getName(); });

	if (streamIterator != _streams.end()) {
		return false;
	}
	_streams.push_back(std::move(stream));
	return true;
}

std::unique_ptr<Client::AOutStream> &Client::CommunicationManager::getStream(const std::string &name) {
	auto streamIterator = std::find_if(_streams.begin(), _streams.end(), [name] (std::unique_ptr<Client::AOutStream> &Sstream) { return name == (*Sstream).getName(); });

	if (streamIterator == _streams.end()) {
		throw Spider::Error("No such stream");
	}
	return (*streamIterator);
}

bool Client::CommunicationManager::removeStream(const std::string &name) {
	auto streamIterator = std::find_if(_streams.begin(), _streams.end(), [name] (std::unique_ptr<Client::AOutStream> &Sstream) { return name == (*Sstream).getName(); });

	if (streamIterator == _streams.end()) {
		return false;
	}
	_streams.erase(streamIterator);
	return true;
}

bool Client::CommunicationManager::sendDataTo(const std::string &name, const std::string &data) {
	auto streamIterator = std::find_if(_streams.begin(), _streams.end(), [name] (std::unique_ptr<Client::AOutStream> &Sstream) { return name == (*Sstream).getName(); });

	if (streamIterator == _streams.end()) {
		std::cout << "Didn't find Network" << std::endl;
		return false;
	}
	std::cout << "Found Network" << std::endl;
	(*(*streamIterator)).write(data);
	return true;
}

void Client::CommunicationManager::addCommand(boost::property_tree::ptree &command) {
	_commands.push(command);
}

boost::property_tree::ptree Client::CommunicationManager::getCommand() {
  auto command = _commands.front();
  _commands.pop();
  return (command);
}

void Client::CommunicationManager::refreshConnection() {
  for (auto &item : _streams)
	  (*item).isAlive();
}

bool Client::CommunicationManager::hasCommand() const {
  return (!_commands.empty());
}