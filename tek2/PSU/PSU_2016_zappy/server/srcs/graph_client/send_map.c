/*
** send_map.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/graph_client/send_map.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 30 14:08:43 2017 Antoine FORET
** Last update Fri Jun 30 14:08:43 2017 Antoine FORET
*/

#include	"graph_client.h"

bool		send_map(t_graph_client *self, t_map *map)
{
  size_t	map_size;
  size_t	sent;
  t_position	pos;

  map_size = map->width * map->height;
  sent = 0;
  while (sent < map_size)
  {
    pos.x = (int)(sent % map->width);
    pos.y = (int)(sent / map->width);
    self->send_cell_content(self, &pos,
			    map->tiles[sent]);
    sent += 1;
  }
  return (true);
}