/*
** command_finder.c for command_finder in /home/gogo/rendu/PSU_2015_minishell2/src/cmd
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 16:30:04 2016 Gauthier Cler
** Last update Tue Apr 19 00:02:37 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	"mysh.h"

bool		is_builtin(char **cmd)
{
  if (my_strcmp(cmd[0], "env") == SUCCESS
      || my_strcmp(cmd[0], "setenv") == SUCCESS
      || my_strcmp(cmd[0], "unsetenv") == SUCCESS
      || my_strcmp(cmd[0], "cd") == SUCCESS
      || my_strcmp(cmd[0], "exit") == SUCCESS)
    return (true);
  else
    return (false);
}

void		command_finder(t_env *env, char **cmd, char **path)
{
  if (cmd == NULL)
    return ;
  if (my_strlen(cmd[0]) == 0)
    return ;
  (my_strcmp(cmd[0], "env") == SUCCESS) ? disp_env(env) : 0;
  (my_strcmp(cmd[0], "exit") == SUCCESS) ? my_exit(cmd) : 0;
  (my_strcmp(cmd[0], "setenv") == SUCCESS) ? set_env(env, cmd) : 0;
  (my_strcmp(cmd[0], "unsetenv") == SUCCESS) ? unset_env(env, cmd) : 0;
  (my_strcmp(cmd[0], "cd") == SUCCESS) ? my_cd(env, cmd) : 0;
  if (is_builtin(cmd) == false)
    if (path_exec(env, cmd, path) == ERROR)
      current_dir_exec(env, cmd);
}
