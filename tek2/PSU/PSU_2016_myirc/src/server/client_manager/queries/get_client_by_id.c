/*
** get_client_by_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/get_client_by_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 10:31:20 2017 Anas Buyumad
** Last update Thu Jun 01 10:31:20 2017 Anas Buyumad
*/

#include		<stdlib.h>
#include		"server/client_manager.h"

t_client		*get_client_by_id(t_client_mgr *manager,
					  int16_t client_id)
{
  size_t		iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].id == client_id)
      return (&manager->clients[iterator]);
    iterator += 1;
  }
  return (NULL);
}