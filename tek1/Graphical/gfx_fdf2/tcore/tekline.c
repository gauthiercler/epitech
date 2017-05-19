/*
** tekline.c for fdf2 in /home/gauthier/rendu/gfx_fdf2
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Dec 14 10:13:52 2015 Gauthier Cler
** Last update Wed Dec 16 11:12:06 2015 Gauthier Cler
*/

#include	"fdf.h"

void	loop_x(t_bunny_pixelarray *pix, t_bunny_position *pos,
	       t_color *color, int *info)
{
  int	i;
  int	cor;

  protection(pix, pos, color);
  i = 0;
  cor = 0;
  while (i < info[0])
    {
      pos[0].x += info[2];
      cor += info[1];
      if (cor > info[0])
	{
	  cor -= info[0];
	  pos[0].y += info[3];
	}
      i++;
      protection(pix, pos, color);
    }
}

void	loop_y(t_bunny_pixelarray *pix, t_bunny_position *pos,
	       t_color *color, int *info)
{
  int	i;
  int	cor;

  protection(pix, pos, color);
  i = 0;
  cor = 0;
  while (i < info[1])
    {
      pos[0].y += info[3];
      cor += info[0];
      if (cor > info[0])
	{
	  cor -= info[1];
	  pos[0].x += info[2];
	}
      i++;
      protection(pix, pos, color);
    }
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  int			info[4];
  t_bunny_position	res[2];

  res[0].x = pos[0].x;
  res[0].y = pos[0].y;
  res[1].x = pos[1].x;
  res[1].y = pos[1].y;
  info[0] = pos[1].x - pos[0].x;
  info[1] = pos[1].y - pos[0].y;
  if (info[0] < 0)
    info[0] = -(info[0]);
  if (info[1] < 0)
    info[1] = -(info[1]);
  info[2] = 1;
  info[3] = 1;
  if (pos[0].x > pos[1].x)
    info[2] = -1;
  if (pos[0].y > pos[1].y)
    info[3] = -1;
  if (info[0] > info[1])
    loop_x(pix, res, color, info);
  else
    loop_y(pix, res, color, info);
}

void	protection(t_bunny_pixelarray *pix,
		   t_bunny_position *pos,
		   t_color *color)
{
  if ((pos[0].x < pix->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y < pix->clipable.clip_height && pos[0].y >= 0))
    tekpixel(pix, pos, color);
}
