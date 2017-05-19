/*
** command.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/command.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 14:41:06 2016 Antoine FORET
** Last update Mon May 30 20:45:54 2016 Vincent Dusautoir
*/

#ifndef COMMAND_H_
# define COMMAND_H_

typedef		struct s_command t_command;

# include	"io.h"
# include	"class/shell.h"

t_command	*new_command(char **params);
void		command_destructor(t_command *self);
int		command_run(t_command *self, t_shell *shell, t_io *io);
int		semicoma_run(t_command *self, t_shell *shell, t_io *io);
int		pipe_run(t_command *self, t_shell *shell, t_io *io);
int		and_run(t_command *self, t_shell *shell, t_io *io);
int		or_run(t_command *self, t_shell *shell, t_io *io);
int		simple_left_run(t_command *self, t_shell *shell, t_io *io);
int		simple_right_run(t_command *self, t_shell *shell, t_io *io);
int		double_right_run(t_command *self, t_shell *shell, t_io *io);
int		double_left_run(t_command *self, t_shell *shell, t_io *io);
t_bool		command_is_relative(t_command *self);
int		command_exec(const char *path, char **params,
			     t_shell *shell, t_io *io);
char		*command_search_path(t_env_manager *env, const char *bin_name);
void		redirection_terminate(t_command *self);

struct		s_command
{
  char		**params;
  t_command	*right;
  t_command	*left;
  int		(*run)(t_command *self, t_shell *shell, t_io *io);
  void		(*destruct)(t_command *self);
  t_bool	(*is_relative)(t_command *self);
  int		(*exec)(const char *path, char **params,
			t_shell *shell, t_io *io);
  char		*(*search_path)(t_env_manager *env, const char *bin_name);
  void		(*terminate)(t_command *self);
};

#endif /* !COMMAND_H_ */
