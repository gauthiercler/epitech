/*
** env_entry.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/env_entry.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:18:53 2016 Antoine FORET
** Last update Sun Jun  5 13:23:12 2016 Gauthier Cler
*/

#ifndef ENV_ENTRY_H_
# define ENV_ENTRY_H_

# include	"bool.h"

typedef		struct s_env_entry t_env_entry;

void		env_entry_destructor(t_env_entry *self);
t_env_entry	*new_env_entry(const char *key);
t_bool		env_entry_set(t_env_entry *self, const char *value);
char		*env_entry_compose(t_env_entry *self);

struct		s_env_entry
{
  char		*key;
  char		*value;
  void		(*destruct)(t_env_entry *self);
  t_bool	(*set)(t_env_entry *self, const char *value);
  char		*(*compose)(t_env_entry *self);
};

#endif /* !ENV_ENTRY_H_ */
