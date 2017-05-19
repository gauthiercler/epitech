/*
** init_xor.c for init in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/initialization/init_arg
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 22 21:31:20 2016 Gauthier Cler
** Last update Sat Mar 26 17:30:13 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include        "asm.h"

int             init_xor(t_instruction *instruction)
{
  if ((instruction->name = my_strdup("xor")) == NULL)
    return (ERROR);
  instruction->nb_args = 3;
  if ((instruction->tab =
       malloc(sizeof(char *) * (instruction->nb_args + 1))) == NULL)
    return (ERROR);
  if ((instruction->tab[0] = my_strdup("123")) == NULL)
    return (ERROR);
  if ((instruction->tab[1] = my_strdup("123")) == NULL)
    return (ERROR);
  if ((instruction->tab[2] = my_strdup("1")) == NULL)
    return (ERROR);
  instruction->tab[3] = NULL;
  return (SUCCESS);
}
