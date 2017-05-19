/*
** remove.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/remove.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 13:48:24 2016 Antoine FORET
** Last update Sun Jun  5 19:27:44 2016 Gauthier Cler
*/

#include	"class/env_manager.h"

/*
** Put all values from the env one element up in list
** @params self, start index
** @return void
*/
static void	env_manager_up(t_env_manager *self, unsigned int index)
{
  t_env_entry	*entry;

  while ((entry = self->get(self, index)) != NULL)
    {
      self->values[index - 1] = entry;
      index++;
    }
  self->values[index - 1] = NULL;
}

/*
** Remove an entry from env with given key
** @params self, wanted key
** @return success -> TRUE, failure -> FALSE
*/
t_bool		env_manager_remove(t_env_manager *self, const char *key)
{
  t_env_entry	*entry;
  t_env_entry	*target;
  unsigned int	index;

  index = 0;
  if ((target = self->find(self, key)) == NULL)
    return (TRUE);
  while ((entry = self->get(self, index)) != NULL)
    {
      if (entry == target)
	{
	  entry->destruct(entry);
	  env_manager_up(self, index + 1);
	  self->size--;
	  return (TRUE);
	}
      index++;
    }
  return (FALSE);
}
