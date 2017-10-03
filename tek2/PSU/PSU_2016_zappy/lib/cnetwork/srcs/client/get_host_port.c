/*
** get_host_port.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/client/get_host_port.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 17 15:17:47 2017 Antoine FORET
** Last update Wed May 17 15:17:47 2017 Antoine FORET
*/

#include	"client.h"

uint16_t	client_get_host_port(t_client *self)
{
  return (self->socket->get_port(self->socket));
}