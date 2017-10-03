/*
** graphic_display.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/bonus/graphic_display.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 30 21:53:55 2017 Anas Buyumad
** Last update Thu Mar 30 21:53:55 2017 Anas Buyumad
*/

#include		"lem_ipc.h"

void			startup_graphic(t_ipc *data)
{
  init_graphic(&data->graphic);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    display_sdl_error("SDL Couldn't Initialize ");
  if ((data->graphic.window =
	 SDL_CreateWindow("LemIPC - arena",
			  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN))
      == NULL)
    display_sdl_error("window couldn't be created ");
  data->graphic.frames.screen =
    SDL_CreateRenderer(data->graphic.window, -1, 0);
  init_palette(data->graphic.palette);
  init_palette_t(data->graphic.t_palette);
  load_ressources(&data->graphic);
  SDL_SetRenderDrawColor(data->graphic.frames.screen, 0x0, 0x0, 0x0, 255);
  SDL_RenderFillRect(data->graphic.frames.screen, NULL);
  draw_titles(&data->graphic);
  draw_arena(data);
  SDL_RenderPresent(data->graphic.frames.screen);
}

void			close_graphic(t_ipc *data)
{
  SDL_DestroyWindow(data->graphic.window);
  SDL_Quit();
}