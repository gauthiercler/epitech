/*
** no_pipe_command.c for no_pipe_command in /home/gogo/rendu/PSU_2015_minishell2/src/cmd
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr  5 14:15:55 2016 Gauthier Cler
** Last update Mon Apr 18 23:52:57 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

int		launch_command(char *instruction, t_env *env)
{
  char		**cmd;
  char		**path;

  path = gen_path(env->env);
  cmd = my_str_to_wordtab(instruction);
  if (cmd == NULL)
    return (ERROR);
  command_finder(env, cmd, path);
  (cmd != NULL) ? free_tab(cmd) : 0;
  (path != NULL) ? free_tab(path) : 0;
  return (SUCCESS);
}
