/*
** tekray.c for tekray in /home/gogo/rendu/gfx_raytracer1/tcore
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 29 10:09:47 2016 Gauthier Cler
** Last update Sat Mar 12 23:04:35 2016 Gauthier Cler
*/

#include	"raytracer.h"

void		tekray(const t_bunny_position	*screen_info,
		       int			*x,
		       int			*y,
		       int			*z)
{
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *y = screen_info[1].y - (screen_info[0].y / 2);
  *z = 100;
}
