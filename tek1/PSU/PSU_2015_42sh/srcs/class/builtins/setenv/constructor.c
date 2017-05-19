/*
** constructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/setenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 16:16:29 2016 Gauthier Cler
** Last update Mon May 30 23:53:06 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/setenv.h"

/*
** Define methods available for the setenv object
** @params self
** @return void
*/
static void	setenv_methods(t_setenv *self)
{
  self->run = setenv_run;
  self->checker = setenv_checker;
  self->destruct = setenv_destructor;
}

/*
** Generate a new builtin setenv object
** @params void
** @return success -> setenv object, failure -> NULL
*/
t_setenv 	*new_setenv(void)
{
  t_setenv	*setenv;

  setenv = malloc(sizeof(t_setenv));
  if (setenv == NULL)
    return (NULL);
  setenv_methods(setenv);
  return (setenv);
}
