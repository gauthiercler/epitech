/*
** which.h for 42sh in /home/gogo/rendu/PSU_2015_42sh/includes/class/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jun  4 00:26:46 2016 Gauthier Cler
** Last update Sun Jun  5 13:30:02 2016 Gauthier Cler
*/

#ifndef WHICH_H
# define WHICH_H

# include		"class/env_manager.h"
# include		"class/builtin.h"

typedef 		struct s_which t_which;

t_which			*new_which(void);
int			which_run(t_builtin_base *self, char **command,
				  t_shell *shell, t_io *io);
t_bool			which_checker(char **command);
void			which_destructor(t_builtin_base *self);

struct s_which
{
  int			(*run)(t_builtin_base *self, char **command,
			 t_shell *shell, t_io *io);
  void			(*destruct)(t_builtin_base *self);
  t_bool		(*checker)(char **command);
};

#endif /* !WHICH_H */
