/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/unsetenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 17:22:05 2016 Gauthier Cler
** Last update Mon May 30 23:59:14 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/unsetenv.h"

/*
** Free unsetenv builtin object
** @params self
** @return void
*/
void		unsetenv_destructor(t_builtin_base *builtin)
{
  t_unsetenv	*self;

  self = (t_unsetenv *)builtin;
  if (self != NULL)
    free(self);
}
