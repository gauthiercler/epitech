/*
** remove_client_by_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/remove_client_by_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 10:56:56 2017 Anas Buyumad
** Last update Thu Jun 01 10:56:56 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<memory.h>
#include	"common/error.h"
#include	"server/client_manager.h"

bool		remove_client_by_id(t_client_mgr *manager,
					int16_t client_id)
{
  t_client	*client;

  if ((client = get_client_by_id(manager, client_id)) == NULL)
    return (false);
  fprintf(stdout, "[Client Disconnection]\n");
  dump_client(client);
  if (close(client->socket.fd) == SYSCALL_FAIL)
    throw_error("close", __func__, &operational, MINOR);
  memset(client, 0, sizeof(t_client));
  return (true);
}