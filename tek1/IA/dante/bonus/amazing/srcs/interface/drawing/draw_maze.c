/*
** draw_maze.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 23:14:06 2016 Buyumad Anas
** Last update Sun May 22 17:08:39 2016 Buyumad Anas
*/

#include	"amazing.h"

void		draw_cell(t_amazing *amazing, int type, t_position *pos, int ratio)
{
  SDL_Color	color;
  t_position	end;
  t_position	save;

  save.x = pos->x;
  save.y = pos->y;
  end.x = pos->x + 400 / ratio;
  end.y = pos->y + 400 / ratio;
  while (pos->y <= end.y)
    {
      pos->x = save.x;
      while (pos->x <= end.x)
	{
	  set_cell_color(&color, pos, type, ratio);
	  set_pixel(amazing->Screen, pos, &color);
	  pos->x += 1;
	}
      pos->y += 1;
    }
  pos->x -= 1;
  pos->y = save.y;
}

void		draw_maze(t_amazing *amazing)
{
  t_position	pos;
  int		ratio;
  int		row;
  int		column;

  init_blit_maze(amazing, &pos.y, &pos.x, &row);
  if (amazing->width >= amazing->height)
    ratio = amazing->width;
  else
    ratio = amazing->height;
  blit(amazing->Screen, amazing->Map, &pos);
  while (row < amazing->perfect.map.height)
    {
      column = 0;
      pos.x = 50;
      while (column < amazing->perfect.map.width)
	{
	  draw_cell(amazing, amazing->perfect.map.cells[row][column], &pos,
		    ratio);
	  column += 1;
	}
      pos.y += 400 / ratio;
      row += 1;
    }
}

void		draw_maze_depth(t_amazing *amazing)
{
  t_position	pos;
  int		ratio;
  int		row;
  int		column;

  init_blit_maze(amazing, &pos.y, &pos.x, &row);
  if (amazing->width >= amazing->height)
    ratio = amazing->width;
  else
    ratio = amazing->height;
  blit(amazing->Screen, amazing->Map, &pos);
  while (row < amazing->solver.map.size_y)
    {
      column = 0;
      pos.x = 50;
      while (column < amazing->solver.map.size_x)
	{
	  draw_cell(amazing, amazing->solver.map.array[row][column], &pos,
		    ratio);
	  column += 1;
	}
      pos.y += 400 / ratio;
      row += 1;
    }
}

void		draw_maze_breadth(t_amazing *amazing)
{
  t_position	pos;
  int		ratio;
  int		row;
  int		column;

  init_blit_maze(amazing, &pos.y, &pos.x, &row);
  if (amazing->width >= amazing->height)
    ratio = amazing->width;
  else
    ratio = amazing->height;
  blit(amazing->Screen, amazing->Map, &pos);
  while (row < amazing->solver_breadth.map.size_y)
    {
      column = 0;
      pos.x = 50;
      while (column < amazing->solver_breadth.map.size_x)
	{
	  draw_cell(amazing, amazing->solver_breadth.map.array[row][column],
		    &pos, ratio);
	  column += 1;
	}
      pos.y += 400 / ratio;
      row += 1;
    }
  usleep(amazing->speed);
}

void		draw_maze_star(t_amazing *amazing)
{
  t_position	pos;
  int		ratio;
  int		row;
  int		column;

  init_blit_maze(amazing, &pos.y, &pos.x, &row);
  if (amazing->width >= amazing->height)
    ratio = amazing->width;
  else
    ratio = amazing->height;
  blit(amazing->Screen, amazing->Map, &pos);
  while (row < amazing->solve_astar.map.size_y)
    {
      column = 0;
      pos.x = 50;
      while (column < amazing->solve_astar.map.size_x)
	{
	  draw_cell(amazing, amazing->solve_astar.map.array[row][column],
		    &pos, ratio);
	  column += 1;
	}
      pos.y += 400 / ratio;
      row += 1;
    }
  usleep(amazing->speed);
}
