/*
** add.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/add.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:05:47 2016 Antoine FORET
** Last update Sun Jun  5 19:22:45 2016 Gauthier Cler
*/

#include	"bool.h"
#include	"class/env_manager.h"

/*
** Take a key and a value and add them to env object
** @params self, key, value
** @return success -> TRUE, failure -> FALSE
*/
t_bool		env_manager_add(t_env_manager *self, const char *key,
				const char *value)
{
  t_env_entry	*entry;

  if ((entry = new_env_entry(key)) == NULL)
    return (FALSE);
  if (entry->set(entry, value) == FALSE)
    {
      entry->destruct(entry);
      return (FALSE);
    }
  return (self->insert(self, entry));
}
