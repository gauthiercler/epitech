/*
** hexa.c for hexa in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Jan  7 17:36:40 2016 Gauthier Cler
** Last update Tue Jan 26 21:39:59 2016 Gauthier Cler
*/

#include	"tekpaint.h"

int		pix_to_cactus(t_bunny_pixelarray	*pix,
			      char			*name)
{
  int		a;
  int		i;
  int		*pixel;
  char		base[6];
  char		size[4];
  char		*abs;

  if ((abs = my_strcat(name, ".cactus")) == NULL)
    return (ERROR);
  pixel = (int *)pix->pixels;
  if ((a = open(abs, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1)
    return (ERROR);
  cactus_header(pix, a, size);
  i = 0;
  while (i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      decimal_to_base(pixel[i++], base);
      write(a, base, 6);
    }
  if (close(a) == -1)
    return (ERROR);
  bunny_free(abs);
  my_putstr("Fichier Sauvegardé avec succès\n");
  return (SUCCESS);
}

void		cactus_header(t_bunny_pixelarray	*pix,
			      int			a,
			      char			*size)
{
  write(a, "cactus", 6);
  size_to_char(size, pix->clipable.buffer.width);
  write (a, size, 4);
  size_to_char(size, pix->clipable.buffer.height);
  write (a, size, 4);
}

void		size_to_char(char	*tab,
			     int	size)
{
  tab[0] = size / 1000 + '0';
  size %= 1000;
  tab[1] = size / 100 + '0';
  size %= 100;
  tab[2] = size / 10 + '0';
  size %= 10;
  tab[3] = size + '0';
}

void		decimal_to_base(int	decimal,
				char	*base)
{
  int		count;
  int		power;
  int		zero;

  power = 0;
  count = 1;
  while (count * 40 < decimal)
    {
      count *= 40;
      power += 1;
    }
  zero = 6 - power;
  while (zero)
    {
      zero--;
      base[zero] = '0';
    }
  while (count)
    {
      base[5 - power] = (decimal / count) + '0';
      power--;
      decimal %= count;
      count /= 40;
    }
}

int		my_strlen(char	*str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
