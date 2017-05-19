/*
** load_ressources.c for load_ressources in /home/gogo/rendu/gfx_tekadventure
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 14 15:30:10 2016 Gauthier Cler
** Last update Sun Apr 17 20:48:01 2016 Buyumad Anas
*/

#include	"adventure.h"

int		fill_ressource(t_bunny_ini *ini,
			       t_ressource *ressource,
			       int current)
{
  if ((ressource->name =
       my_strdup(bunny_ini_get_field(ini, "ressources", "names",
				     current))) == NULL)
    return (format(2, "No name at %d\n", current));
  if ((ressource->picture = bunny_load_picture(ressource->name)) == NULL)
    return (ERROR);
  ressource->size.x = ressource->picture->clip_width;
  ressource->size.y = ressource->picture->clip_height;
  return (SUCCESS);
}

t_ressource	*load_ressources(char *filename)
{
  t_ressource	*ressource;
  t_bunny_ini	*ini;
  int		i;
  int		nb;

  i = 0;
  if ((ini = bunny_load_ini(filename)) == NULL)
    return (p_error("load_ressources : Couldn't load the file\n"));
  if ((nb = my_atoi(bunny_ini_get_field(ini, "ressources",
				   "nb_ressources", 0))) < 0)
    return (p_error("load_ressources : nb_ressources < 0\n"));
  if ((ressource = bunny_malloc(sizeof(t_ressource) * (nb + 1))) == NULL)
    return (p_error("Couldn't malloc.\n"));
  while (i < nb)
    {
      if (fill_ressource(ini, &ressource[i], i) == ERROR)
	return (NULL);
      i++;
    }
  ressource[i].name = NULL;
  bunny_delete_ini(ini);
  return (ressource);
}
