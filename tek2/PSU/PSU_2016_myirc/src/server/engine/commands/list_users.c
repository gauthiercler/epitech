/*
** list_users.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/list_users.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 21:18:43 2017 Anas Buyumad
** Last update Thu Jun 01 21:18:43 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"server/client_manager.h"
#include	"server/engine.h"

static void	list_all_users(t_client_mgr *manager,
				  t_client *user)
{
  start_users_listing(user);
  if (user->connected)
    list_server_users(manager, user);
  if (user->connected)
    stop_users_listing(user);
}

void		list_users(t_server *server, t_command *command)
{
  t_client	*client;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Users Command]\n");
    if (!client->registered)
      return (throw_error_not_registered(client));
    list_all_users(&server->client_mgr, client);
  }
}