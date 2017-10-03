/*
** register_user.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/commands/register_user.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 04 12:08:51 2017 Anas Buyumad
** Last update Sun Jun 04 12:08:51 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<memory.h>
#include	"server/client_manager.h"
#include	"server/engine.h"

void		register_user(t_server *server, t_command *command)
{
  t_client	*client;

  client = get_client_by_id(&server->client_mgr, command->client_id);
  if (client && client->connected)
  {
    fprintf(stdout, "[Register User]\n");
    if (strlen(client->name) == 0)
      return ;
    if (client->registered)
      return (throw_error_already_registered(client));
    if (command->nb_args < 4)
      return (throw_error_need_more_params(client, "USER"));
    client->registered = true;
    welcome_user(client);
  }
}