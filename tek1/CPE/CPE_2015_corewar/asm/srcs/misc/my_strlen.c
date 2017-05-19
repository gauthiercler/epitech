/*
** my_strlen.c for my_strlen in /home/gogo/rendu/CPE_2015_corewar/asm/src/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar 21 11:06:01 2016 Gauthier Cler
** Last update Sun Mar 27 18:51:45 2016 Gauthier Cler
*/

#include	"asm.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
      i += 1;
  return (i);
}
