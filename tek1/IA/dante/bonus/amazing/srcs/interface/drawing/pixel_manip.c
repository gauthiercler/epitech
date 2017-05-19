/*
** pixel_manip.c for amazing in /home/skyrise/Work/Repositories/Epitech/IA/dante/bonus/amazing/srcs/interface/drawing/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 29 23:28:28 2016 Buyumad Anas
** Last update Sat May 21 19:41:02 2016 Buyumad Anas
*/

#include	"amazing.h"

void		set_pixel(SDL_Surface *image, t_position *pos, SDL_Color *color)
{
  Uint32	*pixels;

  pixels = (Uint32 *)image->pixels;
  pixels[pos->x + pos->y * image->clip_rect.w] =
      SDL_MapRGBA(image->format, color->r, color->g, color->b, 128);
}

static void	set_color_next(SDL_Color *color, int macro)
{
  if (macro == BLUE)
    {
      color->r = 48;
      color->g = 144;
      color->b = 199;
    }
  else if (macro == RED)
    {
      color->r = 229;
      color->g = 84;
      color->b = 81;
    }
  else if (macro == YELLOW)
    {
      color->r = 255;
      color->g = 243;
      color->b = 128;
    }
  else if (macro == GREEN)
    {
      color->r = 74;
      color->g = 160;
      color->b = 44;
    }
}

void		set_color(SDL_Color *color, int macro)
{
  if (macro == WHITE)
    {
      color->r = 0xFF;
      color->g = 0xFF;
      color->b = 0xFF;
    }
  else if (macro == BLACK)
    {
      color->r = 0x00;
      color->g = 0x00;
      color->b = 0x00;
    }
  else if (macro == GREY)
    {
      color->r = 109;
      color->g = 123;
      color->b = 141;
    }
  set_color_next(color, macro);
}
