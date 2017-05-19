/*
** draw.c for draw in /home/sylvain/Documents/zone_tests/Infographie/rush_incendie/gfx_incendie/version1/coucou
**
** Made by Sylvain Chaugny
** Login   <sylvain@epitech.net>
**
** Started on  Sun Dec  6 00:14:30 2015 Sylvain Chaugny
** Last update Sun Dec  6 19:07:42 2015 Sylvain Chaugny
*/

#include		<lapin.h>
#include		"include/my_flames.h"

void			draw_line(t_bunny_pixelarray	*pix,
				  t_datas		*datas,
				  int			arg)
{
  int			len;
  float			deg;

  len = (float)datas->pos[0].y - (float)datas->pos[1].y;
  deg = 255 / len;
  while (datas->pos[0].y > datas->pos[1].y)
    {
      tekpixel(pix, &datas->pos[0], datas->col[0]);
      datas->col[0].argb[arg] -= deg;
      datas->pos[0].y--;
    }
}

void			init_datas(t_datas *datas, int i, int height, int plus)
{
  datas->pos[0].x = i;
  datas->pos[1].x = i;
  datas->pos[0].y = height;
  datas->pos[1].y = height - rand() % 10 - 15 - datas->k - plus;
  datas->col[0].argb[0] = 255;
  datas->col[0].argb[1] = 255;
  datas->col[0].argb[2] = 255;
  datas->col[0].argb[3] = 255;
  datas->col[1].argb[0] = 255;
  datas->col[1].argb[1] = 255;
  datas->col[1].argb[2] = 0;
  datas->col[1].argb[3] = 255;
}

void			go_to_next_part(t_datas *datas, int i, int height, int plus)
{
  datas->pos[0] = datas->pos[1];
  datas->pos[1].x = i;
  datas->pos[1].y = height - (height - datas->pos[0].y) - rand() % 20 - 10 - \
    plus - datas->k;
  datas->col[0] = datas->col[1];
}

int			check_k()
{
  int			k;

  if (rand() % 2 == 1)
    k = 5 - rand() % 10;
  else
    k = 0;
  return (k);
}

int			fire(t_bunny_pixelarray *pix, int height, int plus)
{
  t_datas		datas;
  int			i;
  int			j;

  i = 0;
  while (i < pix->clipable.buffer.width)
    {
      datas.k = check_k();
      j = 0;
      while (j < 30)
	{
	  init_datas(&datas, i, height, plus);
	  draw_line(pix, &datas, 2);
	  go_to_next_part(&datas, i, height, plus);
	  datas.col[1].argb[1] = 0;
	  draw_line(pix, &datas, 1);
	  go_to_next_part(&datas, i, height, plus);
	  datas.col[1].argb[0] = 0;
	  draw_line(pix, &datas, 0);
	  i++;
	  j++;
	}
    }
  return (0);
}
