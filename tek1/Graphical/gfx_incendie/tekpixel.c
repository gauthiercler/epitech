/*
** tekpixel.c for tekpixel in /home/sylvain/Documents/zone_tests/Infographie/tp_pixel
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Tue Dec  1 20:07:55 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:08:14 2015 Sylvain Chaugny
*/

#include <lapin.h>
#include <stdio.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color color)
{
  t_color		*pixel;

  pixel = pix->pixels;
  pixel[pos->y * pix->clipable.buffer.width + pos->x].argb[0] = color.argb[0];
  pixel[pos->y * pix->clipable.buffer.width + pos->x].argb[1] = color.argb[1];
  pixel[pos->y * pix->clipable.buffer.width + pos->x].argb[2] = color.argb[2];
  pixel[pos->y * pix->clipable.buffer.width + pos->x].argb[3] = color.argb[3];
}
