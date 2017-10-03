/*
** display.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/display.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 17:43:19 2017 Gauthier Cler
** Last update Sun Apr 02 17:43:21 2017 Gauthier Cler
*/

#include		"lem_ipc.h"

bool			display_players(t_ipc *data)
{
  SDL_Texture		*texture;
  SDL_Rect		rect;
  char			nb_players[4];
  int			idx;

  idx = 0;
  memset(nb_players, '\0', 4);
  sprintf(nb_players, "%d", data->memory->concurrent_players);
  rect.x = (SCREEN_WIDTH / 2) + ((SCREEN_WIDTH / 2) / 2) -
	   (((int)strlen(nb_players) * 50));
  rect.y = 450;
  while (nb_players[idx])
  {
    rect.x += 50;
    rect.w = data->graphic.teams[nb_players[idx] - 48].id->w;
    rect.h = data->graphic.teams[nb_players[idx] - 48].id->h;
    texture = SDL_CreateTextureFromSurface(data->graphic.frames.screen,
					   data->graphic.
					     teams[nb_players[idx] - 48].id);
    if (SDL_RenderCopy(data->graphic.frames.screen, texture,
		       NULL, &rect) == -1)
      display_sdl_error("Couldn't draw ArenaT");
    idx += 1;
  }
  return (true);
}

static bool		team_alive(char *arena, int team)
{
  int			cell;

  cell = 0;
  while (cell < arena_size)
  {
    if (arena[cell] == team + 48)
      return (true);
    cell += 1;
  }
  return (false);
}

void			draw_team(t_ipc *data, SDL_Rect *rect, int idx)
{
  SDL_Texture		*texture;

  if (team_alive(data->memory->arena, idx))
  {
    rect->x = ((SCREEN_WIDTH / 2) + 50 + ((idx % 3) * 170));
    rect->y = 100 + ((idx / 3) * data->graphic.teams[idx].id->h + 50);
    rect->w = data->graphic.teams[idx].id->w;
    rect->h = data->graphic.teams[idx].id->h;
    texture = SDL_CreateTextureFromSurface(data->graphic.frames.screen,
					   data->graphic.teams[idx].id);
    if (SDL_RenderCopy(data->graphic.frames.screen,
		       texture, NULL, rect) == -1)
      display_sdl_error("Couldn't draw ArenaT");
    rect->x += 100;
    rect->y += 40;
    rect->w = 25;
    rect->h = 25;
    SDL_SetRenderDrawColor(data->graphic.frames.screen,
			   data->graphic.palette[idx].red,
			   data->graphic.palette[idx].green,
			   data->graphic.palette[idx].blue,
			   data->graphic.palette[idx].alpha);
    SDL_RenderFillRect(data->graphic.frames.screen, rect);
  }
}

bool			display_teams(t_ipc *data)
{
  SDL_Rect		rect;
  int			idx;

  clear_screen(data);
  idx = 0;
  while (idx < 9)
  {
    draw_team(data, &rect, idx);
    idx += 1;
  }
  return (true);
}

void			clear_screen(t_ipc *data)
{
  SDL_Rect		clear;

  clear.x = (SCREEN_WIDTH / 2) + 10;
  clear.y = 100;
  clear.w = (SCREEN_WIDTH / 2);
  clear.h = 450;
  SDL_SetRenderDrawColor(data->graphic.frames.screen, 0x0, 0x0, 0x0, 255);
  SDL_RenderFillRect(data->graphic.frames.screen, &clear);
}