/*
** echo.h for 42sh in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/includes/class/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Jun  5 20:36:50 2016 Buyumad Anas
** Last update Sun Jun  5 20:37:10 2016 Buyumad Anas
*/

#ifndef ECHO_H_
# define ECHO_H_

# ifndef BSD
#  define BSD		(0)
# endif /* !BSD */

# ifndef SYSV
#  define SYSV		(1)
# endif /* !SYSV */

# ifndef BOTH
#  define BOTH		(2)
# endif /* !BOTH */

# ifndef NONE
#  define NONE		(3)
# endif /* !NONE */

# include		<stddef.h>
# include		"class/builtin.h"
# include		"bool.h"

typedef 		struct s_escape t_escape;
typedef 		struct s_echo t_echo;

t_echo			*new_echo(void);
int			echo_run(t_builtin_base *builtin, char **command,
				 t_shell *shell, t_io *io);
void			echo_destructor(t_builtin_base *self);
void			echo_assess_style(t_echo *self);
void			echo_assess_flags(t_echo *self, char **command);
int			echo_display(t_echo *self, char **command, t_io *io, t_shell *);
int			echo_display_variable(t_echo *, char *, t_shell *);
void			echo_escape(t_echo *self, char *string, size_t *index, t_io *io);

struct			s_escape
{
  char			*sequence;
  char			character;
};

struct			s_echo
{
  int			(*run)(t_builtin_base *, char **, t_shell *, t_io *io);
  void			(*destruct)(t_builtin_base *);
  void			(*assess_style)(t_echo *self);
  void			(*assess_flags)(t_echo *self, char **command);
  int			(*display_variable)(t_echo *, char *, t_shell *);
  int			(*display)(t_echo *self, char **command, t_io *io,
			 t_shell *shell);
  void			(*escape)(t_echo *self, char *string, size_t *index,
					t_io *io);
  t_escape		escapes[11];
  size_t		echo_style;
  t_bool		string_mode;
  t_bool		newline_flag;
  t_bool		escape_flag;
};

#endif /* !ECHO_H_ */
