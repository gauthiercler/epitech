/*
** add_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/add_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed May 31 13:40:37 2017 Anas Buyumad
** Last update Wed May 31 13:40:37 2017 Anas Buyumad
*/

#include	<memory.h>
#include	<stdio.h>
#include	<arpa/inet.h>
#include	"server/client_manager.h"

static int16_t	get_available_index(t_client clients[MAX_CLIENTS])
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (clients[iterator].connected == false)
      return ((int16_t)iterator);
    iterator += 1;
  }
  return (NO_CLIENT);
}

bool		add_client(t_client_mgr *manager, t_socket *socket)
{
  int16_t 	client_id;
  int16_t 	client_index;

  if (get_nb_connected_clients(manager) == MAX_CLIENTS)
    return (false);
  if ((client_id = get_available_client_id(manager)) == NO_CLIENT)
    return (false);
  if ((client_index = get_available_index(manager->clients)) == NO_CLIENT)
    return (false);
  memset(&manager->clients[client_index], 0, sizeof(t_client));
  memcpy(&manager->clients[client_index].socket, socket, sizeof(t_socket));
  manager->clients[client_index].connected = true;
  manager->clients[client_index].id = client_id;
  initialize_ring_buffer(&manager->clients[client_index].ring_buffer);
  fprintf(stdout, "[Client Connection]\n");
  dump_client(&manager->clients[client_index]);
  return (true);
};