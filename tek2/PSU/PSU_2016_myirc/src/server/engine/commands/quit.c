/*
** quit.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/quit.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 15:43:49 2017 Anas Buyumad
** Last update Sun Jun 04 15:43:49 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"server/client_manager.h"
#include	"server/engine.h"

void		quit(t_server *server, t_command *command)
{
  t_client	*client;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Quit]\n");
    flush_client_from_channels(server, client);
    remove_client_by_id(&server->client_mgr, client->id);
  }
}