/*
** freetab.c for freetab in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May 11 16:18:26 2016 montag_v
** Last update Fri May 13 00:43:56 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		freetab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  if (tab[i] != NULL)
	    bunny_free(tab[i]);
	  i += 1;
	}
      bunny_free(tab);
    }
}
