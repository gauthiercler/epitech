/*
** find.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/find.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 13:04:25 2016 Antoine FORET
** Last update Sun Jun  5 19:26:59 2016 Gauthier Cler
*/

#include	<string.h>
#include	"class/env_manager.h"

/*
** Search for a given key in the env object.
** @params self, key
** @return success -> ptr to entry, failure -> NULL
*/
t_env_entry	*env_manager_find(t_env_manager *self, const char *key)
{
  unsigned int	index;
  t_env_entry	*entry;

  index = 0;
  while ((entry = self->get(self, index)) != NULL)
    {
      if (strcmp(key, entry->key) == 0)
	return (entry);
      index++;
    }
  return (NULL);
}
