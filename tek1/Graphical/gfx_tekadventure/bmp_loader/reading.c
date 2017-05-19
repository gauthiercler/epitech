/*
** reading.c for reading in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:09:47 2016 Gauthier Cler
** Last update Wed Apr 20 21:10:36 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"bmp.h"

int		skip_x_bytes(int fd, int x)
{
  char		*buffer;

  if ((buffer = bunny_malloc(sizeof(char) * x)) == NULL)
    return (-1);
  return (read(fd, buffer, x));
}

int		read_header(t_bmp *bmp, int fd)
{
  int		status;

  status = 0;
  read(fd, bmp->signature, 2) != 2 ? status = 1 : 0;
  read(fd, &bmp->size, 4) != 4 ? status = 1 : 0;
  skip_x_bytes(fd, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->pixels_offset, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->header_size, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->width, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->height, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->planes_amount, 2) != 2 ? status = 1 : 0;
  read(fd, &bmp->bpp, 2) != 2 ? status = 1 : 0;
  read(fd, &bmp->compression, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->image_size, 4) != 4 ? status = 1 : 0;
  skip_x_bytes(fd, 8) != 8 ? status = 1 : 0;
  read(fd, &bmp->colors_amount, 4) != 4 ? status = 1 : 0;
  read(fd, &bmp->colors_imp, 4) != 4 ? status = 1 : 0;
  if (status)
    return (1);
  bmp->position = 54;
  return (0);
}

int   read_data(t_bmp *bmp, int fd)
{
  int i;
  int image_size;

  i = 0;
  image_size = bmp->width * bmp->height;
  format(1, "Image size => %d (%d x %d)\n",
	 image_size, bmp->width, bmp->height);
  if (skip_x_bytes(fd, bmp->pixels_offset - bmp->position)
      != bmp->pixels_offset - bmp->position)
    return (1);
  if ((bmp->pixels = bunny_malloc(sizeof(t_color) * image_size)) == NULL)
    return (1);
  while (i < image_size)
  {
    if (read_current_byte(bmp, fd))
      return (1);
    assign_current_byte(bmp, i);
    i += 1;
  }
  return (0);
}

int read_current_byte(t_bmp *bmp, int fd)
{
  if (bmp->bpp == 24)
  {
    if (read(fd, bmp->data_buffer, 3) != 3)
      return (1);
  }
  else if (bmp->bpp == 32)
  {
    if (read(fd, bmp->data_buffer, 4) != 4)
      return (1);
  }
  return (0);
}

void  assign_current_byte(t_bmp *bmp, int i)
{
  if (bmp->bpp == 32)
  {
    bmp->pixels[i].argb[3] = bmp->data_buffer[0];
    bmp->pixels[i].argb[2] = bmp->data_buffer[1];
    bmp->pixels[i].argb[1] = bmp->data_buffer[2];
    bmp->pixels[i].argb[0] = bmp->data_buffer[3];
  }
  else if (bmp->bpp == 24)
  {
    bmp->pixels[i].argb[2] = bmp->data_buffer[0];
    bmp->pixels[i].argb[1] = bmp->data_buffer[1];
    bmp->pixels[i].argb[0] = bmp->data_buffer[2];
    bmp->pixels[i].argb[3] = 255;
  }
}
