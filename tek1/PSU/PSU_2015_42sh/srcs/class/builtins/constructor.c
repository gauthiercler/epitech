/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/builtins/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 13:58:59 2016 Vincent Dusautoir
** Last update Sun Jun  5 20:36:41 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/builtin.h"

/*
** Set methods of builtin object
** @params self
** @return void
*/
static void	builtin_methods(t_builtin *self)
{
  self->run = builtin_run;
  self->is_builtin = builtin_is_builtin;
  self->set_data = builtin_set_data;
  self->destruct = builtin_destructor;
}

/*
** Create new builtin object
** @params void
** @return success -> builtin, failure -> NULL
*/
t_builtin	*new_builtin(void)
{
  t_builtin	*builtin;

  if ((builtin = malloc(sizeof(t_builtin))) == NULL)
    return (NULL);
  builtin_methods(builtin);
  builtin->set_data(builtin);
  return (builtin);
}
