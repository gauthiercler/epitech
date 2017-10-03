/*
** display_winner.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/display_winner.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 18:00:27 2017 Gauthier Cler
** Last update Sun Apr 02 18:00:27 2017 Gauthier Cler
*/

#include		"lem_ipc.h"

void			render_texture(t_ipc *data, SDL_Rect *rect,
					   SDL_Surface *arg)
{
  SDL_Texture		*texture;

  texture = SDL_CreateTextureFromSurface(data->graphic.frames.screen, arg);
  if (SDL_RenderCopy(data->graphic.frames.screen, texture, NULL, rect) == -1)
    display_sdl_error("Couldn't draw ArenaT");
}

void			display_winner(t_ipc *data)
{
  SDL_Rect		rect;

  SDL_SetRenderDrawColor(data->graphic.frames.screen, 0x0, 0x0, 0x0, 255);
  SDL_RenderFillRect(data->graphic.frames.screen, NULL);
  rect.x = ((SCREEN_WIDTH / 2) - (data->graphic.frames.team->w / 2));
  rect.y = (SCREEN_HEIGHT / 2) - (data->graphic.frames.team->h  / 2 + 100);
  rect.w = data->graphic.frames.team->w;
  rect.h = data->graphic.frames.team->h;
  render_texture(data, &rect, data->graphic.frames.team);
  rect.y += 100;
  rect.x = ((SCREEN_WIDTH / 2) -
    (data->graphic.teams[data->memory->winning_team].id->w / 2));
  rect.w = data->graphic.teams[data->memory->winning_team].id->w;
  rect.h = data->graphic.teams[data->memory->winning_team].id->h;
  render_texture(data, &rect, data->
    graphic.teams[data->memory->winning_team].id);
  rect.y += 100;
  rect.x = ((SCREEN_WIDTH / 2) - (data->graphic.frames.wins->w / 2));
  rect.w = data->graphic.frames.wins->w;
  rect.h = data->graphic.frames.wins->h;
  render_texture(data, &rect, data->graphic.frames.wins);
  SDL_RenderPresent(data->graphic.frames.screen);
  wait_end_event();
}