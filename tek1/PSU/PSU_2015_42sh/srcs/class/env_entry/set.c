/*
** set.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env_entry/set.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:22:15 2016 Antoine FORET
** Last update Sun Jun  5 19:28:29 2016 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"bool.h"
#include	"class/env_entry.h"

/*
** Set value to the env_entry object
** @params self, value
** @return success -> TRUE, failure -> FALSE
*/
t_bool		env_entry_set(t_env_entry *self, const char *value)
{
  char		*new_value;

  if (value == NULL)
    value = "";
  if ((new_value = strdup(value)) == NULL)
    return (FALSE);
  if (self->value != NULL)
    free(self->value);
  self->value = new_value;
  return (TRUE);
}
