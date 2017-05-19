/*
** add_label.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/labels/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 15:42:49 2016 Buyumad Anas
** Last update Sat Mar 26 15:47:02 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		add_label(t_label **labels, char *name, int line)
{
  t_label	*label;
  t_label	*tmp;

  if ((label = malloc(sizeof(t_label))) == NULL)
    return (ERROR);
  if ((label->name = my_strdup(name)) == NULL)
    return (ERROR);
  label->line = line;
  label->next = NULL;
  if (*labels == NULL)
    *labels = label;
  else
    {
      tmp = *labels;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = label;
    }
  return (SUCCESS);
}
