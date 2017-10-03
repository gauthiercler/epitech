/*
** run.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/run.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:40:52 2017 Anas Buyumad
** Last update Sat May 27 17:40:53 2017 Anas Buyumad
*/

#include	<stdbool.h>
#include	<stdint.h>
#include	"server/engine.h"
#include	"server/client_manager.h"
#include	"server/server.h"

bool		run_server(uint16_t port)
{
  t_server	server;

  initialize_server(&server, port);
  while (operational)
  {
    initialize_watcher(&server.client_mgr, &server.watcher,
		       server.socket.fd);
    watch(&server.watcher);
    watch_connections(&server.client_mgr, &server.watcher,
		      server.socket.fd);
    if (server.watcher.ready_fds > 0)
      retrieve_commands(&server.buffer, &server.client_mgr,
			&server.watcher);
    flush_disconnected_clients(&server);
    flush_clients_buffers(&server.buffer, &server.client_mgr);
    process_commands(&server);
  }
  return (true);
}