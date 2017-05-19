/*
** main.c for objdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump_project/src
** 
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
** 
** Started on  Tue Feb 14 09:47:33 2017 Gauthier Cler
** Last update Tue Feb 14 09:47:39 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"objdump.h"

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
    if (!objdump(argv[iterator]))
      ret_value = EXIT_FAILURE;
    iterator += 1;
  }
  return (ret_value);
}

int		main(int argc, char **argv)
{
  binary = argv[0];
  if (argc == 1)
    return ((int)!objdump("a.out"));
  return (handle_args(argc, argv));
}
