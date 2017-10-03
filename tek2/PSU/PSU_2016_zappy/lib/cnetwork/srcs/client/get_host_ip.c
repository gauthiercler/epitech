/*
** get_host_ip.c for PSU_2016_myftp in /home/foret_a/Lab/PSU_2016_myftp/lib/cnetwork/srcs/client/get_host_ip.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 17 15:17:24 2017 Antoine FORET
** Last update Wed May 17 15:17:24 2017 Antoine FORET
*/

#include	"client.h"

const char	*client_get_host_ip(t_client *self)
{
  return (self->socket->get_ip(self->socket));
}