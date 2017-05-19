/*
** get_env.c for get_env in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 09:19:23 2016 Gauthier Cler
** Last update Sat Jan 23 18:30:55 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"../include/info.h"

char	*get_env(char **env, char *name)
{
  int	i;
  int	j;
  char	*res;

  init_var(&i, &j);
  while (env[i])
    {
      while (env[i][j] == name[j])
	j++;
      if (j == my_strlen(name))
	{
	  j = 0;
	  if ((res = malloc(sizeof(char) * my_strlen(env[i]) + 1)) == NULL)
	    malloc_error();
	  res[my_strlen(env[i])] = '\0';
	  while (j < my_strlen(env[i]))
	    {
	      res[j] = env[i][j + my_strlen(name) + 1];
	      j += 1;
	    }
	  return (res);
	}
      j = 0;
      i += 1;
    }
}

char	*get_env_list(t_env *env, char *name)
{
  int	j;
  char	*res;

  j = 0;
  while (env != NULL)
    {
      while (env->elem[j] == name[j])
	j++;
      if (j == my_strlen(name))
	{
	  j = 0;
	  if ((res = malloc(sizeof(char) * my_strlen(env->elem) + 1)) == NULL)
	    malloc_error();
	  res[my_strlen(env->elem)] = '\0';
	  while (j < my_strlen(env->elem))
	    {
	      res[j] = env->elem[j + my_strlen(name) + 1];
	      j += 1;
	    }
	  return (res);
	}
      j = 0;
      env = env->nxt;
    }
  return (NULL);
}
