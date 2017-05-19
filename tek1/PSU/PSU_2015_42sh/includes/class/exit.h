/*
** exit.h for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/includes/class/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 13:32:15 2016 Buyumad Anas
** Last update Sun Jun  5 13:24:23 2016 Gauthier Cler
*/

#ifndef EXIT_H_
# define EXIT_H_

# include		<stddef.h>
# include		"class/builtin.h"
# include		"bool.h"

typedef 		struct s_exit t_exit;

t_exit			*new_exit(void);
int			exit_run(t_builtin_base *builtin, char **command,
				 t_shell *shell, t_io *io);
void			exit_destructor(t_builtin_base *self);
t_bool			exit_checker(char **command);
int			exit_get_value(char *string);

struct			s_exit
{
  int			(*run)(t_builtin_base *, char **, t_shell *, t_io *);
  void			(*destruct)(t_builtin_base *);
  t_bool		(*checker)(char **);
  int			(*get_value)(char *);
};

#endif /* !EXIT_H_ */
