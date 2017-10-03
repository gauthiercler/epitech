/*
** add_channel.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/channels/add_channel.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 19:03:44 2017 Gauthier Cler
** Last update Mon Jun 05 19:03:44 2017 Gauthier Cler
*/

#include	<memory.h>
#include	"client/channels.h"

void		add_channel(t_channel *channels, const char *name)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (!channels[idx].active)
    {
      memcpy(channels[idx].name, name, strlen(name));
      channels[idx].active = true;
      channels[idx].id = (int8_t)(get_max_channel_id(channels) + 1);
      break ;
    }
    idx += 1;
  }
}