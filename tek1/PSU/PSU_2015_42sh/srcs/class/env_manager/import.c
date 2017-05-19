/*
** import.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/import.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 13:00:41 2016 Antoine FORET
** Last update Sun Jun  5 19:27:16 2016 Gauthier Cler
*/

#include	"libc.h"

/*
** Import a env in the env object. It import for each line of ref an env entry
** @params self, ref env (char **)
** @return TRUE
*/
t_bool		env_manager_import(t_env_manager *self, char **ref)
{
  unsigned int	index;
  char		*entry[2];
  t_bool	set;

  index = 0;
  while (ref[index] != NULL)
    {
      set = FALSE;
      if (split(ref[index], entry, "="))
      {
	if (entry[1] != '\0')
	{
	  entry[1][0] = '\0';
	  entry[1] += 1;
	  set = TRUE;
	}
	self->set(self, entry[0], entry[1]);
	if (set)
	  (entry[1] - 1)[0] = '=';
      }
      index++;
    }
  return (TRUE);
}
