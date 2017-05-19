/*
** set.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/set.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 12:59:49 2016 Antoine FORET
** Last update Sun Jun  5 19:27:51 2016 Gauthier Cler
*/

#include	"class/env_manager.h"

/*
** set value or add value to the env object
** @params self, key, value
** @return success -> TRUE, failure -> FALSE
*/
t_bool		env_manager_set(t_env_manager *self, const char *key,
				const char *value)
{
  t_env_entry	*entry;
  t_bool	status;

  if ((entry = self->find(self, key)) != NULL)
    status = entry->set(entry, value);
  else
    status = self->add(self, key, value);
  if (status == TRUE)
    self->cached = FALSE;
  return (status);
}
