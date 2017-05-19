/*
** my_cd.c for my_cd in /home/gogo/rendu/PSU_2015_minishell2/src/cmd
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Apr  3 02:02:53 2016 Gauthier Cler
** Last update Tue Apr 12 23:24:17 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"

int		check_pwd(char *current)
{
  if (my_strncmp(current, "PWD=", 4) == SUCCESS)
    return (SUCCESS);
  if (my_strncmp(current, "OLDPWD=", 7) == SUCCESS)
    return (SUCCESS);
  return (ERROR);
}

char		**add_cd(char **save, char *old, char *new)
{
  char		**env;
  int		count;
  int		i;
  int		j;
  char		*tmp;

  j = 0;
  i = -1;
  count = 0;
  (check_env(save, "PWD=") == -1) ? count += 1 : 0;
  (check_env(save, "OLDPWD=") == -1) ? count += 1 : 0;
  env = xmalloc(sizeof(char *) * (tab_len(save) + 1 + count));
  while (save[++i])
    if (check_pwd(save[i]) == ERROR)
      env[j++] = my_strdup(save[i]);
  tmp = my_strcat("PWD=", new);
  env[j] = my_strdup(tmp);
  (tmp != NULL) ? free(tmp) : 0;
  tmp = my_strcat("OLDPWD=", old);
  env[j + 1] = my_strdup(tmp);
  env[j + 2] = NULL;
  (tmp != NULL) ? free(tmp) : 0;
  free_tab(save);
  return (env);
}

int		my_cd(t_env *env, char **cmd)
{
  char		*old;
  char		*new;
  char		a[4096];
  int		is;

  if (tab_len(cmd) > 2)
    return (format(2, "cd: Too many arguments.\n"));
  old = my_strdup(getcwd(a, 4096));
  if (cmd[1] == NULL)
    ((is = check_env(env->env, "HOME=")) != -1) ? chdir(env->env[is] + 5) : 0;
  else if (my_strcmp(cmd[1], "-") == SUCCESS)
    ((is = check_env(env->env, "OLDPWD=")) != -1) ? chdir(env->env[is] + 7) : 0;
  else
    (chdir(cmd[1]) == -1) ? format(2, "%s: Bad argument.\n", cmd[1]) : 0;
  new = my_strdup(getcwd(a, 4096));
  env->env = add_cd(env->env, old, new);
  (old != NULL) ? free(old) : 0;
  (new != NULL) ? free(new) : 0;
  return (SUCCESS);
}
