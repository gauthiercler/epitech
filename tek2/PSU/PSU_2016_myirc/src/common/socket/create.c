/*
** create.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/socket/create.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 15:21:56 2017 Anas Buyumad
** Last update Mon May 29 15:21:56 2017 Anas Buyumad
*/

#include	"common/config.h"
#include	"common/error.h"
#include	"common/socket.h"

void		create_socket(t_socket *sock)
{
  if (operational)
  {
    sock->fd = socket(PF_INET, SOCK_STREAM, 0);
    if (sock->fd == SYSCALL_FAIL)
      return (throw_error("socket", __func__, &operational, CRITICAL));
    sock->address.sin_family = AF_INET;
  }
}