/*
** convert.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/convert.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 10:07:58 2017 Antoine FORET
** Last update Mon Jun 26 10:07:58 2017 Antoine FORET
*/

#include	"map.h"

void		map_convert(t_map *self, t_position *position)
{
  while (position->x < 0 || position->x >= (int)(self->width))
    position->x = (unsigned int)((position->x + self->width) % self->width);
  while (position->y < 0 || position->y >= (int)(self->height))
    position->y = (unsigned int)((position->y + self->height) % self->height);
}