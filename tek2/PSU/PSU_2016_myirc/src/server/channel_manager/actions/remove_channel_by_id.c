/*
** remove_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/actions/remove_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 18:37:02 2017 Anas Buyumad
** Last update Tue May 30 18:37:02 2017 Anas Buyumad
*/

#include	<memory.h>
#include	"server/channel_manager.h"

bool		remove_channel_by_id(t_channel_mgr *manager,
					 int8_t channel_id)
{
  size_t 	iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].active)
      if (manager->channels[iterator].id == channel_id)
	return (memset(&manager->channels[iterator], 0, sizeof(t_channel))
		!= NULL);
    iterator += 1;
  }
  return (false);
}