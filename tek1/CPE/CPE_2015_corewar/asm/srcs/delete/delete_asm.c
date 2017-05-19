/*
** delete_asm.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/delete/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 14:18:41 2016 Buyumad Anas
** Last update Sun Mar 27 16:57:13 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

void		delete_args(t_arg *args, int nb_args)
{
  int		i;

  i = 0;
  while (i < nb_args)
    {
      if (args[i].name != NULL)
	free(args[i].name);
      if (args[i].label_name != NULL)
	free(args[i].label_name);
      i += 1;
    }
  free(args);
}

void		delete_lines(t_line *lines)
{
  t_line	*tmp;

  tmp = lines;
  while (lines != NULL)
    {
      tmp = lines->next;
      if (lines->nb_args > 0)
	delete_args(lines->args, lines->nb_args);
      free(lines);
      lines = tmp;
    }
}

void		delete_labels(t_label *labels)
{
  t_label	*tmp;

  tmp = labels;
  while (labels != NULL)
    {
      tmp = labels->next;
      if (labels->name != NULL)
	free(labels->name);
      free(labels);
      labels = tmp;
    }
}

void		delete_instructions(t_instruction *instructions)
{
  int		i;
  int		j;

  i = 0;
  while (instructions[i].name)
    {
      j = 0;
      if (instructions[i].name != NULL)
	free(instructions[i].name);
      while (instructions[i].tab[j])
	{
	  free(instructions[i].tab[j]);
	  j += 1;
	}
      free(instructions[i].tab);
      i += 1;
    }
}

void		delete_asm(t_asm *data)
{
  delete_instructions(data->instructions);
  delete_labels(data->labels);
  delete_lines(data->lines);
}
