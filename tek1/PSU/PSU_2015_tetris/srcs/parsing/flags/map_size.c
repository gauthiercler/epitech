/*
** map_size.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/map_size.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  03 17:58:03 2016 Anas Buyumad
** Last update Tue Mar 15 16:26:23 2016 Gauthier Cler
*/

#include	"tetris.h"

int	parse_single_map(t_init *setup, char *arg)
{
  int	length;
  int	height;

  arg += 11;
  length = my_atoi(arg);
  while (arg[0] >= '0' && arg[0] <= '9')
    arg++;
  arg += 1;
  height = my_atoi(arg);
  if (length <= 0 || height <= 0)
    return (ERROR);
  setup->map.width = length;
  setup->map.height = height;
  return (SUCCESS);
}

int	map_action(t_init *setup, char *arg)
{
  int	status;

  if (my_strncmp(arg, "--map-size=", 11) == 0)
    {
      status = parse_single_map(setup, arg);
      return (status);
    }
  return (ERROR);
}
