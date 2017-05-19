/*
** fill_hitboxes.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 15:38:12 2016 Anas Buyumad
** Last update Sun Apr 17 20:11:01 2016 Gauthier Cler
*/

#include	"adventure.h"

void		fill_hitboxes(t_elem *elems, t_ressource *ressources)
{
  int		i;
  int		e;

  i = 0;
  while (elems[i].name != NULL)
    {
      e = 0;
      while (ressources[e].name != NULL)
	{
	  if (my_strcmp(elems[i].name, ressources[e].name) == SUCCESS)
	    {
	      elems[i].hitbox.x = ressources[e].size.x;
	      elems[i].hitbox.y = ressources[e].size.y;
	    }
	  e++;
	}
      i++;
    }
}

void		fill_levels_hitboxes(t_adventure *adventure)
{
  int		level;
  int		decor;

  level = 0;
  while (level < NB_LEVELS)
    {
      decor = 0;
      while (decor < NB_DECOR)
	{
	  fill_hitboxes(adventure->levels[level].decors[decor].elems,
			adventure->ressources);
          fill_hitboxes(adventure->levels[level].decors[decor].dynamics,
			adventure->ressources);
	  decor += 1;
	}
      level += 1;
    }
}
