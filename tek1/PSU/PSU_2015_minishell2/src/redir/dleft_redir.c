/*
** dleft_redir.c for dleft_redir in /home/gogo/rendu/PSU_2015_minishell2/src/redir
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 12 22:18:05 2016 Gauthier Cler
** Last update Mon Apr 18 19:41:21 2016 Gauthier Cler
*/

#include		<sys/types.h>
#include		<sys/wait.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"mysh.h"

int			is_end(char *str1, char *str2)
{
  int			i;

  i = 0;
  if (str1 == NULL)
    return (SUCCESS);
  if (my_strlen(str1) != my_strlen(str2))
    return (ERROR);
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

char			*my_realloc(char *save, char *str)
{
  char			*new;
  int			i;
  int			j;

  new = xmalloc(sizeof(char) * my_strlen(save) + my_strlen(str) + 2);
  j = 0;
  i = 0;
  while (save[i])
    {
      new[j++] = save[i];
      i += 1;
    }
  i = 0;
  while (str[i])
    {
      new[j++] = str[i];
      i += 1;
    }
  new[j] = '\n';
  new[j + 1] = '\0';
  (save != NULL) ? free(save) : 0;
  return (new);
}

char			*first_alloc(char *str)
{
  char			*new;
  int			i;

  i = 0;
  new = xmalloc(sizeof(char) * my_strlen(str) + 2);
  while (str[i])
    {
      new[i] = str[i];
      i += 1;
    }
  new[i] = '\n';
  new[i + 1] = '\0';
  return (new);
}

int			send_save(t_redir *redir, t_env *env, char *save)
{
  pid_t			pid;
  int			status;
  int			tmp[2];

  pipe(tmp);
  format(tmp[1], "%s", save);
  if ((pid = fork()) == -1)
    return (format(2, "Failed to fork\n"));
  if (pid == 0)
    {
      dup2(tmp[0], 0);
      close(tmp[1]);
      launch_command(redir->arg1, env);
      exit(1);
    }
  else
    {
      close(tmp[0]);
      close(tmp[1]);
      wait(&status);
    }
  return (SUCCESS);
}

int			dleft_redir(t_redir *redir, t_env *env)
{
  char			*str;
  char			*save;

  save = NULL;
  if (my_strlen(redir->arg2) == 0)
    return (format(2, "Missing name for redirect.\n"));
  format(1, "? ");
  if ((str = get_next_line(0)) == NULL)
    return (ERROR);
  while (my_strcmp(str, redir->arg2) != SUCCESS)
    {
      if (save == NULL)
	save = first_alloc(str);
      else
	save = my_realloc(save, str);
      format(1, "? ");
      (str != NULL) ? free(str) : 0;
      if ((str = get_next_line(0)) == NULL)
	return (ERROR);
    }
  if (send_save(redir, env, save) == ERROR)
    return (ERROR);
  (save != NULL) ? free(save) : 0;
  return (SUCCESS);
}
