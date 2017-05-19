/*
** get_old_pwd.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 11:36:50 2016 Gauthier Cler
** Last update Tue May 31 00:17:43 2016 Gauthier Cler
*/

#include	"bool.h"
#include	"class/cd.h"

/*
** Get the old pwd if it exist from env array
** @params self, env
** @return t_bool success -> TRUE, failure FALSE
*/
t_bool		cd_get_old_pwd(t_cd *self, t_env_manager *env)
{
  self->old_pwd = env->find(env, "OLDPWD");
  if (self->old_pwd == NULL)
    return (FALSE);
  return (TRUE);
}
