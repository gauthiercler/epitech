/*
** draw_decor.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 14:17:09 2016 Buyumad Anas
** Last update Sun Apr 17 20:14:45 2016 Gauthier Cler
*/

#include	"adventure.h"

int			draw_elem(t_adventure *adventure, t_elem *elems)
{
  int			i;
  t_bunny_position	pos;
  t_bunny_picture	*picture;

  i = 0;
  while (elems[i].name != NULL)
    {
      if ((picture = get_picture(adventure->ressources, elems[i].name)) == NULL)
	return (ERROR);
      pos.x = elems[i].pos.x;
      pos.y = elems[i].pos.y;
      if (elems[i].exists == true)
	bunny_blit(&adventure->window->buffer, picture, &pos);
      i++;
    }
  return (SUCCESS);
}

int		draw_decor(t_adventure *adventure, t_decor *decor)
{
  if ((draw_elem(adventure, decor->elems)) == ERROR)
    return (ERROR);
  if ((draw_elem(adventure, decor->dynamics)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
