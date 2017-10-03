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

int		main(int ac, char **av)
{
  if (ac != 3)
  {
    custom_error("Usage : ./lemipc path_to_key team_number");
    return (EXIT_FAILURE);
  }
  if (!parse_args(av[2]))
    return (custom_error("Arguments are not valid"));
  if (!lem_ipc(av[1], av[2]))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}