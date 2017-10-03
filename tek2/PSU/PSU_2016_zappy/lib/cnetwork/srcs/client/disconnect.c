/*
** disconnect.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/client/disconnect.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat May 13 22:21:35 2017 Antoine FORET
** Last update Sat May 13 22:21:35 2017 Antoine FORET
*/

#include	"client.h"

void		tcp_client_disconnect(t_client *self)
{
  self->socket->disconnect(self->socket);
}