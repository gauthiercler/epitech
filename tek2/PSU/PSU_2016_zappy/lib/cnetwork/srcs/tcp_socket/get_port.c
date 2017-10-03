/*
** get_port.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/get_port.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 12 12:26:52 2017 Antoine FORET
** Last update Fri May 12 12:26:52 2017 Antoine FORET
*/

#include	"tcp_socket.h"

uint16_t	tcp_socket_get_port(t_tcp_socket *self)
{
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  if (getsockname(self->socket,
		  (SOCKADDR*)(&info), &info_size) == SOCKET_ERROR)
    return (0);
  else
    return (ntohs(info.sin_port));
}