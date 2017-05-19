/*
** alias.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 13:47:31 2016 Vincent Dusautoir
** Last update Sun Jun  5 14:37:25 2016 Vincent Dusautoir
*/

#ifndef		ALIAS_H_
# define	ALIAS_H_

typedef		struct s_alias t_alias;

# include	"class/builtin.h"

struct		s_alias
{
  int		(*run)(t_builtin_base *self, char **request,
		       t_shell *shell, t_io *io);
  void		(*destruct)(t_builtin_base *self);
};

t_alias		*new_alias();
int		alias_run(t_builtin_base *self, char **request,
			  t_shell *shell, t_io *io);
void		alias_destructor(t_builtin_base *self);

#endif		/* !ALIAS_H_ */
