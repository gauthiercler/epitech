/*
** remove_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/remove_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed May 31 23:57:11 2017 Anas Buyumad
** Last update Wed May 31 23:57:11 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<memory.h>
#include	<unistd.h>
#include	"common/error.h"
#include	"server/client_manager.h"

bool		remove_client_by_name(t_client_mgr *manager, char *name)
{
  t_client	*client;

  if ((client = get_client_by_name(manager, name)) == NULL)
    return (false);
  fprintf(stdout, "[Client Disconnection]\n");
  dump_client(client);
  if (close(client->socket.fd) == SYSCALL_FAIL)
    throw_error("close", __func__, &operational, MINOR);
  memset(client, 0, sizeof(t_client));
  return (true);
}