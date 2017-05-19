/*
** compose.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env_entry/compose.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri May 20 12:16:49 2016 Antoine FORET
** Last update Sun Jun  5 19:28:04 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<string.h>
#include	"class/env_entry.h"

/*
** Export key and value like key=value
** @params self
** @return key=value (char *)
*/
char		*env_entry_compose(t_env_entry *self)
{
  char		*result;

  result = malloc(sizeof(char) * (strlen(self->key) + strlen(self->value) + 2));
  if (result == NULL)
    return (NULL);
  strcpy(result, self->key);
  strcat(result, "=");
  strcat(result, self->value);
  return (result);
}
