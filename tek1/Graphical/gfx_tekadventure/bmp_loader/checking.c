/*
** checking.c for checking in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:06:16 2016 Gauthier Cler
** Last update Wed Apr 20 21:06:28 2016 Gauthier Cler
*/

#include	"bmp.h"

int		check_header(t_bmp *bmp)
{
  int		status;

  status = 0;
  bmp->signature[0] != 'B' || bmp->signature[1] != 'M' ? status = 1 : 0;
  bmp->pixels_offset < 54 ? status = 1 : 0;
  bmp->width > 2000 ? status = 1 : 0;
  bmp->height > 1100 ? status = 1 : 0;
  bmp->planes_amount != 1 ? status = 1 : 0;
  bmp->bpp != 24 && bmp->bpp != 32 ? status = 1 : 0;
  return (status);
}
