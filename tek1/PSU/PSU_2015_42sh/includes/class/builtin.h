/*
** builtin.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May 30 13:05:12 2016 Vincent Dusautoir
** Last update Tue May 31 13:47:09 2016 Gauthier Cler
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

typedef			struct s_builtin t_builtin;
typedef			struct s_data_builtins t_data_builtins;
typedef			struct s_builtin_base t_builtin_base;

# include		"bool.h"
# include		"config.h"
# include		"io.h"
# include		"class/env_manager.h"
# include		"class/shell.h"
# include		"history_entry.h"
# include		"history_manager.h"

# ifndef BUILTIN_SUCCESS
#  define BUILTIN_SUCCESS (256)
# endif /* !BUILTIN_SUCCESS */

# ifndef BUILTIN_ERROR
#  define BUILTIN_ERROR (257)
# endif /* !BUILTIN_ERROR */

struct			s_builtin_base
{
  int			(*run)(t_builtin_base *, char **, t_shell *, t_io *);
  void			(*destruct)(t_builtin_base *);
};

struct			s_data_builtins
{
  char			*name;
  t_builtin_base	*builtin;
};

struct			s_builtin
{
  t_data_builtins	*data[NB_BUILTINS + 1];
  t_bool		(*is_builtin)(t_builtin *, char **);
  void			(*set_data)(t_builtin *);
  int			(*run)(t_builtin *, char **, t_shell *,
			       t_io *);
  void			(*destruct)(t_builtin *);
};

t_builtin		*new_builtin(void);
t_bool			builtin_is_builtin(t_builtin *, char **);
void			builtin_set_data(t_builtin *);
int			builtin_run(t_builtin *, char **, t_shell *,
				    t_io *);
void			builtin_destructor(t_builtin *);

#endif
