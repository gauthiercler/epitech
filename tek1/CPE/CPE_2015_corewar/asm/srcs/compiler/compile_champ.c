/*
** compile_champ.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 24 21:03:04 2016 Buyumad Anas
** Last update Sun Mar 27 17:08:20 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int		compile_line(int fd, t_line *line, t_label *labels)
{
  int		tab[2];
  int		i;

  i = 1;
  tab[0] = fd;
  if (line->nb_args > 0)
  compile_instruction(fd, line);
  while (i < line->nb_args && line->nb_args > 1)
    {
      tab[1] = line->args[0].value;
      compile_arg(&line->args[i], labels, tab);
      i += 1;
    }
  return (SUCCESS);
}

int		compile_champ(int fd, t_asm *data)
{
  t_line	*tmp;

  tmp = data->lines;
  while (tmp != NULL)
    {
      compile_line(fd, tmp, data->labels);
      tmp = tmp->next;
    }
  return (SUCCESS);
}
