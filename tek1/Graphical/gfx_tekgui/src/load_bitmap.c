/*
** load_bitmap.c for load_bitmap in /tmp/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Feb  9 23:55:52 2016 Gauthier Cler
** Last update Thu Feb 25 00:34:13 2016 Gauthier Cler
*/

#include		"tekgui.h"

t_bunny_pixelarray	*define_pix_size(int	a)
{
  unsigned char		buf[100];
  t_bunny_pixelarray	*res;
  unsigned int		width;
  unsigned int		height;
  unsigned int		offset;

  read(a, buf, 18);
  offset = *(int *) & buf[14];
  read(a, buf, offset - 4);
  width = *(int *) & buf[0];
  height = *(int *) & buf[4];
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
  t_color		*color;

  color = bunny_malloc(sizeof(t_color) * size);
  pixel = (int *)pix->pixels;
  i = 0;
  while (i < size)
    {
      read(a, buf, 4);
      color[i].argb[0] = buf[3];
      color[i].argb[1] = buf[2];
      color[i].argb[2] = buf[1];
      color[i].argb[3] = buf[0];
      i += 1;
    }
  fill_bitmap(pix, color, pixel);
  bunny_free(color);
}

void			fill_bitmap(t_bunny_pixelarray	*pix,
				    t_color		*color,
				    int			*pixel)
{
  int			k;
  int			i;
  int			j;
  int			b;

  k = 1;
  b = 0;
  while (k <=  pix->clipable.buffer.height)
    {
      i = (pix->clipable.buffer.height - k) * pix->clipable.buffer.width;
      j = 0;
      while (j < pix->clipable.buffer.width)
	{
	  if (j >= 0 && j < pix->clipable.clip_height
	   * pix->clipable.clip_width)
	    pixel[b] = color[i].full;
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
