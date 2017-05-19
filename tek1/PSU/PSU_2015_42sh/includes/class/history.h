/*
** history.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/history.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 20:01:20 2016 Antoine FORET
** Last update Sat Jun 04 20:01:20 2016 Antoine FORET
*/

#ifndef HISTORY_H_
# define HISTORY_H_

typedef		struct s_history t_history;

# include	"class/builtin.h"

void		history_destructor(t_builtin_base *builtin);
int		history_run(t_builtin_base *builtin, char **request,
			    t_shell *shell, t_io *io);
t_history	*new_history();

struct		s_history
{
  int		(*run)(t_builtin_base *self, char **request,
		       t_shell *shell, t_io *io);
  void		(*destruct)(t_builtin_base *self);
};

#endif /* !HISTORY_H_ */
