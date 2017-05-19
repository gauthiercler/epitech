/*
** env.h for env in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 14:32:35 2016 Gauthier Cler
** Last update Sun Jun  5 13:22:57 2016 Gauthier Cler
*/

#ifndef ENV_H_
# define ENV_H_

typedef			struct s_env t_env;

# include		"class/env_manager.h"
# include		"class/builtin.h"

struct			s_env
{
  int			(*run)(t_builtin_base *self, char **request,
			 t_shell *shell, t_io *io);
  void			(*destruct)(t_builtin_base *self);
};

t_env			*new_env(void);
int			env_run(t_builtin_base *self, char **request,
				t_shell *shell, t_io *io);
void			env_destructor(t_builtin_base *self);

#endif /* !ENV_H_ */
