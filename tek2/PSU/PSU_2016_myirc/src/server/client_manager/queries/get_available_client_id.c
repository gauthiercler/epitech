/*
** get_available_client_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/get_available_client_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 10:39:15 2017 Anas Buyumad
** Last update Thu Jun 01 10:39:15 2017 Anas Buyumad
*/

#include	<stdlib.h>
#include	"server/client_manager.h"

int16_t		get_available_client_id(t_client_mgr *manager)
{
  int16_t 	available_id;
  int16_t 	max_id;

  available_id = 1;
  if ((max_id = get_max_client_id(manager)) == NO_CLIENT)
    return (1);
  while (available_id <= max_id)
  {
    if (get_client_by_id(manager, available_id) == NULL)
      return (available_id);
    available_id += 1;
  }
  return (available_id);
}