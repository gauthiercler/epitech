/*
** get_foreign_port.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/tcp_socket/get_foreign_port.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 17 15:14:59 2017 Antoine FORET
** Last update Wed May 17 15:14:59 2017 Antoine FORET
*/

#include	"tcp_socket.h"

uint16_t	tcp_socket_get_foreign_port(t_tcp_socket *self)
{
  SOCKADDR_IN	info;
  unsigned int	info_size;

  info_size = sizeof(info);
  if (getpeername(self->socket,
		  (SOCKADDR*)(&info), &info_size) == SOCKET_ERROR)
    return (0);
  else
    return (ntohs(info.sin_port));
}