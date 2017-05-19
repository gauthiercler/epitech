/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_manager/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:05:33 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:12:25 2016 Vincent Dusautoir
*/

#include		<stdlib.h>
#include		"class/alias_manager.h"

/*
** Set methods of alias_manager object
** @params self
** @return void
*/
static void		alias_manager_methods(t_alias_manager *self)
{
  self->display = alias_manager_display;
  self->displayone = alias_manager_displayone;
  self->get = alias_manager_get;
  self->add = alias_manager_add;
  self->destruct = alias_manager_destructor;
  self->destructone = alias_manager_destructone;
}

/*
** Create the alias_manager object
** @params void
** @return success -> alias_manager, failure -> NULL
*/
t_alias_manager		*new_alias_manager(void)
{
  t_alias_manager	*alias_manager;

  if ((alias_manager = malloc(sizeof(t_alias_manager))) == NULL)
    return (NULL);
  alias_manager->entries = NULL;
  alias_manager_methods(alias_manager);
  return (alias_manager);
}
