/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env_entry/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:08:41 2016 Antoine FORET
** Last update Sun Jun  5 19:28:15 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/env_manager.h"

/*
** Define methods available for the env_entry object
** @params self
** @return void
*/
static void	env_entry_methods(t_env_entry *entry)
{
  entry->destruct = env_entry_destructor;
  entry->set = env_entry_set;
  entry->compose = env_entry_compose;
}

/*
** Generate a new env_entry object and initialize it.
** @params key of the new entry
** @return success -> env_entry object, failure -> NULL
*/
t_env_entry	*new_env_entry(const char *key)
{
  t_env_entry	*entry;

  if ((entry = malloc(sizeof(t_env_entry))) == NULL)
    return (NULL);
  entry->key = strdup(key);
  entry->value = NULL;
  env_entry_methods(entry);
  if (entry->key == NULL)
    {
      entry->destruct(entry);
      return (NULL);
    }
  return (entry);
}
