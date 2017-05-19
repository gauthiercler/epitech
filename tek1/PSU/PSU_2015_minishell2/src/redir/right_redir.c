/*
** right_redir.c for right_redir in /home/gogo/rendu/PSU_2015_minishell2/src/redir
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  9 14:18:59 2016 Gauthier Cler
** Last update Tue Apr 12 22:20:27 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"mysh.h"

int		right_redir(t_redir *redir, t_env *env)
{
  env->redir = true;
  if (my_strlen(redir->arg2) == 0)
    return (format(2, "Missing name for redirect.\n"));
  if ((env->fd_file = open(redir->arg2, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			   | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
			   | S_IWOTH)) == -1)
    return (format(2, "Error while opening %s.\n", redir->arg2));
  if (check_pipe(redir->arg1) == SUCCESS)
    {
      env->redir_pipe = true;
      env->redir = false;
      pipe_command(redir->arg1, env);
    }
  else
    launch_command(redir->arg1, env);
  close(env->fd_file);
  return (SUCCESS);
}
