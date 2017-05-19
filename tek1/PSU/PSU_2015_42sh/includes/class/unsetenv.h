/*
** unsetenv.h for 42sh in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 17:36:19 2016 Gauthier Cler
** Last update Sun Jun  5 13:29:48 2016 Gauthier Cler
*/

#ifndef UNSETENV_H_
# define UNSETENV_H_

# include	"class/env_manager.h"
# include	"class/builtin.h"

typedef 	struct s_unsetenv t_unsetenv;

t_unsetenv	*new_unsetenv(void);
int		unsetenv_run(t_builtin_base *self, char **request,
			     t_shell *shell, t_io *io);
void		unsetenv_destructor(t_builtin_base *self);

struct		s_unsetenv
{
  int		(*run)(t_builtin_base *self, char **request,
		 t_shell *shell, t_io *io);
  void		(*destruct)(t_builtin_base *self);
};

#endif /* UNSETENV_H_ */
