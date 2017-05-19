/*
** setenv.h for 42sh in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 16:22:30 2016 Gauthier Cler
** Last update Sun Jun  5 13:27:42 2016 Gauthier Cler
*/

#ifndef SETENV_H_
# define SETENV_H_

typedef		struct s_setenv t_setenv;

# include	"class/env_manager.h"
# include	"class/builtin.h"

t_setenv	*new_setenv(void);
int		setenv_run(t_builtin_base *self, char **request,
			   t_shell *shell, t_io *io);
t_bool		setenv_checker(char **request);
void		setenv_destructor(t_builtin_base *self);

struct		s_setenv
{
  int		(*run)(t_builtin_base *self, char **request,
		 t_shell *shell, t_io *io);
  void		(*destruct)(t_builtin_base *self);
  t_bool	(*checker)(char **resquest);
};

#endif /* !SETENV_H_ */
