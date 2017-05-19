/*
** main.c for main in /home/gogo/rendu/PSU_2015_minishell2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 29 14:09:26 2016 Gauthier Cler
** Last update Mon Apr 18 23:52:46 2016 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

bool		prompt;

int		main(int ac, char **av, char **ae)
{
  (void)ac;
  (void)av;
  if (my_sh(ae) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		assess_instruction(char *instruction, t_env *env)
{
  if (check_redir(instruction) == SUCCESS)
    {
      if (redir_command(instruction, env) == ERROR)
	return (ERROR);
    }
  else if (check_pipe(instruction) == SUCCESS)
    {
      if (pipe_command(instruction, env) == ERROR)
	return (ERROR);
    }
  else
    {
      if (launch_command(instruction, env) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int		execute_loop(char *str, t_env *env)
{
  char		**semicolon;
  int		i;

  semicolon = separator_to_tab(str, ';');
  if (semicolon == NULL)
    return (ERROR);
  i = 0;
  while (semicolon[i])
    {
      env->redir = false;
      env->redir_pipe = false;
      assess_instruction(semicolon[i], env);
      i += 1;
    }
  (semicolon != NULL) ? free_tab(semicolon) : 0;
  return (SUCCESS);
}

int		my_sh(char **ae)
{
  char		*command;
  t_env		env;

  prompt = false;
  if ((env.env = clone_env(ae)) == NULL)
    return (ERROR);
  disp_prompt(env.env);
  signal(SIGINT, signal_handler);
  while ((command = get_next_line(0)))
    {
      if (execute_loop(command, &env) == ERROR)
	return (ERROR);
      free(command);
      if (prompt == false)
	disp_prompt(env.env);
      prompt = false;
    }
  free_tab(env.env);
  if (isatty(0))
    write(1, "\n", 1);
  return (SUCCESS);
}
