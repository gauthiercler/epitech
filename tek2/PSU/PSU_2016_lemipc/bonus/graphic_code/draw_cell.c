/*
** draw_cell.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/bonus/graphic_code/draw_cell.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 02 20:08:50 2017 Anas Buyumad
** Last update Sun Apr 02 20:08:51 2017 Anas Buyumad
*/

#include		"lem_ipc.h"

static void		draw_wall(t_ipc *data, SDL_Rect *cell_outline,
				     SDL_Rect *cell_fill)
{
  cell_fill->x = cell_outline->x + 1;
  cell_fill->y = cell_outline->y + 1;
  cell_fill->w = cell_outline->w - 2;
  cell_fill->h = cell_outline->h - 2;
  SDL_SetRenderDrawColor(data->graphic.frames.screen,
			 data->graphic.t_palette[0].red,
			 data->graphic.t_palette[0].green,
			 data->graphic.t_palette[0].blue,
			 data->graphic.t_palette[0].alpha);
  SDL_RenderDrawRect(data->graphic.frames.screen, cell_outline);
  SDL_SetRenderDrawColor(data->graphic.frames.screen,
			 0x0, 0x0, 0x0, 255);
  SDL_RenderFillRect(data->graphic.frames.screen, cell_fill);
}

void			draw_cell(t_ipc *data, char cell_content,
				      SDL_Rect *cell_outline,
				      SDL_Rect *cell_fill)
{
  if (is_wall(cell_content))
    draw_wall(data, cell_outline, cell_fill);
  else if (cell_content == FREE_CELL || cell_content == TOMB_CELL)
  {
    SDL_SetRenderDrawColor(data->graphic.frames.screen,
			   0x0, 0x0, 0x0, 255);
    SDL_RenderFillRect(data->graphic.frames.screen, cell_fill);
  }
  else
  {
    SDL_SetRenderDrawColor(data->graphic.frames.screen,
			   data->graphic.palette[cell_content - 48].red,
			   data->graphic.palette[cell_content - 48].green,
			   data->graphic.palette[cell_content - 48].blue,
			   data->graphic.palette[cell_content - 48].alpha);
    SDL_RenderFillRect(data->graphic.frames.screen, cell_fill);
  }
  SDL_SetRenderDrawColor(data->graphic.frames.screen, 132, 132, 130, 255);
}