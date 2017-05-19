/*
** parser.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/parser/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 26 21:08:35 2016 Buyumad Anas
** Last update Thu Apr  7 14:09:09 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

void		skip_spacing(char *line, int *index)
{
  while (line[*index] && (line[*index] == ' ' || line[*index] == '\t'))
    *index += 1;
}

void		skip_label(char *line, int *index)
{
  if (*index == 0 && line[*index] != LABEL_CHAR)
    *index += 1;
  if (*index > 0)
    {
      while (line[*index] && (line[*index - 1] != LABEL_CHAR))
	*index += 1;
    }
}

int		count_params(char *line, int *index)
{
  int		count;
  bool		first;
  int		i;

  count = 0;
  i = *index;
  first = false;
  while (line[i] && line[i] != COMMENT_CHAR)
    {
      if ((first && count == 1) && (line[i] != ' ' && line[i] != '\t') &&
	  (line[i - 1] == ' ' || line[i - 1] == '\t'))
	count += 1;
      if (count > 0 && line[i] == SEPARATOR_CHAR)
	count += 1;
      if (count == 0 && (line[i] != ' ' && line[i] != '\t'))
	{
	  first = true;
	  count += 1;
	}
      i += 1;
    }
  return (count);
}

int		loop_parser(t_line *line, char *line_s, int nb_args,
			    int *index)
{
  int		i;
  bool		first;

  i = 0;
  first = true;
  while (i < nb_args)
    {
      if (parse_param(&line->args[i], line_s, index, first) == ERROR)
	return (ERROR);
      if (i == (nb_args - 1))
	if (remove_end(&line->args[i]) == ERROR)
	  return (ERROR);
      if (first)
	first = false;
      i += 1;
    }
  return (SUCCESS);
}

int		parser(t_line *line, char *line_s)
{
  int		index;
  int		nb_args;

  index = 0;
  if (line->is_label)
    skip_label(line_s, &index);
  nb_args = count_params(line_s, &index);
  line->nb_args = nb_args;
  if (nb_args > 0)
    {
      if ((line->args = malloc(sizeof(t_arg) * nb_args)) == NULL)
	return (format(2, "Couldn't perform malloc.\n"));
    }
  if (loop_parser(line, line_s, nb_args, &index))
    return (ERROR);
  return (SUCCESS);
}
