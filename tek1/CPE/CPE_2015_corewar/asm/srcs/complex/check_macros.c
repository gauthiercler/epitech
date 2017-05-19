/*
** check_macros.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/complex/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 27 17:24:21 2016 Buyumad Anas
** Last update Sun Mar 27 18:41:06 2016 Gauthier Cler
*/

#include	"asm.h"

int		macros_are_valid(void)
{
  if (BAD != -1 || INS != 0 || REG != 1 || IND != 2 || DIR != 3 || DLAB != 4 ||
      ILAB != 5 || SUCCESS != 0 || ERROR != 1 || LABEL_ERROR != 2 ||
      HEADER_ERROR != 3 || READ_SIZE != 4096)
    return (format(2,
		   "You do not have the right to change our own macros.\n"));
  return (SUCCESS);
}
