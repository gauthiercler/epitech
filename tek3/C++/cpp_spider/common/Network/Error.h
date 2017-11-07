#ifndef        CPP_SPIDER_NETWORK_ERROR_H_
# define        CPP_SPIDER_NETWORK_ERROR_H_

#include <Error.hpp>

namespace Network
{
  class NetworkError : public Spider::Error
  {
  public:
      explicit NetworkError(std::string const &message) : Error(message) {};
  };
}

#endif        /* !CPP_SPIDER_NETWORK_ERROR_H_ */
