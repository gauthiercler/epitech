/*
** pick_neighbor.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 22:21:52 2016 Buyumad Anas
** Last update Wed Apr 27 16:25:46 2016 Buyumad Anas
*/

#include	"perfection.h"

int		nb_successes(int directions[4])
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (i < 4)
    {
      if (directions[i] == SUCCESS)
	count += 1;
      i += 1;
    }
  return (count);
}

int		get_value_loop(int directions[4], int random_value)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (count <= random_value && i < 4)
    {
      if (directions[i] == SUCCESS)
	count += 1;
      if (count == random_value)
	return (i + 1);
      i += 1;
    }
  return (IMP);
}

int		get_random_value(int nb_success)
{
  int		value;

  value = (((int)rand() % nb_success)) + 1;
  return (value);
}

int		pick_neighbor(t_list *list, t_map *map, t_list *cell)
{
  int		directions[4];
  int		nb_success;
  int		random_value;

  directions[0] = check_directions(list, map, cell, NORTH);
  directions[1] = check_directions(list, map, cell, EAST);
  directions[2] = check_directions(list, map, cell, SOUTH);
  directions[3] = check_directions(list, map, cell, WEST);
  if ((nb_success = nb_successes(directions)) == 0)
    return (-1);
  random_value = get_random_value(nb_success);
  return (get_value_loop(directions, random_value));
}
