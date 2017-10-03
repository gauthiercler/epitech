/*
** watch.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/watcher/watch.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 14:59:05 2017 Gauthier Cler
** Last update Thu Jun 01 14:59:06 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"common/error.h"
#include	"common/structures.h"

void		watch(t_watcher *watcher)
{
  if (operational)
  {
    watcher->ready_fds =
      select(watcher->max,
	     &watcher->read_watcher,
	     NULL,
	     &watcher->exception_watcher,
	     &watcher->timeout);
    if (watcher->ready_fds == SYSCALL_FAIL)
      return (throw_error("select", __func__, &operational, CRITICAL));
  }
}