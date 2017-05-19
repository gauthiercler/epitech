/*
** loading.c for bmploader in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:04:45 2016 Gauthier Cler
** Last update Wed Apr 20 21:09:10 2016 Gauthier Cler
*/

#include		<fcntl.h>
#include		<unistd.h>
#include		"bmp.h"

t_bunny_pixelarray	*load_error(t_bmp *bmp, int fd)
{
  format(1, "An Error occured while loading the file.\n");
  if (fd == -1)
    close(fd);
  if (bmp != NULL)
    delete_bmp(bmp);
  return (NULL);
}

void			print_info(t_bmp *bmp)
{
  format(1, "Signature => %s\n", bmp->signature);
  format(1, "BMP Size => %d\n", bmp->size);
  format(1, "Pixels Offset => %d\n", bmp->pixels_offset);
  format(1, "Header size => %d\n", bmp->header_size);
  format(1, "Width => %d\n", bmp->width);
  format(1, "Height => %d\n", bmp->height);
  format(1, "Planes => %d\n", bmp->planes_amount);
  format(1, "Bits per Pixel => %d\n", bmp->bpp);
  format(1, "Compression => %d\n", bmp->compression);
  format(1, "Image Size => %d\n", bmp->image_size);
  format(1, "Colors amount => %d\n", bmp->colors_amount);
  format(1, "Important Colors => %d\n", bmp->colors_imp);
}

t_bunny_pixelarray	*load_bmp(char *path)
{
  t_bmp			*bmp;
  int			fd;
  t_bunny_pixelarray	*pix;

  bmp = generate_bmp();
  fd = open(path, O_RDONLY);
  if (bmp == NULL || fd == -1)
    return (load_error(bmp, fd));
  format(1, "Fd => %d\n", fd);
  if (read_header(bmp, fd))
    return (load_error(bmp, fd));
  format(1, "Header read.\n");
  if (check_header(bmp))
    return (load_error(bmp, fd));
  format(1, "Header correct.\n");
  if (read_data(bmp, fd))
    return (load_error(bmp, fd));
  format(1, "Data read.\n");
  close(fd);
  print_info(bmp);
  pix = transposition(bmp);
  delete_bmp(bmp);
  return (pix);
}
