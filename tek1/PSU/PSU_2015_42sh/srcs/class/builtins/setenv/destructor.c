/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/setenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 16:33:07 2016 Gauthier Cler
** Last update Sun Jun  5 20:44:33 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/setenv.h"

/*
** free setenv object
** @params self
** @return void
*/
void		setenv_destructor(t_builtin_base *builtin)
{
  t_setenv	*self;

  self = (t_setenv *)builtin;
  if (self != NULL)
    free(self);
}
