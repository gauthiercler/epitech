/*
** load_cactus.c for load_cactus in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  8 09:36:38 2016 Gauthier Cler
** Last update Tue Jan 26 21:19:20 2016 Gauthier Cler
*/

#include		"tekpaint.h"

t_bunny_pixelarray	*load_cactus(char	*file)
{
  t_bunny_pixelarray	*pix;
  int			a;

  a = open(file, O_RDONLY);
  if (a == -1)
    return (NULL);
  pix = define_pix_cactus(a);
  if (pix == NULL)
    return (NULL);
  cactus_to_pix(pix, a, pix->clipable.buffer.width,
		pix->clipable.buffer.height);
  if (close(a) == -1)
    return (NULL);
  return (pix);
}

void			cactus_to_pix(t_bunny_pixelarray	*pix,
				      int			a,
				      unsigned int 	       	width,
				      unsigned int		height)
{
  int			*pixel;
  char			buf[6];
  unsigned int		i;

  pixel = (int *)pix->pixels;
  i = 0;
  while (i < width * height)
    {
      if (read(a, buf, 6) == -1)
	i += 1;
      else
	{
	  pixel[i] = cactus_to_decimal(buf);
	  i += 1;
	}
    }
}

int			cactus_to_decimal(char	*buf)
{
  int			decimal;

  decimal = (buf[0] - 48) * pow(40, 5);
  decimal += (buf[1] - 48) * pow(40, 4);
  decimal += (buf[2] - 48) * pow(40, 3);
  decimal += (buf[3] - 48) * pow(40, 2);
  decimal += (buf[4] - 48) * pow(40, 1);
  decimal += (buf[5] - 48) * pow(40, 0);
  return (decimal);
}

t_bunny_pixelarray	*define_pix_cactus(int	a)
{
  t_bunny_pixelarray	*res;
  unsigned char	       	buf[4];
  unsigned char		name[6];
  unsigned int		width;
  unsigned int		height;

  if (read(a, buf, 6) == -1)
    return (NULL);
  if (my_strcmp(name, "cactus") != 0)
    return (NULL);
  if (read(a, buf, 4) == -1)
    return (NULL);
  width = my_atoi(buf);
  if (width <= 0 || width > 1392)
    return (NULL);
  if (read(a, buf, 4) == -1)
    return (NULL);
  height = my_atoi(buf);
  if (height <= 0 || height > 850)
    return (NULL);
  res = bunny_new_pixelarray(width, height);
  return (res);
}
