/*
** tektext.c for tektext in /home/gogo/rendu/gfx_tekgui/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:45:52 2016 Gauthier Cler
** Last update Sun Feb 28 21:24:14 2016 Gauthier Cler
*/

#include	"tekgui.h"

void			tektext(t_bunny_pixelarray *pix,
				const char *str,
				t_bunny_pixelarray *font_png)
{
  t_bunny_position	pos;
  t_bunny_position	font_pos;
  int			i;

  i = 0;
  pos.x = 0;
  pos.y = 0;
  font_pos.y = 0;
  while (str[i])
    {
      font_pos.x = str[i] * 5;
      put_char(pix, font_pos, font_png, pos);
      pos.x += 6;
      i += 1;
    }
}

void			put_char(t_bunny_pixelarray *pix,
				 t_bunny_position  font_pos,
				 t_bunny_pixelarray *font_png,
				 t_bunny_position pos)
{
  t_color		color[2];
  t_bunny_position	save[2];

  save[0].x = font_pos.x;
  save[0].y = font_pos.y;
  save[1].x = pos.x;
  save[1].y = pos.y;
  while (font_pos.y != save[0].y + 7)
    {
      while (font_pos.x != save[0].x + 5)
	{
	  color[0].full = get_color(font_png, &font_pos);
	  tekpixel(pix, &pos, color);
	  font_pos.x += 1;
	  pos.x += 1;
	}
      pos.y += 1;
      font_pos.y += 1;
      pos.x = save[1].x;
      font_pos.x = save[0].x;
    }
}

int		get_color(t_bunny_pixelarray *pix,
			  t_bunny_position *pos)
{
  int		i;
  int		*pixel;

  pixel = (int *)pix->pixels;
  i = pos->x + pos->y * pix->clipable.buffer.width;
  return (pixel[i]);
}
