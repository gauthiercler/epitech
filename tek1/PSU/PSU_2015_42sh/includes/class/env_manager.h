/*
** env.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/env.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 11:19:12 2016 Antoine FORET
** Last update Sun Jun  5 13:23:06 2016 Gauthier Cler
*/

#ifndef ENV_MANAGER_H_
# define ENV_MANAGER_H_

# include	<stddef.h>
# include	<stdio.h>
# include	"class/env_entry.h"

typedef		struct s_env_manager t_env_manager;

void		env_manager_destructor(t_env_manager *self);
t_env_manager	*new_env_manager(char **env_tab);
t_env_entry	*env_manager_get(t_env_manager *self, unsigned int index);
t_bool		env_manager_insert(t_env_manager *self, t_env_entry *entry);
t_bool		env_manager_import(t_env_manager *self, char **ref);
t_bool		env_manager_add(t_env_manager *self, const char *key,
				const char *value);
void		env_manager_display(t_env_manager *self, int fd);
void		env_manager_cache_clear(t_env_manager *self);
t_bool		env_manager_cache(t_env_manager *self);
char		**env_manager_export(t_env_manager *self);
t_env_entry	*env_manager_find(t_env_manager *self, const char *key);
t_bool		env_manager_set(t_env_manager *self, const char *key,
				const char *value);
t_bool		env_manager_remove(t_env_manager *self, const char *key);

struct		s_env_manager
{
  t_env_entry	**values;
  size_t	size;
  t_bool	cached;
  char		**cache;
  t_env_entry	*(*get)(t_env_manager *self, unsigned int index);
  t_bool	(*insert)(t_env_manager *self, t_env_entry *entry);
  t_bool	(*add)(t_env_manager *self, const char *key, const char *value);
  t_bool	(*import)(t_env_manager *self, char **ref);
  void		(*display)(t_env_manager *self, int fd);
  void		(*cache_clear)(t_env_manager *self);
  t_bool	(*generate_cache)(t_env_manager *self);
  char		**(*export)(t_env_manager *self);
  t_env_entry	*(*find)(t_env_manager *self, const char *key);
  t_bool	(*set)(t_env_manager *self, const char *key, const char *value);
  t_bool	(*remove)(t_env_manager *self, const char *key);
  void		(*destruct)(t_env_manager *self);
};

#endif /* !ENV_MANAGER_H_ */
