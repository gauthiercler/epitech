/*
** AOutStream.hpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/AOutStream.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:10:23 2017 Gauthier Cler
** Last update Sun Oct 08 22:10:23 2017 Gauthier Cler
*/

#ifndef CPP_SPIDER_IOUTSTREAM_HPP
#define CPP_SPIDER_IOUTSTREAM_HPP

#include	"Error.hpp"
#include       	<string>

namespace 	Client {

  class 	CommunicationManager;

  class 	AOutStream {

  public:

    enum class	StreamType {
      NETWORK,
      FILE
    };

    explicit AOutStream(const std::string &name, CommunicationManager &cm, StreamType type);
    virtual ~AOutStream() = default;

    virtual bool write(const std::string &data) = 0;
    virtual bool isAlive() = 0;
    virtual bool isOpen() const = 0;
    virtual bool hasData() = 0;
    virtual void clear() = 0;
    virtual const std::string extractData() = 0;

    const std::string &getName() const;

  protected:

    std::string _name;
    CommunicationManager &_cm;
    StreamType _type;

  };


}

#endif //CPP_SPIDER_IOUTSTREAM_HPP
