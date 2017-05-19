/*
** add_args_size.c for add_args_size in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/count_bytes
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 23 14:46:54 2016 Gauthier Cler
** Last update Sun Mar 27 18:44:49 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		fill_size_loop(t_arg *args, int nb_args)
{
  int		i;

  i = 0;
  while (i < nb_args)
    {
      count_bytes(args, i);
      i += 1;
    }
  return (SUCCESS);
}

void		add_args_size(t_line *lines)
{
  while (lines != NULL)
    {
      fill_size_loop(lines->args, lines->nb_args);
      lines = lines->next;
    }
}
