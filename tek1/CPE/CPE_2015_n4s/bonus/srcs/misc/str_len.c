/*
** str_len.c for ia in /home/gogo/rendu/CPE_2015_n4s/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:06:30 2016 Gauthier Cler
** Last update Tue Apr 26 22:06:36 2016 Gauthier Cler
*/

#include	"ia.h"

int		str_len(char *string)
{
  return (*string) ? str_len(++string) + 1 : 0;
}
