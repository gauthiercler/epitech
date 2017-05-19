/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_entry/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:29:09 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:16:59 2016 Vincent Dusautoir
*/

#include	<string.h>
#include	<stdlib.h>
#include	"libc.h"
#include	"class/alias_entry.h"

/*
** Set the alias_entry methods
** @params self
** @return void
*/
static void	alias_entry_methods(t_alias_entry *self)
{
  self->display = alias_entry_display;
  self->destruct = alias_entry_destructor;
}

/*
** Create the alias_entry object
** @params alias, cmd, next
** @return alias_entry
*/
t_alias_entry	*new_alias_entry(char *alias, char **cmd, t_alias_entry **next)
{
  t_alias_entry	*alias_entry;

  if ((alias_entry = malloc(sizeof(t_alias_entry))) == NULL)
    return (*next);
  alias_entry->alias = strdup(alias);
  alias_entry->command = array_dup(cmd);
  alias_entry_methods(alias_entry);
  alias_entry->next = *next;
  alias_entry->previous = NULL;
  if (*next != NULL)
    (*next)->previous = alias_entry;
  return (alias_entry);
}
