/*
** initialize.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/watcher/initialize.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 11:33:10 2017 Anas Buyumad
** Last update Mon May 29 11:33:10 2017 Anas Buyumad
*/

#include		"server/structures.h"

static void		configure_watcher(t_watcher *watcher, int server_fd)
{
  watcher->max = server_fd + 1;
  watcher->timeout.tv_sec = 0;
  watcher->timeout.tv_usec = 1000000;
  FD_ZERO(&watcher->read_watcher);
  FD_ZERO(&watcher->exception_watcher);
  FD_SET(server_fd, &watcher->read_watcher);
}

void			initialize_watcher(t_client_mgr *manager,
					       t_watcher *watcher,
					       int server_fd)
{
  size_t		iterator;

  if (operational)
  {
    iterator = 0;
    configure_watcher(watcher, server_fd);
    while (iterator < MAX_CLIENTS)
    {
      if (manager->clients[iterator].connected)
      {
	if (manager->clients[iterator].socket.fd + 1 > watcher->max)
	  watcher->max = manager->clients[iterator].socket.fd + 1;
	FD_SET(manager->clients[iterator].socket.fd,
	       &watcher->read_watcher);
      }
      iterator += 1;
    }
  }
}