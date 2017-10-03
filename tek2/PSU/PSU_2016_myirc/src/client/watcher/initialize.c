/*
** initialize.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/watcher/initialize.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 14:57:33 2017 Gauthier Cler
** Last update Thu Jun 01 14:57:33 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"client/structures.h"

static void	configure_watcher(t_watcher *watcher)
{
  watcher->max = STDIN_FILENO + 1;
  watcher->timeout.tv_sec = 0;
  watcher->timeout.tv_usec = 1000;
  FD_ZERO(&watcher->read_watcher);
  FD_ZERO(&watcher->exception_watcher);
  FD_SET(STDIN_FILENO, &watcher->read_watcher);
}

void		initialize_watcher(t_client *client)
{
  if (operational)
  {
    configure_watcher(&client->watcher);
    if (client->connected)
    {
      if (client->socket.fd + 1 > client->watcher.max)
	client->watcher.max = client->socket.fd + 1;
      FD_SET(client->socket.fd, &client->watcher.read_watcher);
    }
  }
}