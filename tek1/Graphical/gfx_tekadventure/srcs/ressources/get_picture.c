/*
** get_picture.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/ressources/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 23:12:26 2016 Buyumad Anas
** Last update Sun Apr 17 20:00:26 2016 Gauthier Cler
*/

#include	"adventure.h"

t_bunny_picture		*get_picture(t_ressource *ressources, char *name)
{
  int		i;

  i = 0;
  while (ressources[i].name != NULL)
    {
      if (my_strcmp(name, ressources[i].name) == SUCCESS)
	return (ressources[i].picture);
      i++;
    }
  return (NULL);
}
