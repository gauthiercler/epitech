#pragma once

#define MAX_UDP_SIZE (1024)
#define MAX_TCP_SIZE (1024)
#define NET_TIMEOUT (100)

#include "config/Export.hpp"

namespace rnetwork
{
    bool RNETWORK_API init();
    void RNETWORK_API clean();
}

#ifdef WIN32

#include <winsock2.h>

#define MSG_NOSIGNAL 0

typedef long int ssize_t;
typedef int socklen_t;

#elif defined (linux)

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <netdb.h>
# define INVALID_SOCKET (-1)
# define SOCKET_ERROR (-1)
# define closesocket(s) close(s)

typedef		int			SOCKET;
typedef		struct sockaddr_in	SOCKADDR_IN;
typedef		struct sockaddr		SOCKADDR;
typedef		struct in_addr		IN_ADDR;

#else

# error not defined for this platform

#endif