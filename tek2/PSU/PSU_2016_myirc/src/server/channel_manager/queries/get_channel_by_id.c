/*
** get_channel_by_id.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/queries/get_channel_by_id.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:44:14 2017 Anas Buyumad
** Last update Sun May 28 01:44:14 2017 Anas Buyumad
*/

#include		<stdlib.h>
#include		"server/structures.h"

t_channel		*get_channel_by_id(t_channel_mgr *manager,
					    uint8_t channel_id)
{
  size_t		iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].id == channel_id)
      return (&manager->channels[iterator]);
    iterator += 1;
  }
  return (NULL);
}