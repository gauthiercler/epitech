/*
** destructor.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/env/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 15:06:18 2016 Gauthier Cler
** Last update Tue May 31 00:02:46 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env.h"

/*
** Free builtin env object
** @params self
** @return void
*/
void		env_destructor(t_builtin_base *builtin)
{
  t_env		*self;

  self = (t_env *)builtin;
  if (self != NULL)
    free(self);
}
