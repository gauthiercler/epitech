/*
** get_nb_connected_clients.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/get_nb_connected_clients.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:50:14 2017 Anas Buyumad
** Last update Sun May 28 01:50:14 2017 Anas Buyumad
*/

#include		"server/structures.h"

size_t			get_nb_connected_clients(t_client_mgr *manager)
{
  size_t		iterator;
  size_t		connected_clients;

  iterator = 0;
  connected_clients = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
      connected_clients += 1;
    iterator += 1;
  }
  return (connected_clients);
}