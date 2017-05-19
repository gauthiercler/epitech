/*
** cache_clear.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/cache_clear.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 12:10:41 2016 Antoine FORET
** Last update Sun Jun  5 19:22:52 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env_manager.h"

/*
** Clear previous cache and free memory used by.
** @params self
** @return void
*/
void		env_manager_cache_clear(t_env_manager *self)
{
  unsigned int	index;

  if (self->cache != NULL)
    {
      index = 0;
      while (self->cache[index] != NULL)
	free(self->cache[index++]);
      free(self->cache);
      self->cache = NULL;
    }
  self->cached = FALSE;
}
