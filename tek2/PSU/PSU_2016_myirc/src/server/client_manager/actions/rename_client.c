/*
** rename_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/rename_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:59:49 2017 Anas Buyumad
** Last update Sun May 28 01:59:49 2017 Anas Buyumad
*/

#include		<stdio.h>
#include		<memory.h>
#include		<stdlib.h>
#include		"server/client_manager.h"

bool			rename_client(t_client_mgr *manager,
					  t_client *client,
					  const char *new_name)
{
  if (get_client_by_name(manager, new_name) != NULL)
    return (false);
  fprintf(stdout, "[Client Rename]\n");
  dump_client(client);
  memset(client->name, 0, CLIENT_NAME_SIZE + 1);
  memcpy(client->name, new_name, strlen(new_name));
  fprintf(stdout, "New Name -> %s\n\n", client->name);
  return (true);
}