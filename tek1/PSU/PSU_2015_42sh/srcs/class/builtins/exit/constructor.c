/*
** constructor.c for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/exit/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 13:39:34 2016 Buyumad Anas
** Last update Sun Jun  5 20:45:28 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/exit.h"

/*
** Assigns the available methods for the exit object
** @params self
** @return void
*/
static void	exit_methods(t_exit *self)
{
  self->run = exit_run;
  self->destruct = exit_destructor;
  self->checker = exit_checker;
  self->get_value = exit_get_value;
}

/*
** Generates a new exit object.
** @params none
** @return success -> exit, failure -> NULL
*/
t_exit		*new_exit(void)
{
  t_exit	*self;

  if ((self = malloc(sizeof(t_exit))) == NULL)
    return (NULL);
  exit_methods(self);
  return (self);
}
