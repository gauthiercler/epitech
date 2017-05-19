/*
** check_label.c for check_label in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/labels/check_label
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 22 17:20:37 2016 Gauthier Cler
** Last update Sun Mar 27 17:05:00 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int		check_label(t_label *labels, int nb_line)
{
  while (labels != NULL)
    {
      if (labels->line == nb_line)
	return (SUCCESS);
      labels = labels->next;
    }
  return (ERROR);
}

int		does_label_exists(t_label *labels, char *label)
{
  while (labels != NULL)
    {
      if (my_strcmp(labels->name, label) == 0)
	return (SUCCESS);
      labels = labels->next;
    }
  return (ERROR);
}
