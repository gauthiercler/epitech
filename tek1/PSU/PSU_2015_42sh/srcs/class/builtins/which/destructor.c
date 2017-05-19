/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/which/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jun  4 00:34:27 2016 Gauthier Cler
** Last update Sun Jun  5 20:40:10 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"class/which.h"

/*
** destruct which object
** @params builtin
** @return void
*/
void			which_destructor(t_builtin_base *builtin)
{
  t_which		*self;

  self = (t_which *)builtin;
  if (self != NULL)
    free(self);
}
