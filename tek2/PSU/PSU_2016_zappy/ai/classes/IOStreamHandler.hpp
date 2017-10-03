/*
** IOStreamHandler.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/IOStreamHandler.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jun 24 09:40:04 2017 Anas Buyumad
** Last update Sat Jun 24 09:40:05 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_IOSTREAMHANDLER_HPP
#define PSU_2016_ZAPPY_IOSTREAMHANDLER_HPP

#include <boost/thread.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>
#include <queue>
#include "AResponse.hpp"
#include "ResponseHandler.hpp"
#include "Socket.hpp"

namespace ai {

  extern bool			running;

  class IOStreamHandler {

  public:

    IOStreamHandler();
    ~IOStreamHandler();

    boost::asio::io_service	&getIOService(void);
    Socket			&getSocket(void);

    void			runIOService(void);
    void			runIOServiceAsync(void);
    void			pollIOService(void);
    void			resetIOService(void);

    void			connect(const std::string &host, const std::string &port);
    void			disconnect(void);
    void			abortConnection(const std::string &reason);
    void			startIOReadProcesser(void);
    void			IOReadProcesser(const boost::system::error_code &error, std::size_t bytesTransferred);
    void			writeData(const std::string &response);

    ResponseHandler		&getResponseHandler(void);

    IOStreamHandler(const IOStreamHandler&) = delete;
    IOStreamHandler& operator=(const IOStreamHandler&) = delete;
    static IOStreamHandler	&get();

  private:

    static IOStreamHandler		_singleton;
    ResponseHandler			_responseHandler;

    boost::asio::io_service		_ioService;

    Socket				_IOStream;
    boost::asio::streambuf		_bufferStream;
    const std::string			_delimiter = "\n";
  };

}



#endif //PSU_2016_ZAPPY_RESPONSEHANDLER_HPP