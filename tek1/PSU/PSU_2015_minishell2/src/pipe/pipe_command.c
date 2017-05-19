/*
** pipe_command.c for pipe_command in /home/gogo/rendu/PSU_2015_minishell2/src/pipe
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr  5 14:04:03 2016 Gauthier Cler
** Last update Mon Apr 18 23:53:18 2016 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"mysh.h"

int		exec_pipe(char *instruction, int pipe_index,
			  int max_index, t_env *env)
{
  (pipe_index < max_index) ? pipe(env->fd) : 0;
  if (pipe_index == 0)
    {
      if (first_pipe_exec(instruction, env) == ERROR)
	return (ERROR);
    }
  else if (pipe_index == max_index)
    {
      if (end_pipe_exec(instruction, env) == ERROR)
	return (ERROR);
    }
  else
    if (multi_pipe_exec(instruction, env) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

void		wait_end_process(char **tab)
{
  int		i;
  int		status;

  i = 0;
  while (tab[i])
    {
      wait(&status);
      i += 1;
    }
}

int		is_valid_pipe(char **tab)
{
  int		i;

  i = 0;
  if (tab_len(tab) == 1)
    return (ERROR);
  while (tab[i])
    {
      if (is_empty(tab[i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		pipe_command(char *instruction, t_env *env)
{
  char		**tab;
  int		i;

  i = 0;
  tab = separator_to_tab(instruction , '|');
  if (is_valid_pipe(tab) == ERROR)
    {
      (tab != NULL) ? free_tab(tab) : 0;
      return (format(2, "Invalid null command.\n"));
    }
  while (tab[i])
    {
      if (exec_pipe(tab[i], i, tab_len(tab) - 1, env) == ERROR)
	return (format(2, "Pipe failed\n"));
      i += 1;
    }
  wait_end_process(tab);
  (tab != NULL) ? free_tab(tab) : 0;
  return (SUCCESS);
}
