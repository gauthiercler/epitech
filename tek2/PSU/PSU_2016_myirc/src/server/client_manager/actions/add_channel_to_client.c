/*
** add_channel_to_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/add_channel_to_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 02:09:21 2017 Anas Buyumad
** Last update Sun May 28 02:09:22 2017 Anas Buyumad
*/

#include		"server/structures.h"

bool			add_channel_to_client(t_client *client,
						  int8_t channel_id)
{
  size_t		iterator;

  iterator = 0;
  if (client->active_channels == MAX_CLIENT_CHANNELS)
    return (false);
  while (iterator < MAX_CLIENT_CHANNELS)
  {
    if (client->channels[iterator] == AVAILABLE_CHANNEL)
    {
      client->channels[iterator] = channel_id;
      client->active_channels += 1;
      return (true);
    }
    iterator += 1;
  }
  return (false);
};