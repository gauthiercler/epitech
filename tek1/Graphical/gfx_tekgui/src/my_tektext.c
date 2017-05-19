/*
** my_tektext.c for my_tektext in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Thu Feb 25 13:18:24 2016 Gauthier Cler
** Last update Tue Mar  1 22:10:57 2016 Gauthier Cler
*/

#include	"tekgui.h"

void			blit_on_pixel(t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      t_color *color)
{
  if (color[0].argb[3] > 0)
    {
      color[0].full = pos[2].y;
      color[0].argb[3] = 1;
      tekpixel(pix, pos, color);
    }
}

void                    my_put_char(t_bunny_pixelarray *pix,
				    t_bunny_position  font_pos,
				    t_bunny_pixelarray *font_png,
				    t_bunny_position *pos)
{
  t_color               color[2];
  t_bunny_position      save[2];

  save[0].x = font_pos.x;
  save[0].y = font_pos.y;
  save[1].x = pos[0].x;
  save[1].y = pos[0].y;
  while (font_pos.y != save[0].y + 7)
    {
      while (font_pos.x != save[0].x + 5)
	{
	  color[0].full = get_color(font_png, &font_pos);
	  blit_on_pixel(pix, pos, color);
	  font_pos.x += 1;
	  pos[0].x += 1;
	}
      pos[0].y += 1;
      font_pos.y += 1;
      pos[0].x = save[1].x;
      font_pos.x = save[0].x;
    }
   pos[0].y -= 7;
}

void			call_put_char(t_bunny_pixelarray *pix,
				      t_bunny_pixelarray *font_png,
				      t_bunny_position *pos,
				      char c)
{
  t_bunny_position	font_pos;

  font_pos.x = c * 5;
  my_put_char(pix, font_pos, font_png, pos);
  pos[0].x += 6;
}
void                    my_tektext(t_bunny_pixelarray *pix,
				   const char *str,
				   t_bunny_pixelarray *font_png,
				   t_bunny_position *pos)
{
  int                   i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 13)
	{
	  pos[0].y += 8;
	  pos[0].x = pos[2].x;
	}
      else if (pos[0].x + 5 >= pos[1].x)
	{
	  pos[0].y += 8;
	  pos[0].x = pos[2].x;
	  call_put_char(pix, font_png, pos, str[i]);
	}
      else if (str[i] == '\t')
	pos[0].x += 28;
      else
	call_put_char(pix, font_png, pos, str[i]);
      i += 1;
    }
}
