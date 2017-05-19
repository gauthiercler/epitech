/*
** process_file.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/process/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 23 15:17:48 2016 Buyumad Anas
** Last update Sun Mar 27 03:14:32 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int		call_lp(t_asm *data, t_line *line, char *line_s, int nb_line)
{
  line->nb_line = nb_line;
  if (check_label(data->labels, nb_line) == SUCCESS)
    line->is_label = true;
  else
    line->is_label = false;
  if (parser(line, line_s) == ERROR)
    return (ERROR);
  if (line_assigner(data->labels, data->instructions, line) == ERROR)
    return (ERROR);
  if (line_lexer(data->instructions, line) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		process_line(t_asm *data, char *line_s, int nb_line)
{
  t_line	*line;
  t_line	*tmp;

  if ((line = malloc(sizeof(t_line))) == NULL)
    return (ERROR);
  line->next = NULL;
  if (call_lp(data, line, line_s, nb_line) == ERROR)
    return (ERROR);
  if (data->lines == NULL)
    data->lines = line;
  else
    {
      tmp = data->lines;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = line;
    }
  return (SUCCESS);
}

int		process_file(int fd, t_asm *data)
{
  char		*line;
  int		nb_line;

  nb_line = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (process_line(data, line, nb_line) == ERROR)
	return (ERROR);
      nb_line += 1;
      free(line);
    }
  return (SUCCESS);
}
