/*
** constructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/which/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jun  4 00:26:19 2016 Gauthier Cler
** Last update Sun Jun  5 20:39:00 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/which.h"

/*
** Define methods available for the which builtin object
** @params self
** @return void
*/
static void	which_methods(t_which *self)
{
  self->run = which_run;
  self->checker = which_checker;
  self->destruct = which_destructor;
}

/*
** Generate a new builtin which object
** @params void
** @return success -> which object, failure NULL
*/
t_which		*new_which(void)
{
  t_which	*self;

  if ((self = malloc(sizeof(t_which))) == NULL)
    return (NULL);
  which_methods(self);
  return (self);
}
