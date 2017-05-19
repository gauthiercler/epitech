/*
** getcolor.c for getcolor in /home/montag_v/rendu/nocss_2020/src_test
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Wed Mar 30 09:27:24 2016 valentin montagne
** Last update Wed Apr 13 14:54:35 2016 valentin montagne
*/

#include		<lapin.h>

unsigned int		getcolor(t_bunny_pixelarray	*pix,
				 t_position	*pos)
{
  int			*pixel;

  pixel = pix->pixels;
  return (pixel[pos->x + pos->y * pix->clipable.buffer.width]);
}
