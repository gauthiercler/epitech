/*
** chain_list.c for chain_list in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 18:17:45 2016 Gauthier Cler
** Last update Sun Jan 24 21:37:39 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"../include/info.h"

void		fill_env(t_env **env, char **ae)
{
  int		i;

  i = 0;
  while (ae[i])
    {
      add_end_list(env, ae[i]);
      i++;
    }
}

void		add_end_list(t_env **env, char *str)
{
  t_env		*tmp;
  t_env		*new;

  if ((new = malloc(sizeof(t_env))) == NULL)
    malloc_error();
  new->elem = my_strdup(str);
  new->nxt = NULL;
  if (*env == NULL)
    *env = new;
  else
    {
      tmp = *env;
      while (tmp->nxt != NULL)
	tmp = tmp->nxt;
      tmp->nxt = new;
    }
}

void	disp_env(t_env *env)
{
  while (env != NULL)
    {
      my_putstr(env->elem);
      my_putchar('\n');
      env = env->nxt;
    }
}

void	set_env(t_env **env, char **exe)
{
  int	i;

  i = 0;
  while (exe[i])
    i += 1;
  if (i == 1)
    disp_env(*env);
  else if (i != 3)
    my_putstr("Nombre d'arguments incorrect\n");
  else
    {
      delete_list(env, exe[1]);
      add_end_list(env, my_strcat(my_strcat(exe[1], "="), exe[2]));
    }
}

void	unset_env(t_env **env, char **exe)
{
  int	i;

  i = 0;
  while (exe[i])
    i += 1;
  if (i != 2)
    my_putstr("Nombre d'arguments incorrect\n");
  else
    delete_list(env, exe[1]);
}
