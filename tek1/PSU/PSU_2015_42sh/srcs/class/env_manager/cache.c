/*
** cache.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/cache.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 10:55:06 2016 Antoine FORET
** Last update Sun Jun  5 19:22:57 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env_manager.h"

/*
** Generate environment cache
** @params self
** @returns success -> TRUE, failure -> FALSE
*/
t_bool		env_manager_cache(t_env_manager *self)
{
  unsigned int	index;
  t_env_entry	*entry;

  index = 0;
  if (self->cache != NULL)
    self->cache_clear(self);
  if ((self->cache = malloc(sizeof(char *) * (self->size + 1))) == NULL)
    return (FALSE);
  while ((entry = self->get(self, index)) != NULL)
    self->cache[index++] = entry->compose(entry);
  self->cache[index] = NULL;
  self->cached = TRUE;
  return (TRUE);
}
