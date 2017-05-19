/*
** get.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_manager/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:12:11 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:15:39 2016 Vincent Dusautoir
*/

#include	<string.h>
#include	<stdlib.h>
#include	"class/alias_manager.h"

/*
** Get the pointer of an alias
** @params self, alias
** @return success -> tmp, failure -> NULL
*/
t_alias_entry	*alias_manager_get(t_alias_manager *self, char *alias)
{
  t_alias_entry	*tmp;

  tmp = self->entries;
  while (tmp != NULL)
    {
      if (strcmp(tmp->alias, alias) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
