/*
** init.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/socket/init.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 15:30:25 2017 Gauthier Cler
** Last update Wed May 31 15:30:25 2017 Gauthier Cler
*/

#include	<stdint.h>
#include	<netinet/in.h>
#include	"common/structures.h"

void		init_socket(t_socket *sock, uint16_t port, in_addr_t ip)
{
  sock->address.sin_port = htons(port);
  sock->address.sin_addr.s_addr = ip;
}