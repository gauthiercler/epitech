/*
** init_blit.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat May 21 19:46:17 2016 Buyumad Anas
** Last update Sat May 21 19:55:52 2016 Buyumad Anas
*/

#include	"amazing.h"

void		set_cell_color(SDL_Color *color, t_position *pos, int type, int ratio)
{
  if ((((pos->x - 50) % (400 / ratio)) == 0) ||
      (((pos->y - 50) % (400 / ratio)) == 0))
    set_color(color, BLACK);
  else if (type == UNSET)
    set_color(color, GREY);
  else if (type == 8 || type == VISITED)
    set_color(color, RED);
  else if (type == WALL || type == WALL_DEPTH)
    set_color(color, BLUE);
  else if (type == PATH || type == POSSIBLE)
    set_color(color, WHITE);
  else if (type == WAITING)
    set_color(color, YELLOW);
  else if (type == EXIT || type == CONSIDERED)
    set_color(color, GREEN);
}

void		init_blit_maze(t_amazing *amazing, int *pos_y, int *pos_x,
			       int *row)
{
  (void)amazing;
  *pos_x = 50;
  *pos_y = 50;
  *row = 0;
}
