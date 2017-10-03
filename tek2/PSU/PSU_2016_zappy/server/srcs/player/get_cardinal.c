/*
** get_cardinal.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/player/get_cardinal.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jul 02 00:59:03 2017 Antoine FORET
** Last update Sun Jul 02 00:59:03 2017 Antoine FORET
*/

#include	"player.h"

static const t_cardinal_liaison	relation[] =
  {
    {1, EC_NORTH},
    {2, EC_NORTH_WEST},
    {3, EC_WEST},
    {4, EC_SOUTH_WEST},
    {5, EC_SOUTH},
    {6, EC_SOUTH_EAST},
    {7, EC_EAST},
    {8, EC_NORTH_EAST},
    {0, EC_NONE}
  };

static const t_player_offset	direction[] =
  {
    {0, P_NORTH},
    {-2, P_WEST},
    {-4, P_SOUTH},
    {-6, P_EAST}
  };

static int			get_cardinal(t_cardinal real)
{
  unsigned int			idx;

  idx = 0;
  while (relation[idx].cardinal != real)
    idx += 1;
  return (relation[idx].value);
}

static int			get_offset(t_player *self)
{
  unsigned int			idx;

  idx = 0;
  while (direction[idx].direction != self->direction)
    idx += 1;
  return (direction[idx].offset);
}

int				player_get_cardinal(t_player *self,
						       t_cardinal real)
{
  int				real_cardinal;
  int				offset;

  real_cardinal = get_cardinal(real);
  offset = (real_cardinal != 0) ? get_offset(self) : 0;
  while (real_cardinal + offset <= 0 && offset != 0)
    real_cardinal += 8;
  return (real_cardinal + offset);
}