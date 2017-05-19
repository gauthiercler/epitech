/*
** alias_entry.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 11:51:14 2016 Vincent Dusautoir
** Last update Sun Jun  5 14:37:20 2016 Vincent Dusautoir
*/

#ifndef ALIAS_ENTRY_
# define ALIAS_ENTRY_

typedef			struct s_alias_entry t_alias_entry;

# include		"bool.h"

t_alias_entry		*new_alias_entry(char *alias, char **cmd,
					 t_alias_entry **next);
void			alias_entry_destructor(t_alias_entry *self);
void			alias_entry_display(t_alias_entry *self, t_bool alias,
					    int fd);

struct			s_alias_entry
{
  char			*alias;
  char			**command;
  void			(*destruct)(t_alias_entry *self);
  void			(*display)(t_alias_entry *self, t_bool alias, int fd);
  t_alias_entry		*next;
  t_alias_entry		*previous;
};

#endif /* !ALIAS_ENTRY_ */
