/*
** listen.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/socket/listen.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 18:35:46 2017 Anas Buyumad
** Last update Mon May 29 18:35:46 2017 Anas Buyumad
*/

#include	"common/error.h"
#include	"common/structures.h"

void		listen_on_socket(t_socket *sock)
{
  if (operational)
  {
    if (listen(sock->fd, SOMAXCONN) == SYSCALL_FAIL)
      return (throw_error("listen", __func__, &operational, CRITICAL));
  }
}