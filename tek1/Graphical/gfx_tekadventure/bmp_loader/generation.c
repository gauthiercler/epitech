/*
** generation.c for loading in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:07:40 2016 Gauthier Cler
** Last update Wed Apr 20 21:07:52 2016 Gauthier Cler
*/

#include	"bmp.h"

t_bmp		*generate_bmp()
{
  t_bmp		*bmp;

  if ((bmp = bunny_malloc(sizeof(t_bmp))) == NULL)
    return (NULL);
  bmp->signature[0] = '\0';
  bmp->signature[1] = '\0';
  bmp->size = 0;
  bmp->pixels_offset = 0;
  bmp->width = 0;
  bmp->height = 0;
  bmp->bpp = 0;
  bmp->compression = 0;
  bmp->image_size = 0;
  bmp->colors_amount = 0;
  bmp->colors_imp = 0;
  bmp->pixels = NULL;
  bmp->position = 0;
  bmp->data_buffer[0] = '\0';
  bmp->data_buffer[1] = '\0';
  bmp->data_buffer[2] = '\0';
  bmp->data_buffer[3] = '\0';
  return (bmp);
}
