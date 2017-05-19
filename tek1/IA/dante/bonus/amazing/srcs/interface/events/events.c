/*
** events.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 17:56:37 2016 Buyumad Anas
** Last update Sun May 22 23:12:22 2016 Gauthier Cler
*/

#include	"amazing.h"

void		handle_keys(t_amazing *amazing, SDL_Event *events)
{
  if (events->type == SDL_KEYDOWN)
    {
      if (events->key.keysym.sym == SDLK_UP)
	{
	  amazing->speed += 1000;
	  format(1, "Speed : %d\n", amazing->speed);
	}
      else if (events->key.keysym.sym == SDLK_DOWN && amazing->speed >= 1000)
	{
	  amazing->speed -= 1000;
	  format(1, "Speed : %d\n", amazing->speed);
	}
      if (events->key.keysym.sym == SDLK_ESCAPE)
	amazing->w_active = false;
    }
}

void		handle_clicks(t_amazing *amazing, SDL_Event *events)
{
  t_position	mouse_pos;
  int		index_touched;

  mouse_pos.x = events->motion.x;
  mouse_pos.y = events->motion.y;
  if (events->type == SDL_MOUSEMOTION)
    {
      index_touched = check_hitboxes(amazing, &mouse_pos);
      set_buttons_state(amazing, index_touched, 0);
    }
  if (events->type == SDL_MOUSEBUTTONDOWN)
    {
      index_touched = check_hitboxes(amazing, &mouse_pos);
      if (index_touched >= 0)
	printf("Button clicked => %s\n", amazing->buttons[index_touched].name);
      set_buttons_state(amazing, index_touched, 1);
      click_actions(amazing, index_touched);
    }
}

void		handle_events(t_amazing *amazing)
{
  while (amazing->w_active)
    {
      if (SDL_PollEvent(&amazing->events))
	{
	  handle_keys(amazing, &amazing->events);
	  handle_clicks(amazing, &amazing->events);
	  (amazing->events.type == SDL_QUIT) ? amazing->w_active = false : 0;
	  draw_buttons(amazing, amazing->buttons);
	  SDL_Flip(amazing->Screen);
	}
    }
}
