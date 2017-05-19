/*
** find_label_address.c for find_label_address in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/compiler
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Mar 25 13:16:24 2016 Gauthier Cler
** Last update Fri Mar 25 13:54:48 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int		find_label_address(char *name, t_label *labels, int *address)
{
  t_label	*tmp;

  tmp = labels;
  while (tmp != NULL)
    {
      if (my_strcmp(name, tmp->name) == SUCCESS)
	{
	  *address = tmp->address;
	  return (SUCCESS);
	}
      tmp = tmp->next;
    }
  return (ERROR);
}
