/*
** draw_arena.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/bonus/graphic_code/draw_arena.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 02 19:19:07 2017 Anas Buyumad
** Last update Sun Apr 02 19:19:07 2017 Anas Buyumad
*/

#include		"lem_ipc.h"

static void		init_variables(SDL_Rect *outline, int *arena_d,
					  int *ratio, t_pos *cell_pix)
{
  *arena_d = 400;
  *ratio = *arena_d / arena_ss;
  outline->x = ((SCREEN_WIDTH / 2) / 2) - (*arena_d / 2) - 1;
  outline->y = 100;
  outline->w = 402;
  outline->h = 402;
  cell_pix->x = outline->x + 1;
}

static void		recalculate_cell(t_pos *cell_pix, int ratio,
					    SDL_Rect *cell_outline,
					    SDL_Rect *cell_fill)
{
  cell_outline->x = cell_pix->x;
  cell_outline->y = cell_pix->y;
  cell_outline->w = ratio;
  cell_outline->h = ratio;
  cell_fill->x = cell_outline->x;
  cell_fill->y = cell_outline->y;
  cell_fill->w = cell_outline->w;
  cell_fill->h = cell_outline->h;
}

static void		draw_frame(t_ipc *data, SDL_Rect *outline)
{
  SDL_SetRenderDrawColor(data->graphic.frames.screen, 209, 208, 206, 255);
  SDL_RenderDrawRect(data->graphic.frames.screen, outline);
  SDL_SetRenderDrawColor(data->graphic.frames.screen, 132, 132, 130, 255);
}

static void		increment_cell(t_pos *cell, t_pos *cell_pix,
					  char mode, int ratio)
{
  if (mode == 1)
  {
    cell->y += 1;
    cell_pix->y += ratio;
  }
  else if (mode == 2)
  {
    cell->x += 1;
    cell_pix->x += ratio;
  }
  else if (mode == 3)
  {
    cell->y = 0;
    cell_pix->y = ratio + 1;
  }
}

bool			draw_arena(t_ipc *data)
{
  SDL_Rect		outline;
  int			arena_dimension;
  int			ratio;
  t_pos			cell;
  t_pos			cell_pix;
  char			cellContent;
  SDL_Rect		cell_outline;
  SDL_Rect		cell_fill;

  init_variables(&outline, &arena_dimension, &ratio, &cell_pix);
  draw_frame(data, &outline);
  cell.x = 0;
  while (cell.x < arena_ss)
  {
    increment_cell(&cell, &cell_pix, 3, outline.y);
    while (cell.y < arena_ss)
    {
      recalculate_cell(&cell_pix, ratio, &cell_outline, &cell_fill);
      cellContent = data->memory->arena[CT(cell.x, cell.y)];
      draw_cell(data, cellContent, &cell_outline, &cell_fill);
      increment_cell(&cell, &cell_pix, 1, ratio);
    }
    increment_cell(&cell, &cell_pix, 2, ratio);
  }
  return (true);
}