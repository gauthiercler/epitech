/*
** remove_channel_of_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/remove_channel_of_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 02:14:42 2017 Anas Buyumad
** Last update Sun May 28 02:14:42 2017 Anas Buyumad
*/

#include		<stdio.h>
#include		"server/client_manager.h"

bool			remove_channel_of_client(t_client *client,
						     int8_t channel_id)
{
  size_t		iterator;

  iterator = 0;
  if (client->active_channels == 0)
    return (false);
  while (iterator < MAX_CLIENT_CHANNELS)
  {
    if (client->channels[iterator] == channel_id)
    {
      client->channels[iterator] = AVAILABLE_CHANNEL;
      client->active_channels -= 1;
      fprintf(stdout, "[Removing Channel %d From Client]\n", channel_id);
      dump_client(client);
      return (true);
    }
    iterator += 1;
  }
  return (false);
}