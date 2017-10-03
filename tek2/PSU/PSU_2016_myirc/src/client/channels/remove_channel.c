/*
** remove_channel.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/channels/remove_channel.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 19:08:56 2017 Gauthier Cler
** Last update Mon Jun 05 19:08:56 2017 Gauthier Cler
*/

#include	"common/misc.h"
#include	"common/structures.h"
#include	"memory.h"

int8_t		remove_channel(t_channel *channels,
				     const char *channel_name)
{
  int		idx;
  int8_t	channel_id;

  idx = 0;
  channel_id = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (strncmp(channels[idx].name, channel_name,
		strlen(channels[idx].name)) == 0)
    {
      channel_id = channels[idx].id;
      memset(&channels[idx], 0, sizeof(t_channel));
      break ;
    }
    idx += 1;
  }
  return (channel_id);
}