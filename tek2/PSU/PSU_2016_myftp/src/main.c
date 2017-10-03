/*
** server.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/server/server.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 11:58:43 2017 Gauthier Cler
** Last update Mon May 08 11:58:43 2017 Gauthier Cler
*/

#include		<stdlib.h>
#include		"misc.h"
#include		"ftp.h"
#include		"macro.h"

int			main(int ac, char **av)
{
  if (ac != NEEDED_ARGS_NUMBER
      || !arguments_checking(av[1], av[2]))
  {
    print_usage(av[0]);
    return (EXIT_FAILURE);
  }
  if (!ftp_server((uint16_t)atoi(av[1])))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}