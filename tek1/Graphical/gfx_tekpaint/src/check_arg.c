/*
** check_arg.c for check_arg in /home/gauthier/rendu/gfx_tekpaint/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon Jan 25 16:36:49 2016 Gauthier Cler
** Last update Tue Jan 26 21:17:20 2016 Gauthier Cler
*/

#include		"tekpaint.h"

int			check_arg(t_prog	*prog,
				  char		*str)
{
  if ((prog->pix = load_cactus(str)) != NULL)
    return (SUCCESS);
  else
    my_putstr("Erreur lors du chargement du fichier cactus.\n");
  if ((prog->pix = load_bitmap(str)) != NULL)
    return (SUCCESS);
  else
    my_putstr("Erreur lors du chargement de l'image.\n");
  return (ERROR);
}

t_bunny_pixelarray	*load_white()
{
  t_bunny_pixelarray	*pix;
  t_color      		color[2];

  color[0].full = WHITE;
  pix = bunny_new_pixelarray(1392, 850);
  full_pix(pix, color);
  return (pix);
}
