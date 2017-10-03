/*
** watch.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/watcher/watch.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 11:36:34 2017 Anas Buyumad
** Last update Mon May 29 11:36:34 2017 Anas Buyumad
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"common/error.h"
#include		"server/structures.h"

void			watch(t_watcher *watcher)
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
    fprintf(stdout, "[Watcher]\nNumber of ready sockets -> %d\n\n",
	    watcher->ready_fds);
  }
}