/*
** alias_manager.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 11:40:41 2016 Vincent Dusautoir
** Last update Sun Jun  5 21:25:41 2016 Gauthier Cler
*/

#ifndef ALIAS_MANAGER_
# define ALIAS_MANAGER_

typedef struct		s_alias_manager t_alias_manager;

# include		"class/alias_entry.h"

struct			s_alias_manager
{
  t_alias_entry		*entries;
  void			(*destruct)(t_alias_manager *self);
  void			(*add)(t_alias_manager *self, char *alias, char **cmd);
  t_alias_entry		*(*get)(t_alias_manager *self, char *alias);
  void			(*display)(t_alias_manager *self, int fd);
  void			(*displayone)(t_alias_manager *self, char *alias,
				      int fd);
  void			(*destructone)(t_alias_manager *self, char *alias);
};

t_alias_manager		*new_alias_manager();
void			alias_manager_destructor(t_alias_manager *self);
void			alias_manager_destructone(t_alias_manager *self,
						  char *alias);
void			alias_manager_add(t_alias_manager *self, char *alias,
					  char **cmd);
void			alias_manager_display(t_alias_manager *self, int fd);
void			alias_manager_displayone(t_alias_manager *self,
						 char *alias, int fd);
t_alias_entry		*alias_manager_get(t_alias_manager *self,
					       char *alias);

#endif /* !ALIAS_MANAGER_*/
