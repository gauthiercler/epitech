/*
** shell.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 21:20:09 2016 Vincent Dusautoir
** Last update Sun Jun  5 13:27:25 2016 Gauthier Cler
*/

#ifndef SHELL_H_
# define SHELL_H_

typedef 		struct s_shell t_shell;

# include		"bool.h"
# include		"class/env_manager.h"
# include		"class/builtin.h"
# include		"class/parser.h"
# include		"class/signal_handler.h"
# include		"class/line_editor.h"
# include		"history_manager.h"

struct			s_shell
{
  char			*instruction;
  int			checker;
  t_env_manager		*env;
  t_builtin		*builtin;
  t_parser		*parser;
  t_signal_handler	*signal_handler;
  int			status;
  t_line_editor		*line_editor;
  t_history_manager	*history_manager;
  int			(*run)(t_shell *);
  t_bool		(*get_instruction)(t_shell *);
  void			(*instruction_destroy)(t_shell *);
  t_shell		*(*prompt)(t_shell *);
  void			(*destruct)(t_shell *);
};

t_shell			*new_shell(int, char **, char **);
t_shell			*shell_prompt(t_shell *);
void			shell_destructor(t_shell *);
t_bool			shell_get_instruction(t_shell *);
void			shell_instruction_destroy(t_shell *);
int			shell_run(t_shell *);

#endif /* !SHELL_H_ */
