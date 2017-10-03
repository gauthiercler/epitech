/*
** is_connected.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/client/is_connected.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat May 13 22:23:18 2017 Antoine FORET
** Last update Sat May 13 22:23:18 2017 Antoine FORET
*/

#include	"client.h"

bool		tcp_client_is_connected(t_client *self)
{
  return (self->socket->is_connected(self->socket));
}