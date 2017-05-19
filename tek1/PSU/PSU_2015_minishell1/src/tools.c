/*
** malloc.c for malloc in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jan 23 18:24:06 2016 Gauthier Cler
** Last update Fri Feb 12 15:20:58 2016 Gauthier Cler
*/

#include	<signal.h>
#include	<stdlib.h>
#include	"../include/info.h"

void	malloc_error()
{
  my_putstr("Erreur de malloc\n");
  exit(0);
}

void	signal_handler(int sig)
{
  if (sig == SIGINT)
    my_putstr("\n$>");
  else if (sig == SIGSEGV)
    my_putstr("Segmentation fault\n");
}

void	my_prompt()
{
  my_putstr("$>");
  signal(SIGINT, signal_handler);
}

void	loop_sh(t_env **env, char **exe, char **path, char **ae)
{
  if (my_strcmp(exe[0], "env") == 1)
    disp_env(*env);
  else if (my_strcmp(exe[0], "setenv") == 1)
    set_env(env, exe);
  else if (my_strcmp(exe[0], "unsetenv") == 1)
    unset_env(env, exe);
  else if (my_strcmp(exe[0], "cd") == 1 && exe[1] != NULL)
    my_cd(env, exe);
  else if (my_strcmp(exe[0], "exit") == 1)
    my_exit(exe[1]);
  else if (loop_access(exe, path, ae) == 0)
    current_dir_bin(exe, ae);
  my_prompt();
}
