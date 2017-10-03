/*
** event.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/bonus/graphic_code/event.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Apr 02 17:55:37 2017 Gauthier Cler
** Last update Sun Apr 02 17:55:38 2017 Gauthier Cler
*/

#include 		"lem_ipc.h"

void			wait_end_event()
{
  SDL_Event		event;
  bool			waiting;

  waiting = true;
  while (waiting)
  {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      break ;
    if (event.type == SDL_KEYDOWN)
      if (event.key.keysym.sym == SDLK_ESCAPE)
	break ;
  }
}