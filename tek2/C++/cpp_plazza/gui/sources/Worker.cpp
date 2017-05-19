/*
** Worker.cpp for cpp_plazza in /home/gogo/rendu/tek2/cpp_plazza/includes/Worker.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 16 18:55:38 2017 Gauthier Cler
** Last update Sun Apr 16 18:55:40 2017 Gauthier Cler
*/

#include "Worker.hpp"

plazza::Worker::Worker() : _thread(Thread()), _busy(false){
  this->_regexes = {
    {Information::PHONE_NUMBER, std::regex("(?:[0-9]{2} ?){5}")},
    {Information::EMAIL_ADDRESS, std::regex("[a-zA-Z0-9_.]+@[a-zA-Z0-9_.]+\\.[a-zA-Z]+")},
    {Information::IP_ADDRESS, std::regex("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)")}
  };
}

plazza::Thread &plazza::Worker::getThread() const {
  return const_cast<Thread&>(this->_thread);
}

bool plazza::Worker::isBusy() const {
  return this->_busy;
}

void plazza::Worker::setBusy(const bool busy) {
  this->_busy = busy;
}

void plazza::Worker::performJob(const std::string &fileName, const Information type) {
  std::string key;

  this->_file.load(fileName);
  if (this->_file.isOpen()) {
    this->setFileBuffer(this->_file.getBuffer());
    this->searchResult(type);
    if (this->_results.size() == 0){
      this->_cracker.run(this->_fileBuffer);
      key = this->_cracker.getKeyXor();
      this->_xor.setKey(key);
      this->_xor >> this->_fileBuffer;
      this->searchResult(type);
      this->_xor << this->_fileBuffer;
      if (this->_results.size() == 0 && key.size() == 1) {
	this->_caesar.setMoved(this->_cracker.getKeyCaesar());
	this->_caesar >> this->_fileBuffer;
	this->searchResult(type);
	this->_caesar << this->_fileBuffer;
      }
    }
  }
//  this->display();
}

void plazza::Worker::display() const {
  for (auto &result : this->_results)
    std::cout << result << std::endl;
}

void plazza::Worker::searchResult(const Information type) {
  std::smatch sm;
  std::string buffer;

  this->_results.clear();
  auto regex = this->_regexes.find(type);
  buffer = this->_fileBuffer;
  if (regex != this->_regexes.end()) {
    while (std::regex_search(buffer, sm, regex->second)) {
      this->_results.push_back(sm.str());
      buffer = sm.suffix();
    }
  }
}

void plazza::Worker::setFileBuffer(const std::string &buffer) {
  this->_fileBuffer = buffer;
}

plazza::Worker::Worker(const plazza::Worker &) : _busy(false){
  this->_regexes = {
    {Information::PHONE_NUMBER, std::regex("(?:[0-9]{2} ?){5}")},
    {Information::EMAIL_ADDRESS, std::regex("[a-zA-Z0-9_.]+@[a-zA-Z0-9_.]+\\.[a-zA-Z]+")},
    {Information::IP_ADDRESS, std::regex("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)")}
  };
}

plazza::Worker::Worker(plazza::Worker &) : _busy(false){
  this->_regexes = {
    {Information::PHONE_NUMBER, std::regex("(?:[0-9]{2} ?){5}")},
    {Information::EMAIL_ADDRESS, std::regex("[a-zA-Z0-9_.]+@[a-zA-Z0-9_. ]+\\.[a-zA-Z]+")},
    {Information::IP_ADDRESS, std::regex("(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)")}
  };
}

std::vector<std::string> plazza::Worker::getResults(void) const {
  return this->_results;
}
