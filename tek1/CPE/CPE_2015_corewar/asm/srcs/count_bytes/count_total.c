/*
** count_total.c for count_total in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/count_bytes
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Mar 23 16:33:26 2016 Gauthier Cler
** Last update Sun Mar 27 17:07:23 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

void		add_label_address(int *prog_size, t_label *labels,
				  int current_line)
{
  t_label	*tmp;

  tmp = labels;
  while (tmp != NULL)
    {
      if (tmp->line == current_line)
	tmp->address = *prog_size;
      tmp = tmp->next;
    }
}

void		set_label_call_address(t_line *line, int index)
{
  int		i;

  i = index - 1;
  while (i >= 0)
    {
      if (i == 0)
	{
	  if (line->args[i].value != 0 && line->args[i].value != 8 &&
	      line->args[i].value != 11 && line->args[i].value != 14)
	    line->args[i].address -= 1;
	}
      line->args[index].address -= line->args[i].o_size;
      i -= 1;
    }
}

void		count_line(int *prog_size, t_line *line,
			   t_label *labels, int current_line)
{
  int		i;

  if (line->is_label == true)
    add_label_address(prog_size, labels, current_line);
  i = 0;
  while (i < line->nb_args)
    {
      if (line->args[0].type != BAD)
	{
	  if ((my_strcmp(line->args[0].name, "zjmp") == ERROR) &&
	      (my_strcmp(line->args[0].name, "fork") == ERROR) &&
	      (my_strcmp(line->args[0].name, "lfork") == ERROR) &&
	      (my_strcmp(line->args[0].name, "live") == ERROR) && (i == 0))
	    *prog_size += 1;
	  if (line->args[i].type == DLAB || line->args[i].type == ILAB)
	    {
	      line->args[i].address = *prog_size;
	      set_label_call_address(line, i);
	    }
	  *prog_size += line->args[i].o_size;
	}
      i += 1;
    }
}

void		count_all_bytes(int *prog_size, t_line *lines, t_label *labels)
{
  int		current_line;

  current_line = 0;
  while (lines != NULL)
    {
      count_line(prog_size, lines, labels, current_line);
      lines = lines->next;
      current_line += 1;
    }
}
