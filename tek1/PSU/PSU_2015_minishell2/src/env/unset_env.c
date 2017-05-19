/*
** unset_env.c for unset_env in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Apr  3 01:27:44 2016 Gauthier Cler
** Last update Tue Apr 12 21:48:28 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

int		find_existing_env(char **save, char **cmd)
{
  int		count;
  int		i;
  char		*tmp;

  i = 0;
  count = 0;
  while (cmd[i])
    {
      tmp = my_strcat(cmd[i], "=");
      if (check_env(save, tmp) != -1)
	count += 1;
      (tmp != NULL) ? free(tmp) : 0;
      i += 1;
    }
  return (count);
}

int		check_existing_loop(char *current, char **cmd)
{
  char		*tmp;
  int		i;

  i = 0;
  while (cmd[i])
    {
      tmp = my_strcat(cmd[i], "=");
      if (my_strncmp(current, tmp, my_strlen(tmp)) == SUCCESS)
	{
	  (tmp != NULL) ? free(tmp) : 0;
	  return (SUCCESS);
	}
      i += 1;
      (tmp != NULL) ? free(tmp) : 0;
    }
  return (ERROR);
}

char		**remove_env(char **save, char **cmd)
{
  int		count;
  char		**env;
  int		i;
  int		j;

  j = 0;
  i = 0;
  count = find_existing_env(save, cmd);
  env = xmalloc(sizeof(char *) * (tab_len(save) - count + 1));
  while (save[i])
    {
      if (check_existing_loop(save[i], cmd) == ERROR)
	{
	  env[j] = my_strdup(save[i]);
	  j += 1;
	}
      i += 1;
    }
  env[j] = NULL;
  free_tab(save);
  return (env);
}

int		unset_env(t_env *env, char **cmd)
{
  if (cmd[1] == NULL)
    return (format(2, "unsetenv: Too few arguments.\n"));
  env->env = remove_env(env->env, cmd + 1);
  return (SUCCESS);
}
