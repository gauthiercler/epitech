/*
** get_max_channel_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/queries/get_max_channel_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 15:12:28 2017 Anas Buyumad
** Last update Tue May 30 15:12:28 2017 Anas Buyumad
*/

#include	"server/channel_manager.h"

int8_t		get_max_channel_id(t_channel_mgr *manager)
{
  size_t	iterator;
  int8_t	max_id;

  iterator = 0;
  max_id = NO_CHANNEL;
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].active)
      if (manager->channels[iterator].id > max_id)
	max_id = manager->channels[iterator].id;
    iterator += 1;
  }
  return (max_id);
}