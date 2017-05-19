/*
** save.c for save in /home/gogo/rendu/gfx_raytracer2/srcs/saving/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat May 14 20:54:54 2016 Gauthier Cler
** Last update Fri May 20 14:27:25 2016 Gauthier Cler
*/

#include 	<unistd.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>
#include	"raytracer.h"

static void	fill_struct(t_bmp *bmp, int padding)
{
  bmp->type = 0x4D42;
  bmp->size = 54 + SCREEN_HEIGHT + padding;
  bmp->reserved = 0;
  bmp->offset = 54;
  bmp->header_size = 40;
  bmp->width = SCREEN_WIDTH;
  bmp->height = SCREEN_HEIGHT;
  bmp->planes = 1;
  bmp->bits = 24;
  bmp->compression = 0;
  bmp->imagesize = padding * SCREEN_HEIGHT;
  bmp->xresolution = 0;
  bmp->yresolution = 0;
  bmp->ncolours = 0;
  bmp->importantcolours = 0;
}

static void	write_pixels(int fd, t_bunny_pixelarray *pix)
{
  unsigned int	*pixel;
  t_color	color;
  int		x;
  int		y;

  y = 0;
  pixel = (unsigned int *)pix->pixels;
  while (y < SCREEN_HEIGHT)
    {
      x = 0;
      while (x < SCREEN_WIDTH)
	{
	  color.full = pixel[x + (SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH];
          write(fd, &color.argb[2], 1);
          write(fd, &color.argb[1], 1);
          write(fd, &color.argb[0], 1);
	  x += 1;
	}
      y += 1;
    }
}

static void	write_struct(int fd, t_bmp *bmp)
{
  write(fd, &bmp->type, 2);
  write(fd, &bmp->size, 4);
  write(fd, &bmp->reserved, 4);
  write(fd, &bmp->offset, 4);
  write(fd, &bmp->header_size, 4);
  write(fd, &bmp->width, 4);
  write(fd, &bmp->height, 4);
  write(fd, &bmp->planes, 2);
  write(fd, &bmp->bits, 2);
  write(fd, &bmp->compression, 4);
  write(fd, &bmp->imagesize, 4);
  write(fd, &bmp->xresolution, 4);
  write(fd, &bmp->yresolution, 4);
  write(fd, &bmp->ncolours, 4);
  write(fd, &bmp->importantcolours, 4);
}

int		save_to_file(t_bunny_pixelarray *pix)
{
  int		fd;
  t_bmp		bmp;
  int		padding;
  char		*filename;

  format(1, "Enter name of the file : ");
  if ((filename = get_next_line(0)) == NULL)
    return (format(2, "Malloc error\n"));
  format(1, "Saving...\n");
  if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
                           | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
                           | S_IWOTH)) == -1)
    return (format(2, "Error while opening %s\n", filename));
  padding = (3 * (SCREEN_WIDTH + 1) / 4) * 4;
  fill_struct(&bmp, padding);
  write_struct(fd, &bmp);
  write_pixels(fd, pix);
  close(fd);
  bunny_free(filename);
  format(1, "Rendering saved in file %s\n", filename);
  return (SUCCESS);
}
