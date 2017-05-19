/*
** remove_end.c for remove_end in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/parser
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr  7 14:09:25 2016 Gauthier Cler
** Last update Thu Apr  7 14:11:20 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int             remove_end(t_arg *param)
{
  char          *save;
  int           j;

  if ((save = my_strdup(param->name)) == NULL)
    return (ERROR);
  free(param->name);
  j = 0;
  while (save[j] != ' ' && save[j] != '\t' && save[j])
    j += 1;
  if ((param->name = malloc(sizeof(char) * (j + 1))) == NULL)
    return (ERROR);
  j = 0;
  while (save[j] != ' ' && save[j] != '\t' && save[j])
    {
      param->name[j] = save[j];
      j += 1;
    }
  param->name[j] = '\0';
  free(save);
  return (SUCCESS);
}
