/*
** watch_connections.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/watcher/watch_connections.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 14:58:20 2017 Anas Buyumad
** Last update Mon May 29 14:58:20 2017 Anas Buyumad
*/

#include		<stdio.h>
#include		<errno.h>
#include		"common/error.h"
#include		"server/client_manager.h"

static void		handle_accept_error(void)
{
  if (errno == ECONNABORTED || errno == EMFILE || errno == ENFILE)
    throw_error("accept", __func__, &operational, MINOR);
  else
    throw_error("accept", __func__, &operational, CRITICAL);
}

static void		accept_connection(t_client_mgr *manager,
					     int server_fd)
{
  t_socket		socket;

  if ((socket.fd =
	 accept(server_fd,
		(struct sockaddr *)&socket.address,
		&(socklen_t){0})) == UNSET_FD)
    handle_accept_error();
  if (!add_client(manager, &socket))
  {
    fprintf(stdout, "[Client Connection]\nSocket -> %d refused.\n\n",
	    socket.fd);
  }
}

void			watch_connections(t_client_mgr *manager,
					      t_watcher *watcher,
					      int server_fd)
{
  if (operational)
  {
    if (FD_ISSET(server_fd, &watcher->read_watcher))
    {
      fprintf(stdout, "[Server Socket]\nChanges detected.\n\n");
      accept_connection(manager, server_fd);
    }
  }
}