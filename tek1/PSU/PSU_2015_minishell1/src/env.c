/*
** env.c for env in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Jan 20 00:27:32 2016 Gauthier Cler
** Last update Sun Jan 24 23:15:48 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../include/info.h"

int	delete_list(t_env **env, char *name)
{
  t_env *tmp;
  t_env	*prev;
  char	*abs;
  int	i;

  i = 0;
  abs = my_strcat(name, "=");
  prev = *env;
  tmp = prev;
  while (tmp != NULL)
    {
      if (my_strncmp(tmp->elem, abs, my_strlen(abs)) == 1)
	{
	  if (i == 0)
	    {
	      *env = tmp->nxt;
	      return (0);
	    }
	  prev->nxt = tmp->nxt;
	  return (0);
	}
      prev = tmp;
      tmp = tmp->nxt;
      i += 1;
    }
}

int	my_cd(t_env **env, char **exe)
{
  char	path[4096];
  char	*old;

  if (my_strlen_double(exe) != 2)
    {
      my_putstr("cd: Too many arguments.\n");
      return (0);
    }
  old = get_env_list(*env, "OLDPWD");
  delete_list(env, "PWD");
  delete_list(env, "OLDPWD");
  getcwd(path, 4096);
  add_end_list(env, my_strcat(my_strcat("OLDPWD", "="), path));
  if (my_strlen(exe[1]) == 1 && exe[1][0] == '-')
    {
      if (chdir(old) == -1)
	my_putstr("Erreur chdir");
    }
  else
    {
      if (chdir(exe[1]) == -1)
	my_putstr("Argument incorrect\n");
    }
  getcwd(path, 4096);
  add_end_list(env, my_strcat(my_strcat("PWD", "="), path));
}

int	my_exit(char *arg)
{
  if (arg == NULL)
    exit(0);
  exit(my_atoi(arg));
}

char	**generate_env(t_env *env)
{
  char	**res;
  t_env	*tmp;
  int	i;
  int	j;

  i = 0;
  tmp = env;
  while (tmp != NULL)
    {
      i++;
      tmp  = tmp->nxt;
    }
  if ((res = malloc(sizeof(char *) * i + 1)) == NULL)
    malloc_error();
  res[i] = NULL;
  tmp = env;
  i = 0;
  while (tmp != NULL)
    {
      res[i] = env_fill_loop(tmp);
      i += 1;
      tmp = tmp->nxt;
    }
  return (res);
}

char 	*env_fill_loop(t_env *tmp)
{
  char	*res;
  int	i;

  i = 0;
  if ((res = malloc(sizeof(char) * my_strlen(tmp->elem) + 1)) == NULL)
    malloc_error();
  while (tmp->elem[i])
    {
      res[i] = tmp->elem[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}
