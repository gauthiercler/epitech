/*
** disable_keep_alive.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/client/disable_keep_alive.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 29 16:29:02 2017 Antoine FORET
** Last update Mon May 29 16:29:02 2017 Antoine FORET
*/

#include	"client.h"

bool		tcp_client_disable_keep_alive(t_client *self)
{
  return (self->socket->disable_keep_alive(self->socket));
}