/*
** delete_raytracer.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/deletion/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 10 14:01:32 2016 Buyumad Anas
** Last update Fri May 13 00:57:07 2016 Gauthier Cler
*/

#include	"raytracer.h"

static void	delete_obj(t_object *object, int nb_obj)
{
  int		i;

  i = 0;
  while (i < nb_obj)
    {
      if (object[i].type == POLYGON)
	{
	  if (object[i].infos.triangle != NULL)
	    bunny_free(object[i].infos.triangle);
	}
      if (object[i].infos.texture != NULL)
	bunny_free(object[i].infos.texture);
      i += 1;
    }
}

void		delete_raytracer(t_raytracer *raytracer)
{
  if (raytracer->pix != NULL)
    bunny_delete_clipable(&raytracer->pix->clipable);
  if (raytracer->win != NULL)
    bunny_stop(raytracer->win);
  bunny_free(raytracer->lux);
  delete_obj(raytracer->object, raytracer->nb_obj);
}
