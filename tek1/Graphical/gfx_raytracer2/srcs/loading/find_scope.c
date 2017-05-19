/*
** find_scope.c for find_scope in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Wed May  4 15:56:23 2016 montag_v
** Last update Wed May  4 15:57:53 2016 montag_v
*/

#include	"raytracer.h"

int		find_scope(t_bunny_ini *ini, char **scope, char *origin, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if ((scope[i] =
	   (char *)bunny_ini_get_field(ini, origin, "names", i)) == NULL)
	return (format(2, "find_scope : Couldn't read the file .ini\n"));
      i += 1;
    }
  scope[i] = NULL;
  return (SUCCESS);
}
