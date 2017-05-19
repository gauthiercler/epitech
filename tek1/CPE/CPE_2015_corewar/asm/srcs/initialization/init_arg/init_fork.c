/*
** init_fork.c for init in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/initialization/init_arg
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 22 21:34:25 2016 Gauthier Cler
** Last update Sun Mar 27 18:29:10 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include        "asm.h"

int             init_fork(t_instruction *instruction)
{
  if ((instruction->name = my_strdup("fork")) == NULL)
    return (ERROR);
  instruction->nb_args = 1;
  if ((instruction->tab =
       malloc(sizeof(char *) * (instruction->nb_args + 1))) == NULL)
    return (ERROR);
  if ((instruction->tab[0] = my_strdup("3")) == NULL)
    return (ERROR);
  instruction->tab[1] = NULL;
  return (SUCCESS);
}
