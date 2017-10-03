/*
** retrieve_commands.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/watcher/retrieve_commands.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 13:09:19 2017 Anas Buyumad
** Last update Mon May 29 13:09:19 2017 Anas Buyumad
*/

#include		"server/client_manager.h"
#include		"server/server.h"
#include		"server/parser.h"

void			retrieve_commands(t_cmd_buffer *buffer,
					      t_client_mgr *manager,
					      t_watcher *watcher)
{
  size_t		iterator;

  iterator = 0;
  if (operational)
  {
    while (iterator < MAX_CLIENTS)
    {
      if (manager->clients[iterator].connected)
      {
	if (FD_ISSET(manager->clients[iterator].socket.fd,
		     &watcher->read_watcher))
	  retrieve_command(buffer, &manager->clients[iterator]);
      }
      iterator += 1;
    }
  }
}