/*
** portability.h for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/includes/portability.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:22:03 2017 Antoine FORET
** Last update Thu Apr 27 08:22:03 2017 Antoine FORET
*/

#ifndef CPP_LIBS_PORTABILITY_H_
# define CPP_LIBS_PORTABILITY_H_

# ifdef WIN32

#  include		<winsock2.h>

#  define		SOCK_INT	(0)

# elif defined (linux)

#  include		<sys/types.h>
#  include		<sys/socket.h>
#  include		<netinet/in.h>
#  include		<arpa/inet.h>
#  include		<unistd.h>
#  include		<netdb.h>

#  define		SOCKET		int
#  define		SOCKADDR_IN	struct sockaddr_in
#  define		SOCKADDR	struct sockaddr
#  define		IN_ADDR		struct in_addr

#  define		INVALID_SOCKET	(-1)
#  define		SOCKET_ERROR	(-1)
#  define		closesocket(s)	(close(s))

#  define		SOCK_INT(sock)	(sock)

# endif

#endif /* !CPP_LIBS_PORTABILITY_H_ */
