/*
** init_lld.c for init in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/initialization/init_arg
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 22 21:35:46 2016 Gauthier Cler
** Last update Sat Mar 26 17:23:05 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include        "asm.h"

int             init_lld(t_instruction *instruction)
{
  if ((instruction->name = my_strdup("lld")) == NULL)
    return (ERROR);
  instruction->nb_args = 2;
  if ((instruction->tab =
       malloc(sizeof(char *) * (instruction->nb_args + 1))) == NULL)
    return (ERROR);
  if ((instruction->tab[0] = my_strdup("23")) == NULL)
    return (ERROR);
  if ((instruction->tab[1] = my_strdup("1")) == NULL)
    return (ERROR);
  instruction->tab[2] = NULL;
  return (SUCCESS);
}
