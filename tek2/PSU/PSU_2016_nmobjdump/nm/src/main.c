/*
** main.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm_project/src/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 14 10:14:42 2017 Gauthier Cler
** Last update Tue Feb 14 10:14:42 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"nm.h"

char		*binary;

bool		display_error(const char *error_message)
{
  fprintf(stderr, "%s: ", error_message);
  perror(NULL);
  return (false);
}

static int	handle_args(int argc, char **argv)
{
  int		ret_value;
  int		iterator;

  iterator = 1;
  ret_value = EXIT_SUCCESS;
  while (iterator < argc)
  {
    if (!nm(argv[iterator], (argc == 2) ? false : true))
      ret_value = EXIT_FAILURE;
    iterator += 1;
  }
  return (ret_value);
}

int		main(int argc, char **argv)
{
  binary = argv[0];
  if (argc == 1)
    return ((int)!nm("a.out", false));
  return (handle_args(argc, argv));
}
