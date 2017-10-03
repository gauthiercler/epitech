/*
** draw.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/draw.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 17:07:47 2017 Gauthier Cler
** Last update Sun Apr 02 17:07:47 2017 Gauthier Cler
*/

#include		"lem_ipc.h"

bool			draw_authors(t_graphic *graphic)
{
  SDL_Texture		*texture;
  SDL_Rect		rect;

  rect.x = 0 + 50;
  rect.y = SCREEN_HEIGHT - graphic->frames.title->h -
	   (graphic->frames.anas->h / 2);
  rect.w = graphic->frames.anas->w;
  rect.h = graphic->frames.anas->h;
  texture = SDL_CreateTextureFromSurface(graphic->frames.screen,
					 graphic->frames.anas);
  if (SDL_RenderCopy(graphic->frames.screen, texture, NULL, &rect) == -1)
    display_sdl_error("Couldn't draw anas ");
  rect.w = graphic->frames.gauthier->w;
  rect.h = graphic->frames.gauthier->h;
  rect.x = SCREEN_WIDTH - 50 - rect.w;
  rect.y = SCREEN_HEIGHT - graphic->frames.title->h -
	   (graphic->frames.gauthier->h / 2);
  texture = SDL_CreateTextureFromSurface(graphic->frames.screen,
					 graphic->frames.gauthier);
  if (SDL_RenderCopy(graphic->frames.screen, texture, NULL, &rect) == -1)
    display_sdl_error("Couldn't draw gauthier ");
  return (true);
}

bool			draw_teams_t(t_graphic *graphic)
{
  SDL_Texture		*texture;
  SDL_Rect		rect;

  rect.x = ((SCREEN_WIDTH / 2) + ((SCREEN_WIDTH / 2) / 2)) -
	   (graphic->frames.teams->w/ 2);
  rect.y = 0;
  rect.w = graphic->frames.teams->w;
  rect.h = graphic->frames.teams->h;
  texture = SDL_CreateTextureFromSurface(graphic->frames.screen,
					 graphic->frames.teams);
  if (SDL_RenderCopy(graphic->frames.screen, texture, NULL, &rect) == -1)
    display_sdl_error("Couldn't draw teams ");
  return (true);
}

bool			draw_lemipc(t_graphic *graphic)
{
  SDL_Texture		*texture;
  SDL_Rect		rect;

  rect.x = (SCREEN_WIDTH / 2) - (graphic->frames.title->w/ 2);
  rect.y = SCREEN_HEIGHT - graphic->frames.title->h - 50;
  rect.w = graphic->frames.title->w;
  rect.h = graphic->frames.title->h;
  texture = SDL_CreateTextureFromSurface(graphic->frames.screen,
					 graphic->frames.title);
  if (SDL_RenderCopy(graphic->frames.screen, texture, NULL, &rect) == -1)
    display_sdl_error("Couldn't draw lemIPC ");
  SDL_SetRenderDrawColor(graphic->frames.screen, graphic->t_palette[0].red,
			 graphic->t_palette[0].green,
			 graphic->t_palette[0].blue,
			 graphic->t_palette[0].alpha);
  SDL_RenderDrawLine(graphic->frames.screen, 0, rect.y, SCREEN_WIDTH, rect.y);
  SDL_RenderDrawLine(graphic->frames.screen, 0, rect.y + rect.h,
		     SCREEN_WIDTH, rect.y + rect.h);
  SDL_RenderDrawLine(graphic->frames.screen, SCREEN_WIDTH / 2 , 0,
		     SCREEN_WIDTH / 2, rect.y);
  return (true);
}

bool			draw_arena_t(t_graphic *graphic)
{
  SDL_Texture		*texture;
  SDL_Rect		rect;

  rect.x = ((SCREEN_WIDTH / 2) / 2) - (graphic->frames.arena->w/ 2);
  rect.y = 0;
  rect.w = graphic->frames.arena->w;
  rect.h = graphic->frames.arena->h;
  texture = SDL_CreateTextureFromSurface(graphic->frames.screen,
					 graphic->frames.arena);
  if (SDL_RenderCopy(graphic->frames.screen, texture, NULL, &rect) == -1)
    display_sdl_error("Couldn't draw arena title ");
  return (true);
}

bool			draw_titles(t_graphic *graphic)
{
  draw_authors(graphic);
  draw_lemipc(graphic);
  draw_arena_t(graphic);
  draw_teams_t(graphic);
  return (true);
}