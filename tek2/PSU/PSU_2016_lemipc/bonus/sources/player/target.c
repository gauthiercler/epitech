/*
** target.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/player/target.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Mar 27 17:58:54 2017 Gauthier Cler
** Last update Mon Mar 27 17:58:54 2017 Gauthier Cler
*/

#include	"solver.h"

static t_dir	calculate_path(t_player *player, t_pos *target_pos)
{
  t_list	*list;
  t_dir		ret;

  if (player->pos.x == target_pos->x &&
      player->pos.y == target_pos->y)
    return (NONE);
  ret = NONE;
  list = path_finding(player->arena_map, &player->pos, target_pos);
  if (list)
  {
    if (list->next->x < player->pos.x)
      ret = LEFT;
    else if (list->next->x > player->pos.x)
      ret = RIGHT;
    else if (list->next->y < player->pos.y)
      ret = UP;
    else if (list->next->y > player->pos.y)
      ret = DOWN;
    clean_list(list);
  }
  return ret;
}

bool		target(t_ipc *data, t_player *player, t_pos *target_pos)
{
  t_dir		direction;

  if (!attack(data, player, target_pos))
  {
    update_arena(data->memory->arena, player->arena_map);
    direction = calculate_path(player, target_pos);
    if (direction == NONE)
    {
      determine_target(data->memory->arena, player);
      if (!attack(data, player, &player->team_strat.target))
      {
	update_arena(data->memory->arena, player->arena_map);
	direction = calculate_path(player, &player->team_strat.target);
	if (direction == NONE)
	  return (false);
	move(data->memory->arena, player, direction);
      }
      return (true);
    }
    move(data->memory->arena, player, direction);
  }
  return (true);
}
