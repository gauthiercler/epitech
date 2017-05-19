/*
** blit.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/manipulation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 16:31:19 2016 Buyumad Anas
** Last update Fri Apr 29 23:12:35 2016 Buyumad Anas
*/

#include	"amazing.h"

void		blit(SDL_Surface *dest, SDL_Surface *src, t_position *pos)
{
  SDL_Rect	offset;

  if (pos != NULL)
    {
      offset.x = pos->x;
      offset.y = pos->y;
    }
  else
    {
      offset.x = 0;
      offset.y = 0;
    }
  SDL_BlitSurface(src, NULL, dest, &offset);
}
