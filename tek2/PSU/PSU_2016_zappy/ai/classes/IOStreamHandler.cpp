/*
** ResponseHandler.cpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/ResponseHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 23 15:12:31 2017 Anas Buyumad
** Last update Fri Jun 23 15:12:32 2017 Anas Buyumad
*/

#include <iostream>
#include <FSM/FSM.hpp>
#include "IOStreamHandler.hpp"
#include "SelectType.hpp"

ai::IOStreamHandler ai::IOStreamHandler::_singleton;

ai::IOStreamHandler::IOStreamHandler() :
  _IOStream(_ioService) {
}

ai::IOStreamHandler::~IOStreamHandler() {

}

boost::asio::io_service &ai::IOStreamHandler::getIOService(void) {
  return _ioService;
}

ai::Socket &ai::IOStreamHandler::getSocket(void) {
  return _IOStream;
}

void ai::IOStreamHandler::runIOService(void) {
  _ioService.run();
}

void ai::IOStreamHandler::runIOServiceAsync(void) {
  boost::thread		async_thread(boost::bind(&boost::asio::io_service::run, &_ioService));
  // Detach ?
}

void ai::IOStreamHandler::pollIOService(void) {
  _ioService.poll();
}

void ai::IOStreamHandler::resetIOService(void) {
  _ioService.reset();
}

void ai::IOStreamHandler::connect(const std::string &host,
				  const std::string &port) {
  _IOStream.connect(host, port);
}

void ai::IOStreamHandler::disconnect(void) {
  std::cout << std::endl << "->   IOStreamHandler :: Disconnecting ResponseStream   <-" << std::endl;
  _IOStream.disconnect();
  std::exit(0);
}

void ai::IOStreamHandler::abortConnection(const std::string &reason) {
  this->disconnect();
  ai::running = false;
  throw Error("Aborted connection :: " + reason + ".");
}

void ai::IOStreamHandler::startIOReadProcesser(void) {

  if (_IOStream.get().is_open()) {
    boost::asio::async_read_until(
      _IOStream.get(),
      _bufferStream,
      _delimiter,
      std::bind(&IOStreamHandler::IOReadProcesser,
		this,
		std::placeholders::_1,
		std::placeholders::_2));
  }
}

void
ai::IOStreamHandler::IOReadProcesser(const boost::system::error_code &error,
				     std::size_t bytesTransferred) {

  if (error) {
    if (error.value() == boost::asio::error::eof) {
      this->disconnect();
    }
    else {
      throw Error("An error occurred while processing the response stream.");
    }
  }
  else {

    _responseHandler.assessReceivedResponse(
      std::string(
	boost::asio::buffers_begin(_bufferStream.data()),
	boost::asio::buffers_begin(_bufferStream.data())
	+ bytesTransferred - _delimiter.size())
    );

    _bufferStream.consume(bytesTransferred);

    this->startIOReadProcesser();
  }
}

void ai::IOStreamHandler::writeData(const std::string &response) {
  if (_IOStream.get().is_open()) {
    if (boost::asio::write(_IOStream.get(), boost::asio::buffer(response + _delimiter)) < response.size() + 1) {
      ai::running = false;
      throw Error("IOStreamHandler :: Couldn't properly write the response.");
    }
  }
}

ai::IOStreamHandler &ai::IOStreamHandler::get() {
  return _singleton;
}

ai::ResponseHandler &ai::IOStreamHandler::getResponseHandler(void) {
  return _responseHandler;
}