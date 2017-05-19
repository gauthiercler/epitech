/*
** insert.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/insert.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:26:12 2016 Antoine FORET
** Last update Sun Jun  5 19:27:28 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"bool.h"
#include	"config.h"
#include	"class/env_manager.h"

/*
** Allocate memory by block of BLOCK_ENV entries and add the passed entry (break cache)
** @params self, entry to add
** @return success -> TRUE, failure -> FALSE
*/
t_bool		env_manager_insert(t_env_manager *self, t_env_entry *entry)
{
  unsigned int	index;
  size_t	new_size;
  t_env_entry	**tmp;

  if (self->size % BLOCK_ENV == 0)
    {
      index = 0;
      new_size = (self->size / BLOCK_ENV + 1) * BLOCK_ENV  + 1;
      if ((tmp = malloc(sizeof(t_env_entry *) * new_size)) == NULL)
	return (FALSE);
      while (index < self->size)
	{
	  tmp[index] = self->get(self, index);
	  index++;
	}
      if (self->values != NULL)
	free(self->values);
      self->values = tmp;
    }
  self->values[self->size] = entry;
  self->size++;
  self->cached = FALSE;
  return (TRUE);
}
