/*
** remove_channel_by_name.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/actions/remove_channel_by_name.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 18:39:02 2017 Anas Buyumad
** Last update Tue May 30 18:39:02 2017 Anas Buyumad
*/

#include	<memory.h>
#include	"server/channel_manager.h"

bool		remove_channel_by_name(t_channel_mgr *manager,
					   const char *channel_name)
{
  size_t 	iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].active)
      if (strcmp(manager->channels[iterator].name, channel_name) == 0)
	return (memset(&manager->channels[iterator], 0, sizeof(t_channel))
		!= NULL);
    iterator += 1;
  }
  return (false);
}