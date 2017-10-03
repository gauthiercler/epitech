/*
** get_channel_by_name.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/queries/get_channel_by_name.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:42:00 2017 Anas Buyumad
** Last update Sun May 28 01:42:00 2017 Anas Buyumad
*/

#include		<memory.h>
#include		<stdlib.h>
#include		"server/structures.h"

t_channel		*get_channel_by_name(t_channel_mgr *manager,
					      const char *name)
{
  size_t		iterator;

  iterator = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (strcmp(manager->channels[iterator].name, name) == 0)
      return (&manager->channels[iterator]);
    iterator += 1;
  }
  return (NULL);
}