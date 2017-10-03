/*
** bind.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/socket/bind.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 15:46:50 2017 Anas Buyumad
** Last update Mon May 29 15:46:50 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/structures.h"

void		bind_socket(t_socket *sock)
{
  if (operational)
  {
    if (bind(sock->fd,
	     (struct sockaddr *)&sock->address,
	     sizeof(sock->address)) == SYSCALL_FAIL)
      return (throw_error("bind", __func__, &operational, CRITICAL));
  }
}