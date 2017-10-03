/*
** update_channels_ids.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/channels/update_channels_ids.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 19:02:59 2017 Gauthier Cler
** Last update Mon Jun 05 19:02:59 2017 Gauthier Cler
*/

#include	"common/structures.h"

void		update_channels_ids(t_channel *channels, int8_t max_value)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (channels[idx].id > max_value)
      channels[idx].id -= 1;
    idx += 1;
  }
}