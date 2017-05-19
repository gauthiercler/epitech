/*
** draw_empty_maze.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun May 22 17:07:23 2016 Buyumad Anas
** Last update Sun May 22 17:07:41 2016 Buyumad Anas
*/

#include	"amazing.h"

void		draw_empty_maze(t_amazing *amazing)
{
  t_position	pos;
  SDL_Color	color;

  pos.x = 50;
  pos.y = 50;
  blit(amazing->Screen, amazing->Map, &pos);
  set_color(&color, BLACK);
  pos.y = 49;
  while (pos.y <= 451)
    {
      pos.x = 49;
      while (pos.x <= 451)
	{
	  if (pos.x == 49 || pos.x == 451 || pos.y == 49 || pos.y == 451)
	    set_pixel(amazing->Screen, &pos, &color);
	  pos.x += 1;
	}
      pos.y += 1;
    }
}
