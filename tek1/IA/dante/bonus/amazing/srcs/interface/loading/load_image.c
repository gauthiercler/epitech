/*
** load_image.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 16:06:56 2016 Buyumad Anas
** Last update Fri Apr 29 17:05:18 2016 Buyumad Anas
*/

#include	"amazing.h"

SDL_Surface	*load_image(char *filename)
{
  SDL_Surface	*Image;
  SDL_Surface	*OptimizedImage;

  if ((Image = IMG_Load(filename)) == NULL)
    return (NULL);
  OptimizedImage = SDL_DisplayFormatAlpha(Image);
  SDL_FreeSurface(Image);
  return (OptimizedImage);
}
