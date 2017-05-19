/*
** export.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/export.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 12:35:35 2016 Antoine FORET
** Last update Mon May 30 14:40:54 2016 Gauthier Cler
*/

#include	"class/env_manager.h"

/*
** Ensure cache generation and return a pointer to env cache
** @params self
** @return success -> ptr to cache, failure -> NULL
*/
char		**env_manager_export(t_env_manager *self)
{
  if (self->cached == FALSE && !self->generate_cache(self))
    return (NULL);
  return (self->cache);
}
