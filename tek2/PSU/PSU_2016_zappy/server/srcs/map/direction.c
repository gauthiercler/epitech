/*
** direction.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/map/direction.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon Jun 26 22:20:15 2017 Antoine FORET
** Last update Mon Jun 26 22:20:15 2017 Antoine FORET
*/

#include				<math.h>
#include <stdio.h>
#include				"map.h"
#include				"vector.h"

static const t_vector_orientation	directions[] =
  {
    {0, 22.5, EC_NORTH},
    {22.5, 67.5, EC_NORTH_WEST},
    {67.5, 112.5, EC_WEST},
    {112.5, 157.5, EC_SOUTH_WEST},
    {157.5, 202.5, EC_SOUTH},
    {202.5, 247.5, EC_SOUTH_EAST},
    {247.5, 292.5, EC_EAST},
    {292.5, 337.5, EC_NORTH_EAST},
    {337.5, 360, EC_NORTH},
    {0, 0, EC_NONE}
  };

static t_cardinal			get_direction(double angle,
			       const t_vector_orientation *orientation)
{
  if ((orientation[0].start_angle <= angle &&
       orientation[0].end_angle >= angle) ||
      (orientation[0].start_angle == 0 && orientation[0].end_angle == 0))
    return (orientation[0].cardinal);
  else
    return (get_direction(angle, &orientation[1]));
}

static void				select_shortest(t_map *self,
							   t_position *from,
							   t_position *to,
							   t_vector
							   *direction)
{
  (void)self;
  direction->x = to->x - from->x;
  direction->y = to->y - from->y;
}

t_cardinal				map_direction(t_map *self,
							t_position *origin,
							t_position *target)
{
  t_vector				direction;
  double				angle;

  if (origin->x == target->x && origin->y == target->y)
    return (EC_NONE);
  select_shortest(self, origin, target, &direction);
  angle = atan2(direction.x, direction.y);
  angle *= 180 / M_PI;
  if (angle < 0)
    angle += 360;
  return (get_direction(angle, (t_vector_orientation *)(&directions)));
}