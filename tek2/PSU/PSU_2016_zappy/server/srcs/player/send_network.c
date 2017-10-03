/*
** send_network.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/player/send_network.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 29 10:40:47 2017 Antoine FORET
** Last update Thu Jun 29 10:40:47 2017 Antoine FORET
*/

#include	"config.h"
#include	"player.h"
#include	<stdio.h>

bool		player_send_network(t_player *self)
{
  char		buff[WRITE_SIZE];
  ssize_t	to_write;

  to_write = self->output_buffer->read(self->output_buffer,
				       buff, WRITE_SIZE);
  if (to_write == -1)
    return (false);
  if (self->socket->send(self->socket, buff,
			 (size_t)(to_write), false) == SOCKET_ERROR)
    return (false);
  else
    return (true);
}