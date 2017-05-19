/*
** research_path.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/research_path.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 31 09:28:51 2016 Antoine FORET
** Last update Sun Jun  5 19:31:46 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"class/env_manager.h"
#include	"config.h"
#include	"libc.h"

/*
** Test paths for command
** @params path, bin name
** @return success -> path, error -> NULL
*/
static char	*test_paths(char *path, const char *bin_name)
{
  unsigned int	index;
  char		*base_path;
  char		*full_path;

  index = 0;
  while ((base_path = extract(path, PATH_DELIMITER, index)) != NULL)
    {
      full_path = strcat_ret_only(base_path, bin_name, '/');
      free(base_path);
      if (access(full_path, F_OK | X_OK) == 0)
	return (full_path);
      free(full_path);
      index++;
    }
  return (NULL);
}

/*
** Search path for command
** @params env, bin name
** @return success -> path, error -> NULL
*/
char		*command_search_path(t_env_manager *env, const char *bin_name)
{
  char		*path;
  t_env_entry	*path_env;

  if ((path_env = env->find(env, PATH_ENV)) == NULL)
    return (NULL);
  path = test_paths(path_env->value, bin_name);
  return (path);
}
