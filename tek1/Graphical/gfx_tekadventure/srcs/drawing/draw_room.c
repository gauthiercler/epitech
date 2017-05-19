/*
** draw_room.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 18:14:16 2016 Buyumad Anas
** Last update Sun Apr 17 23:34:30 2016 Gauthier Cler
*/

#include	"adventure.h"

void		draw_graphs(t_adventure *adventure, t_room *room)
{
  t_bunny_position	pos;
  int			i;

  i = 0;
  while (room->graphs[i].links != NULL)
    {
      pos.x = room->graphs[i].pos.x;
      pos.y = room->graphs[i].pos.y;
      bunny_blit(&adventure->window->buffer, adventure->node, &pos);
      i += 1;
    }
}

int		draw_room(t_adventure *adventure, t_room *room)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  bunny_blit(&adventure->window->buffer, room->background, &pos);
  pos.x = 925;
  pos.y = 0;
  bunny_blit(&adventure->window->buffer, adventure->back_button, &pos);
  draw_graphs(adventure, room);
  return (SUCCESS);
}
