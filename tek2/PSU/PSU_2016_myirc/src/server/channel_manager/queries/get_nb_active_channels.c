/*
** get_nb_active_channels.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/channel_manager/queries/get_nb_active_channels.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:47:09 2017 Anas Buyumad
** Last update Sun May 28 01:47:09 2017 Anas Buyumad
*/

#include		"server/structures.h"

size_t			get_nb_active_channels(t_channel_mgr *manager)
{
  size_t		iterator;
  size_t		active_channels;

  iterator = 0;
  active_channels = 0;
  while (iterator < MAX_CHANNELS)
  {
    if (manager->channels[iterator].active)
      active_channels += 1;
    iterator += 1;
  }
  return (active_channels);
}