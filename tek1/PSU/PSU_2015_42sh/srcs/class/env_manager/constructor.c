/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 11:18:57 2016 Antoine FORET
** Last update Sun Jun  5 19:23:08 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"class/env_manager.h"

/*
** Define methods available for the env_manager object
** @params self
** @return void
*/
static void		env_manager_methods(t_env_manager *env)
{
  env->get = env_manager_get;
  env->add = env_manager_add;
  env->insert = env_manager_insert;
  env->import = env_manager_import;
  env->display = env_manager_display;
  env->destruct = env_manager_destructor;
  env->cache_clear = env_manager_cache_clear;
  env->generate_cache = env_manager_cache;
  env->export = env_manager_export;
  env->find = env_manager_find;
  env->set = env_manager_set;
  env->remove = env_manager_remove;
}

/*
** Generate a new env_manager object based on a classic env var
** @params ref env
** @return success -> env_manager object, failure -> NULL
*/
t_env_manager		*new_env_manager(char **env_tab)
{
  t_env_manager		*env;

  if ((env = malloc(sizeof(t_env_manager))) == NULL)
    return (NULL);
  env->values = NULL;
  env->cached = FALSE;
  env->cache = NULL;
  env->size = 0;
  env_manager_methods(env);
  if (!env->import(env, env_tab))
    {
      env->destruct(env);
      return (NULL);
    }
  return (env);
}
