/*
** load_ressources.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 21:11:02 2016 Buyumad Anas
** Last update Sat May 21 19:36:57 2016 Buyumad Anas
*/

#include	"amazing.h"

void		load_ressources(t_amazing *amazing)
{
  load_buttons(amazing->buttons);
  if ((amazing->Background = load_image("./ressources/Background.png")) == NULL)
    exit(printf("Couldn't Load Background.\n"));
  if ((amazing->Generator = load_image("./ressources/Generator.png")) == NULL)
    exit(printf("Couldn't Load Generator.\n"));
  if ((amazing->Credits = load_image("./ressources/Credits.png")) == NULL)
    exit(printf("Couldn't load Credits.\n"));
  if ((amazing->Solver = load_image("./ressources/Solver.png")) == NULL)
    exit(printf("Couldn't Load Solver.\n"));
  if ((amazing->Type = load_image("./ressources/Type.png")) == NULL)
    exit(printf("Couldn't load Type.\n"));
  if ((amazing->Size = load_image("./ressources/Size.png")) == NULL)
    exit(printf("Couldn't load Size.\n"));
  if ((amazing->WxH = load_image("./ressources/WxH.png")) == NULL)
    exit(printf("Couldn't load WxH.\n"));
  if ((amazing->Map =
       SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCALPHA,
			    401, 401, 32, 48, 144, 199, 200)) == NULL)
    exit(printf("Couldn't create Map Surface.\n"));
  SDL_FillRect(amazing->Map, NULL,
	       SDL_MapRGBA(amazing->Map->format, 48, 144, 199, 200));
}
