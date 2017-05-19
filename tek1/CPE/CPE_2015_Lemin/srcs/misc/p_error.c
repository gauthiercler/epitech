/*
** p_error.c for p_error in /home/gogo/rendu/CPE_2015_Lemin/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 23 13:02:47 2016 Gauthier Cler
** Last update Sat Apr 23 13:06:30 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"lemin.h"

void			*p_error(char *str)
{
  format(2, "%s", str);
  return (NULL);
}
