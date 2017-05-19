/*
** p_error.c for solver in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:14:43 2016 Gauthier Cler
** Last update Wed Apr 27 23:14:44 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"solver.h"

void			*p_error(char *str)
{
  format(2, "%s", str);
  return (NULL);
}
