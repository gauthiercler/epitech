/*
** constructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/unsetenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 17:21:58 2016 Gauthier Cler
** Last update Mon May 30 23:58:26 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/unsetenv.h"

/*
** Define methods available for the unsetenv object
** @params self
** @return void
*/
static void	unsetenv_methods(t_unsetenv *self)
{
  self->run = unsetenv_run;
  self->destruct = unsetenv_destructor;
}

/*
** Generate a new unsetenv builtin object
** @params void
** @retun success -> unsetenv object, failure -> NULL
*/
t_unsetenv	*new_unsetenv()
{
  t_unsetenv	*self;

  self = malloc(sizeof(t_unsetenv));
  if (self == NULL)
    return (NULL);
  unsetenv_methods(self);
  return (self);
}
