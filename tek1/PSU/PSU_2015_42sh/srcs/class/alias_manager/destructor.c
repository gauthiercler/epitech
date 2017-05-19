/*
** destructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_manager/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:11:35 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:13:37 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/alias_manager.h"

/*
** Remove one alias
** @params self, alias
** @return void
*/
void		alias_manager_destructone(t_alias_manager *self, char *alias)
{
  t_alias_entry	*rm_alias;

  rm_alias = self->get(self, alias);
  if (rm_alias != NULL)
    {
      if (rm_alias == self->entries)
	self->entries = self->entries->next;
      rm_alias->destruct(rm_alias);
    }
}

/*
** Free the alias_manager object and his entries
** @params self
** @return void
*/
void		alias_manager_destructor(t_alias_manager *self)
{
  t_alias_entry	*tmp;
  t_alias_entry	*temp;

  if (self != NULL)
    {
      tmp = self->entries;
      while (tmp != NULL)
	{
	  temp = tmp;
	  tmp = tmp->next;
	  temp->destruct(temp);
	}
      free(self);
    }
}
