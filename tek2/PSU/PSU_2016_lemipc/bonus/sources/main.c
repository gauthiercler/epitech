/*
** main.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 09:11:49 2017 Gauthier Cler
** Last update Wed Mar 22 09:11:49 2017 Gauthier Cler
*/

#include	"lem_ipc.h"

int		arena_size = ARENA_SIZE;
int		arena_ss = ARENA_SS;

int		main(int ac, char **av)
{
  bool		ret;

  if (ac < 3 || ac > 5)
  {
    custom_error("Usage : ./lemipc path_to_key team_number [map]");
    return (EXIT_FAILURE);
  }
  if (!parse_args(av[2]))
    return (custom_error("Arguments are not valid"));
  if (ac == 4 && !check_map(av[3]))
    return (EXIT_FAILURE);
  if (ac == 4)
    ret = lem_ipc_with_map(av[1], av[2], av[3]);
  else
    ret = lem_ipc(av[1], av[2]);
  return ((ret == true) ? EXIT_SUCCESS : EXIT_FAILURE);
}
