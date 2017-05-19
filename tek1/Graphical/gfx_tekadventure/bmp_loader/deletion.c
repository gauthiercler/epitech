/*
** deletion.c for deletetion in /home/gogo/rendu/gfx_tekadventure/bmp_loader
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 20 21:07:16 2016 Gauthier Cler
** Last update Wed Apr 20 21:07:23 2016 Gauthier Cler
*/

#include	"bmp.h"

void		delete_bmp(t_bmp *bmp)
{
  if (bmp->pixels != NULL)
    bunny_free(bmp->pixels);
  bunny_free(bmp);
}
