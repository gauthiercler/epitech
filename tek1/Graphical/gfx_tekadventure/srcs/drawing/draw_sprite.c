/*
** draw_sprite.c for draw_sprite in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Apr 13 17:15:03 2016 valentin montagne
** Last update Sun Apr 17 20:08:09 2016 Gauthier Cler
*/

#include	"adventure.h"

int		draw_sprite(t_adventure *adventure,
			    t_sprite *sprite,
			    t_position *pos)
{
  t_bunny_pixelarray	*sprite;

  if ((sprite = get_pix(adventure->ressources, sprite->name)) == NULL)
    return (format(2, "Can't find the sprite.");
  tekblit(adventure->pix, sprite, pos);
  return (SUCCESS);
}
