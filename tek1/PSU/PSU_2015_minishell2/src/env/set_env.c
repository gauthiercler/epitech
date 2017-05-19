/*
** set_env.c for set_env in /home/gogo/rendu/PSU_2015_minishell2/src/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Apr  3 00:46:37 2016 Gauthier Cler
** Last update Wed Apr 13 14:16:14 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

char		*add_elem(char **cmd)
{
  char		*elem;
  char		*tmp;

  tmp = my_strcat(cmd[1], "=");
  if (cmd[2] == NULL)
    elem = my_strcat(tmp, "");
  else
    elem = my_strcat(tmp, cmd[2]);
  (tmp != NULL) ? free(tmp) : 0;
  return (elem);
}

int		tab_len(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  return (i);
}

void		add_to_env(t_env *env, char **cmd)
{
  int		exist;
  char		**res;
  char		*tmp;
  int		i;
  int		j;

  j = 0;
  i = 0;
  tmp = my_strcat(cmd[1], "=");
  if ((exist = check_env(env->env, tmp)) != -1)
    res = xmalloc(sizeof(char *) * (tab_len(env->env) + 1));
  else
    res = xmalloc(sizeof(char *) * (tab_len(env->env) + 2));
  while (env->env[i])
    {
      (my_strncmp(env->env[i], tmp, my_strlen(tmp)) == SUCCESS) ? i += 1 : 0;
      (env->env[i] != NULL) ? res[j++] = my_strdup(env->env[i]) : 0;
      (env->env[i] != NULL) ? i += 1 : 0;
    }
  (tmp != NULL) ? free(tmp) : 0;
  res[j] = add_elem(cmd);
  res[j + 1] = NULL;
  (env->env != NULL) ? free_tab(env->env) : 0;
  env->env = res;
}

int		set_env(t_env *env, char **cmd)
{
  if (cmd[1] == NULL)
    {
      disp_env(env);
      return (SUCCESS);
    }
  if (tab_len(cmd) > 3)
    return (format(2, "setenv: Too many arguments.\n"));
  add_to_env(env, cmd);
  return (SUCCESS);
}
