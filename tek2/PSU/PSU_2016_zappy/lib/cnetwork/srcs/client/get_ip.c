/*
** get_ip.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/get_ip.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 08 14:04:58 2017 Antoine FORET
** Last update Mon May 08 14:04:58 2017 Antoine FORET
*/

#include	"client.h"

const char	*client_get_ip(t_client *self)
{
  return (self->socket->get_foreign_ip(self->socket));
}