/*
** start_up.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/startup/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 13:26:48 2016 Buyumad Anas
** Last update Sat May 21 19:24:55 2016 Buyumad Anas
*/

#include	"amazing.h"

void		initialize_window(t_amazing *amazing)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    exit(printf("SDL could not initialize. SDL_Error : %s\n", SDL_GetError()));
  printf("Sdl Init started.\n");
  if ((amazing->Screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,
					  SCREEN_BPP, SDL_SWSURFACE)) == NULL)
    {
      printf("Window could not be created. SDL_Error : %s\n", SDL_GetError());
      exit(0);
    }
  SDL_WM_SetCaption("A-Maze-Ing", NULL);
  printf("Window created.\n");
}

void		init_display(t_amazing *amazing)
{
  amazing->Screen = NULL;
  amazing->Background = NULL;
  amazing->Credits = NULL;
  amazing->Generator = NULL;
  amazing->Solver = NULL;
  amazing->Type = NULL;
  amazing->Size = NULL;
  amazing->Map = NULL;
}

void		init_data(t_amazing *amazing)
{
  init_display(amazing);
  amazing->w_active = true;
  amazing->width = 10;
  amazing->height = 10;
  amazing->speed = 20000;
  amazing->gen_mode = 1;
  amazing->gen_type = -1;
  amazing->solver_type = -1;
  amazing->generated = false;
  amazing->filename = strdup("output.amazing");
  amazing->perfect.list = NULL;
  amazing->perfect.debug = 0;
  amazing->perfect.map.width = amazing->width;
  amazing->perfect.map.height = amazing->height;
  gen_map(&amazing->perfect.map);
}

void		start_up(void)
{
  t_amazing	amazing;

  init_data(&amazing);
  initialize_window(&amazing);
  load_ressources(&amazing);
  draw_amazing(&amazing);
  SDL_Flip(amazing.Screen);
  handle_events(&amazing);
  kill_data(&amazing);
}
