/*
** create_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/actions/create_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue May 30 14:55:10 2017 Anas Buyumad
** Last update Tue May 30 14:55:10 2017 Anas Buyumad
*/

#include	<memory.h>
#include	<stdio.h>
#include	"server/channel_manager.h"

static int8_t 	get_available_index(t_channel channels[MAX_CHANNELS])
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (channels[iterator].active == false)
      return ((uint8_t)iterator);
    iterator += 1;
  }
  return (NO_CHANNEL);
}

bool		create_channel(t_channel_mgr *manager, char *channel_name)
{
  int8_t 	channel_id;
  int8_t 	channel_index;

  if ((channel_id = get_available_channel_id(manager)) == NO_CHANNEL)
    return (false);
  if ((channel_index =
	 get_available_index(manager->channels)) == NO_CHANNEL)
    return (false);
  memset(&manager->channels[channel_index], 0, sizeof(t_channel));
  manager->channels[channel_index].active = true;
  sprintf(manager->channels[channel_index].name, "%s", channel_name);
  manager->channels[channel_index].id = channel_id;
  fprintf(stdout, "[Creating Channel]\nID -> %d\nName -> %s\n\n",
	  manager->channels[channel_index].id,
	  manager->channels[channel_index].name);
  return (true);
}