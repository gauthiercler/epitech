/*
** get_label_name.c for get_label_name in /home/montag_v/rendu/CPE_2015_corewar/asm/srcs/get_label_name
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Mar 23 15:49:11 2016 valentin montagne
** Last update Sat Mar 26 17:11:24 2016 Buyumad Anas
*/

#include	"asm.h"
#include	<stdlib.h>

int		get_label_name(t_arg *arg)
{
  int		i;

  i = 0;
  while (arg->name[i] != LABEL_CHAR)
    i++;
  if ((arg->label_name = malloc(my_strlen(arg->name + i + 1) + 1)) == NULL)
    return (ERROR);
  my_strcpy(arg->name + i + 1, arg->label_name);
  return (SUCCESS);
}
