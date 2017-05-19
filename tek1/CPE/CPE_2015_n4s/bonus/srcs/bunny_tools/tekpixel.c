/*
** tekpixel.c for tekpixel in /home/montag_v/rendu/gfx_tekgui/libtekgui
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Mon Feb 22 17:41:23 2016 montag_v
** Last update Thu Feb 25 09:36:25 2016 valentin montagne
*/

#include	<lapin.h>

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 unsigned int		color)
{
  int		*pixel;
  int		i;

  pixel = (int *)pix->pixels;
  i = pos[0].x + pos[0].y * pix->clipable.buffer.width;
  if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y < pix->clipable.clip_height &&  pos[0].y >= 0))
    pixel[i] = color;
}
