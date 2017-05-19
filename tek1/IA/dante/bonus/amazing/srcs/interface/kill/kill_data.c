/*
** kill_data.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/kill/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 22:58:23 2016 Buyumad Anas
** Last update Sun May  1 16:06:27 2016 Buyumad Anas
*/

#include	"amazing.h"

void		kill_buttons(t_button buttons[NB_BUTTONS])
{
  int		i;

  i = 0;
  while (i < NB_BUTTONS)
    {
      if (buttons[i].button_normal != NULL)
	SDL_FreeSurface(buttons[i].button_normal);
      if (buttons[i].button_hover != NULL)
	SDL_FreeSurface(buttons[i].button_hover);
      if (buttons[i].button_selected != NULL)
	SDL_FreeSurface(buttons[i].button_selected);
      if (buttons[i].name != NULL)
	free(buttons[i].name);
      i += 1;
    }
}

void		kill_display(t_amazing *amazing)
{
  if (amazing->Screen != NULL)
    SDL_FreeSurface(amazing->Screen);
  if (amazing->Background != NULL)
    SDL_FreeSurface(amazing->Background);
  if (amazing->Credits != NULL)
    SDL_FreeSurface(amazing->Credits);
  if (amazing->Generator != NULL)
    SDL_FreeSurface(amazing->Generator);
  if (amazing->Solver != NULL)
    SDL_FreeSurface(amazing->Solver);
  if (amazing->Type != NULL)
    SDL_FreeSurface(amazing->Type);
  if (amazing->Size != NULL)
    SDL_FreeSurface(amazing->Size);
  if (amazing->Map != NULL)
    SDL_FreeSurface(amazing->Map);
}

void		kill_data(t_amazing *amazing)
{
  kill_buttons(amazing->buttons);
  kill_display(amazing);
  SDL_FreeSurface(amazing->Screen);
  SDL_Quit();
}
