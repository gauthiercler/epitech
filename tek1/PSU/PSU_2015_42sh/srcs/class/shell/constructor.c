/*
** constructor.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/shell/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 21:27:29 2016 Vincent Dusautoir
** Last update Sun Jun  5 18:38:44 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	"libc.h"

/*
** Define methods available for the shell object
** @params self
** @return void
*/
static void	shell_methods(t_shell *self)
{
  self->run = shell_run;
  self->prompt = shell_prompt;
  self->get_instruction = shell_get_instruction;
  self->instruction_destroy = shell_instruction_destroy;
  self->destruct = shell_destructor;
}

/*
** Change standard input to point to the script file
** @params target file's path
** @return void
*/
static void	change_std_input(char *file)
{
  int		fd;

  if ((fd = open(file, O_RDONLY)) != -1)
    {
      dup2(fd, 0);
      close(fd);
    }
}

/*
** Generate a new shell object based on shell args
** @params ac, av, env
** @return success -> shell, failure -> NULL
*/
t_shell		*new_shell(int ac, char **av, char **env)
{
  t_shell	*shell;

  if ((shell = malloc(sizeof(t_shell))) == NULL)
    return (NULL);
  shell_methods(shell);
  shell->parser = new_parser();
  shell->builtin = new_builtin();
  shell->signal_handler = new_signal_handler();
  shell->env = new_env_manager(env);
  shell->history_manager = new_history_manager();
  if (isatty(0) == 1 && isatty(1) == 1 && shell->env != NULL)
    shell->line_editor = new_line_editor(shell->env->export(shell->env));
  else
    shell->line_editor = NULL;
  shell->checker = -1;
  shell->status = 256;
  if (shell->parser == NULL || shell->env == NULL ||
      shell->builtin == NULL || shell->signal_handler == NULL)
    {
      shell->destruct(shell);
      return (NULL);
    }
  if (ac == 2)
    change_std_input(av[1]);
  return (shell);
}
