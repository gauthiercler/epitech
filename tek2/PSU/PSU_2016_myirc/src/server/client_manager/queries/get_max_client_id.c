/*
** get_max_client_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/get_max_client_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 10:36:10 2017 Anas Buyumad
** Last update Thu Jun 01 10:36:10 2017 Anas Buyumad
*/

#include	"server/client_manager.h"

int16_t		get_max_client_id(t_client_mgr *manager)
{
  size_t	iterator;
  int16_t 	max_id;

  iterator = 0;
  max_id = NO_CLIENT;
  while (iterator < MAX_CLIENTS)
  {
    if (manager->clients[iterator].connected)
      if (manager->clients[iterator].id > max_id)
	max_id = manager->clients[iterator].id;
    iterator += 1;
  }
  return (max_id);
}