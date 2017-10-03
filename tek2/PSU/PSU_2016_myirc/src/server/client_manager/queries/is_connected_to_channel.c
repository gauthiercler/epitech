/*
** is_connected_to_channel.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/queries/is_connected_to_channel.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:37:18 2017 Anas Buyumad
** Last update Sun May 28 01:37:18 2017 Anas Buyumad
*/

#include	"server/structures.h"

bool		is_connected_to_channel(t_client *client,
					    int8_t channel_id)
{
  size_t	iterator;

  iterator = 0;
  if (client->active_channels == 0)
    return (false);
  while (iterator < MAX_CLIENT_CHANNELS)
  {
    if (client->channels[iterator] == channel_id)
      return (true);
    iterator += 1;
  }
  return (false);
}