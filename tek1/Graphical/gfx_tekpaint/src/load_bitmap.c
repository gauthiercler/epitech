/*
** load_bitmap.c for load_bitmap in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan  5 16:34:01 2016 Gauthier Cler
** Last update Tue Jan 26 21:25:11 2016 Gauthier Cler
*/

#include		"tekpaint.h"

t_bunny_pixelarray	*define_pix_size(int	a)
{
  unsigned char		buf[54];
  t_bunny_pixelarray	*res;
  unsigned int		width;
  unsigned int		height;
  unsigned int		compression;

  if (read(a, buf, 54) == -1)
    return (NULL);
  width = *(int *) & buf[18];
  height = *(int *) & buf[22];
  if (height > 850 || width > 1392)
    {
      my_putstr("Taille de l'image invalide\n");
      return (NULL);
    }
  compression = *(int *) & buf[28];
  if (compression != 24)
    {
      my_putstr("Format de compression invalide.\n");
      return (NULL);
    }
  res = bunny_new_pixelarray(width, height);
  return (res);
}

void			bitmap_to_pix(t_bunny_pixelarray	*pix,
				      int			a,
				      int			size)
{
  unsigned char		buf[3];
  int			i;
  int			*pixel;
  t_color		color[2];
  int			pos;

  pixel = (int *)pix->pixels;
  i = 0;
  while (i < size)
    {
      if (!(read(a, buf, 3) == -1))
	{
	  color[0].argb[0] = buf[2];
	  color[0].argb[1] = buf[1];
	  color[0].argb[2] = buf[0];
	}
      color[0].argb[3] = 0;
      pos = pix->clipable.buffer.width *
	(pix->clipable.buffer.height - i / pix->clipable.buffer.width - 1)
	+ i % pix->clipable.buffer.width;
      pixel[pos] = color[0].full;
      i += 1;
    }
}

void			fill_bitmap(t_bunny_pixelarray	*pix,
				    unsigned int	*stock,
				    int			*pixel)
{
  int			k;
  int			i;
  int			j;
  int			b;

  k = 1;
  b = 0;
  while (k <= pix->clipable.buffer.height)
    {
      i = (pix->clipable.buffer.height - k) * pix->clipable.buffer.width;
      j = 0;
      while (j < pix->clipable.buffer.width)
	{
	  if (j >= 0 && j < pix->clipable.clip_height
	   * pix->clipable.clip_width)
	    pixel[b] = stock[i];
	  i++;
	  j++;
	  b++;
	}
      k++;
    }
}

t_bunny_pixelarray	*load_bitmap(char	*file)
{
  t_bunny_pixelarray	*pix;
  int			a;

  a = open(file, O_RDONLY);
  if (a == -1)
    return (NULL);
  pix = define_pix_size(a);
  if (pix == NULL)
    return (NULL);
  bitmap_to_pix(pix, a, pix->clipable.buffer.width *
		pix->clipable.buffer.height);
  if (close(a) == -1)
    return (NULL);
  return (pix);
}
