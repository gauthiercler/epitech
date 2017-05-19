/*
** process_request.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/cd/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 28 00:45:19 2016 Gauthier Cler
** Last update Fri Jun  3 18:22:42 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>
#include		<errno.h>
#include		"class/cd.h"

/* Go back to home dir with home path
** @params self, env
** @return t_bool success -> TRUE, failure -> FALSE
*/
static t_bool		home_dir(t_cd *self, t_env_manager *env)
{
  self->home_path = env->find(env, "HOME");
  if (self->home_path == NULL)
    {
      fprintf(stderr, "cd: No home directory.\n");
      return (FALSE);
    }
  if (self->get_pwd(self) != FALSE)
    env->set(env, "OLDPWD", self->pwd);
  if (chdir(self->home_path->value) == -1)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (FALSE);
    }
  if (self->get_pwd(self) != FALSE)
    env->set(env, "PWD", self->pwd);
  return (TRUE);
}

/*
** Go back to previous dir stocked in env
** @params self, env
** @return t_bool success -> TRUE, failure -> FALSE
*/
static t_bool		previous_dir(t_cd *self, t_env_manager *env)
{
  if (self->get_old_pwd(self, env) == FALSE)
    {
      fprintf(stderr, "cd: No old pwd\n");
      return (FALSE);
    }
  self->get_pwd(self);
  if (chdir(self->old_pwd->value) == -1)
    {
      fprintf(stderr, "%s.\n", strerror(errno));
      return (FALSE);
    }
  env->set(env, "PWD", self->old_pwd->value);
  if (self->pwd != NULL)
    env->set(env, "OLDPWD", self->pwd);
  return (TRUE);
}

/*
** Go to the request path
** @params self, env, request
** @return t_bool success -> TRUE, failure -> FALSE
*/
static t_bool		standard_request(t_cd *self, t_env_manager *env,
					 char *request)
{
  if (self->get_pwd(self) != FALSE)
    env->set(env, "OLDPWD", self->pwd);
  if (chdir(request) == -1)
    {
      fprintf(stderr, "%s: %s.\n", request, strerror(errno));
      return (FALSE);
    }
  if (self->get_pwd(self) != FALSE)
    env->set(env, "PWD", self->pwd);
  return (TRUE);
}
/*
** Process the request for the right type
** @params self, env, request (for standard_request)
** @return t_bool success -> TRUE, failure -> FALSE
*/
t_bool			cd_process_request(t_cd *self, t_env_manager *env,
					   char *request)
{
  if (self->request_type == PREVIOUS)
    return (previous_dir(self, env));
  else if (self->request_type == EMPTY)
    return (home_dir(self, env));
  else
    return (standard_request(self, env, request));
}
