/*
** destructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/destructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 12:39:48 2016 Antoine FORET
** Last update Sun Jun  5 19:26:35 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/env_manager.h"

/*
** free all memory used to store entries
** @params self
** @return void
*/
static void	env_manager_destruct_entries(t_env_manager *self)
{
  unsigned int	index;
  t_env_entry	*entry;

  index = 0;
  while (index < self->size)
    {
      if ((entry = self->get(self, index)) != NULL)
	entry->destruct(entry);
      index++;
    }
  free(self->values);
}

/*
** free all memory used to store the env object
** @params self
** @return void
*/
void		env_manager_destructor(t_env_manager *self)
{
  if (self != NULL)
    {
      if (self->values != NULL)
	env_manager_destruct_entries(self);
      self->cache_clear(self);
      free(self);
    }
}
