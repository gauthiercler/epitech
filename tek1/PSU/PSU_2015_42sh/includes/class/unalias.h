/*
** unalias.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 14:31:25 2016 Vincent Dusautoir
** Last update Sun Jun  5 14:53:53 2016 Vincent Dusautoir
*/

#ifndef		UNALIAS_H_
# define	UNALIAS_H_

typedef struct	s_unalias t_unalias;

# include	"class/builtin.h"

struct		s_unalias
{
  int		(*run)(t_builtin_base *builtin, char **request,
  			t_shell *shell, t_io *io);
  void		(*destruct)(t_builtin_base *self);
};

t_unalias	*new_unalias();
int		unalias_run(t_builtin_base *builtin, char **request,
			    t_shell *shell, t_io *io);
void		unalias_destructor(t_builtin_base *self);

#endif		/* !UNALIAS_H_ */
