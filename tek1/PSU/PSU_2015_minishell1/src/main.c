/*
** main.c for main in /home/gauthier/rendu/PSU_2015_minishell1
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 11 11:26:10 2016 Gauthier Cler
** Last update Mon Jan 25 10:44:09 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"../include/info.h"

int	main(int ac, char **av, char **ae)
{
  t_env	*env;

  env = NULL;
  if (ac != 1 || ae[0] == NULL)
    return (0);
  fill_env(&env, ae);
  my_sh(env);
  return (0);
}

int	my_sh(t_env *env)
{
  char	*s;
  char	**exe;
  char	**path;
  char	**ae;

  my_prompt();
  while ((s = get_next_line(0)))
    {
      ae = generate_env(env);
      path = my_path_to_tab(get_env(ae, "PATH"));
      if ((exe = my_str_to_wordtab(s)) == NULL)
	my_prompt();
      else
	loop_sh(&env, exe, path, ae);
    }
}

int	current_dir_bin(char **exe, char **ae)
{
  pid_t	pid;
  int	status;

  if (access(exe[0], F_OK) == 0)
    {
      pid = fork();
      if (pid == -1)
	return (0);
      if (pid == 0)
	execve(exe[0], exe, ae);
      else
	{
	  waitpid(pid, &status, WUNTRACED | WCONTINUED);
	  if (WIFSIGNALED(status))
	    if (WTERMSIG(status) == 11)
	      my_putstr("Segmentation fault\n");
	    else if (WTERMSIG(status) == 8)
	      my_putstr("Floating exception\n");
	}
      return (0);
    }
  else
    my_putstr("Erreur d'execution\n");
}

int	loop_access(char **exe, char **path, char **ae)
{
  char	*abs;
  int	i;

  i = 0;
  if (path == NULL)
    return (0);
  while (path[i])
    {
      abs = my_strcat(my_strcat(path[i], "/"), exe[0]);
      if (access(abs, F_OK) == 0)
	{
	  if (execution(exe, ae, abs) == 1)
	    {
	      my_putstr("Erreur d'execution\n");
	      return (1);
	    }
	  return (1);
	}
      i++;
    }
  return (0);
}

int	execution(char **exe, char **ae, char *abs)
{
  pid_t	pid;
  int	status;

  pid = fork();
  if (pid == -1)
    return (1);
  if (pid == 0)
    execve(abs, exe, ae);
  else
    {
      waitpid(pid, &status, WUNTRACED | WCONTINUED);
      if (WIFSIGNALED(status))
	my_putstr("Segmentation fault\n");
    }
  return (0);
}
