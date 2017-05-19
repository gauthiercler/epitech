/*
** constructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/env/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 14:05:32 2016 Gauthier Cler
** Last update Tue May 31 00:02:11 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env.h"

/*
** Define methods available for the env builtin object
** @params self
** @return void
*/
static void	env_methods(t_env *self)
{
  self->run = env_run;
  self->destruct = env_destructor;
}

/*
** Generate a new env builtin object
** @params void
** @return success -> env object, failure -> NULL
*/
t_env		*new_env(void)
{
  t_env		*env;

  env = malloc(sizeof(t_env));
  if (env == NULL)
    return (NULL);
  env_methods(env);
  return (env);
}
