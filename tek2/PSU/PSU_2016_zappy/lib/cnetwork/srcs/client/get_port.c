/*
** get_port.c for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/srcs/client/get_port.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 08 14:05:35 2017 Antoine FORET
** Last update Mon May 08 14:05:35 2017 Antoine FORET
*/

#include	"client.h"

uint16_t	client_get_port(t_client *self)
{
  return (self->socket->get_foreign_port(self->socket));
}