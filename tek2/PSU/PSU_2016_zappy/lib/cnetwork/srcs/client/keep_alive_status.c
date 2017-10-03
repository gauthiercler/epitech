/*
** keep_alive_status.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/client/keep_alive_status.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 29 16:29:47 2017 Antoine FORET
** Last update Mon May 29 16:29:47 2017 Antoine FORET
*/

#include	"client.h"

bool		tcp_client_keep_alive_status(t_client *self)
{
  return (self->socket->keep_alive_status(self->socket));
}