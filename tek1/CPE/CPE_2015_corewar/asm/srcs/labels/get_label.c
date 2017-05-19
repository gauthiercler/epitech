/*
** get_label.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/labels/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 16:12:27 2016 Buyumad Anas
** Last update Sun Mar 27 18:48:43 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		check_previous_label(t_label *labels, char *name)
{
  while (labels != NULL)
    {
      if (my_strcmp(labels->name, name) == SUCCESS)
	return (ERROR);
      labels = labels->next;
    }
  return (SUCCESS);
}

int		parse_label(t_label **labels, char *str, int nb_line,
			    int pos[2])
{
  char		*label;
  int		i;

  i = 0;
  if ((label = malloc(sizeof(char) * (pos[1] + 1))) == NULL)
    return (LABEL_ERROR);
  while (i < pos[1])
    {
      label[i] = str[pos[0] + i];
      i += 1;
    }
  label[i] = '\0';
  if (check_previous_label(*labels, label) == ERROR)
    {
      format(2, "The label %s is declared twice ; Line %d.\n", label, nb_line);
      free(label);
      return (LABEL_ERROR);
    }
  if (add_label(labels, label, nb_line) == ERROR)
    return (LABEL_ERROR);
  free(label);
  return (SUCCESS);
}

int		get_label(t_label **labels, char *str, int nb_line,
			  int position)
{
  int		pos[2];
  int		i;

  i = 0;
  while (str[position + i] && (str[position + i] != LABEL_CHAR))
    {
      if (is_char_valid(str[position + i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  pos[0] = position;
  pos[1] = i;
  return (parse_label(labels, str, nb_line, pos));
}
