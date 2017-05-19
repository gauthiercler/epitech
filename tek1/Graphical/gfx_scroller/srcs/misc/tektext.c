/*
** tektext.c for tektext in /home/gogo/rendu/gfx_tekgui/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb  1 16:45:52 2016 Gauthier Cler
** Last update Sun Mar 20 14:29:01 2016 Anas Buyumad
*/

#include		"megalovania.h"

void			tektext(t_bunny_pixelarray *pix,
				const char *str,
				t_bunny_pixelarray *font_png,
				t_bunny_position *pos)
{
  t_bunny_position	font_pos;
  int			i;

  i = 0;
  font_pos.y = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	pos[0].x += 45;
      else
	{
	  font_pos.x = (str[i] - 65) * 32;
	  put_char(pix, font_pos, font_png, pos[0]);
	  pos[0].x += 35;
	}
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
  while (font_pos.y != save[0].y + 25)
    {
      while (font_pos.x != save[0].x + 31)
	{
	  color[0].full = get_color(font_png, &font_pos);
	  pixel(pix, &pos, color);
	  font_pos.x += 1;
	  pos.x += 1;
	}
      pos.y += 1;
      font_pos.y += 1;
      pos.x = save[1].x;
      font_pos.x = save[0].x;
    }
}

int			get_color(t_bunny_pixelarray *pix,
				  t_bunny_position *pos)
{
  int			i;
  int			*pixel;

  pixel = (int *)pix->pixels;
  i = pos->x + pos->y * pix->clipable.buffer.width;
  return (pixel[i]);
}
