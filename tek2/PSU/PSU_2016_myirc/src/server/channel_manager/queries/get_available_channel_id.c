/*
** get_available_channel_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/queries/get_available_channel_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 18:21:30 2017 Anas Buyumad
** Last update Tue May 30 18:21:30 2017 Anas Buyumad
*/

#include	<stdlib.h>
#include	"server/channel_manager.h"

int8_t		get_available_channel_id(t_channel_mgr *manager)
{
  uint8_t 	available_id;
  int8_t 	max_id;

  available_id = 1;
  if ((max_id = get_max_channel_id(manager)) == NO_CHANNEL)
    return (available_id);
  while (available_id <= max_id)
  {
    if (get_channel_by_id(manager, available_id) == NULL)
      return (available_id);
    available_id += 1;
  }
  return (available_id);
}