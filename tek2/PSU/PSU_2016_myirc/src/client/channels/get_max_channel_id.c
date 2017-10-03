/*
** get_max_channel_id.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/channels/get_max_channel_id.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 20:14:35 2017 Gauthier Cler
** Last update Mon Jun 05 20:14:35 2017 Gauthier Cler
*/

#include	"common/structures.h"

int8_t		get_max_channel_id(t_channel *channels)
{
  int		idx;
  int8_t	max_id;

  max_id = 0;
  idx = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (channels[idx].active && channels[idx].id > max_id)
      max_id = channels[idx].id;
    idx += 1;
  }
  return (max_id);
}