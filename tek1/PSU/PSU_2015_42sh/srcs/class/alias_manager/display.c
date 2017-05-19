/*
** display.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_manager/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:13:48 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:14:46 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"class/alias_manager.h"
#include	"bool.h"

/*
** Display all alias sets
** @params self, fd
** @return void
*/
void		alias_manager_display(t_alias_manager *self, int fd)
{
  t_alias_entry	*tmp;

  tmp = self->entries;
  while (tmp != NULL)
    {
      tmp->display(tmp, TRUE, fd);
      tmp = tmp->next;
    }
}

/*
** Display the alias link
** @params self, alias, fd
** @return void
*/
void		alias_manager_displayone(t_alias_manager *self, char *alias,
					 int fd)
{
  t_alias_entry	*display_alias;

  display_alias = self->get(self, alias);
  if (display_alias != NULL)
    display_alias->display(display_alias, FALSE, fd);
}
