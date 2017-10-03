/*
** get_ip.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/get_ip.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 11 13:51:50 2017 Antoine FORET
** Last update Thu May 11 13:51:50 2017 Antoine FORET
*/

#include	"tcp_socket.h"

char		*tcp_socket_get_ip(t_tcp_socket *self)
{
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  if (getsockname(self->socket,
		  (SOCKADDR *)(&info), &info_size) == SOCKET_ERROR)
    return (NULL);
  else
    return (inet_ntoa(info.sin_addr));
}