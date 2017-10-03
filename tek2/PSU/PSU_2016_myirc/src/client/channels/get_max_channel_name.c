/*
** get_max_channel_id.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/channels/get_max_channel_id.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 18:58:47 2017 Gauthier Cler
** Last update Mon Jun 05 18:58:47 2017 Gauthier Cler
*/

#include	"common/structures.h"

char		*get_max_channel_name(t_channel *channels)
{
  int		idx;
  int		max_id_idx;

  max_id_idx = 0;
  idx = 0;
  while (idx < MAX_CLIENT_CHANNELS)
  {
    if (channels[idx].active && channels[idx].id > channels[max_id_idx].id)
      max_id_idx = idx;
    idx += 1;
  }
  return (channels[max_id_idx].name);
}