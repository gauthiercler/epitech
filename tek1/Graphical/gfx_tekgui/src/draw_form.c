/*
** draw_form.c for draw_form in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 17 17:58:09 2016 Gauthier Cler
** Last update Thu Feb 25 08:52:19 2016 Gauthier Cler
*/

#include	"tekgui.h"

void			draw_form(t_bunny_pixelarray *pix,
				  t_tekgui elem)
{
  t_bunny_position	pos;
  t_color		color;

  color.full = elem.color.full;
  color.argb[3] = 1;
  pos.y = elem.pos.y;
  while (pos.y != elem.pos.y + elem.size.y)
    {
      pos.x = elem.pos.x;
      while (pos.x != elem.pos.x + elem.size.x)
	{
	  tekpixel(pix, &pos, &color);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  draw_border(pix, elem);
}

void			draw_border(t_bunny_pixelarray *pix,
				    t_tekgui elem)
{
  t_bunny_position	pos[2];
  t_color		color;

  color.full = BLACK;
  pos[0].x = elem.pos.x;
  pos[0].y = elem.pos.y;
  pos[1].x = pos[0].x + elem.size.x;
  pos[1].y = pos[0].y;
  tekline(pix, pos, &color);
  pos[0] = pos[1];
  pos[1].x = pos[0].x;
  pos[1].y = pos[1].y + elem.size.y;
  tekline(pix, pos, &color);
  pos[0] = pos[1];
  pos[1].x = elem.pos.x;
  pos[1].y = pos[0].y;
  tekline(pix, pos, &color);
  pos[0] = pos[1];
  pos[1].x = elem.pos.x;
  pos[1].y = elem.pos.y;
  tekline(pix, pos, &color);
}
