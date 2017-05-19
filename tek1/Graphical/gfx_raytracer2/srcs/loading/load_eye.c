/*
** load_eye.c for load_eye in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May 11 09:35:08 2016 montag_v
** Last update Sun May 22 18:11:19 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		load_eye(t_bunny_ini *ini, t_eye *eye)
{
  load_coord(ini, "eye", "coord", &eye->origin);
  eye->blur_level = my_atoi(bunny_ini_get_field(ini, "eye", "blur", 0));
  load_coord(ini, "eye", "inclinaison", &eye->inclinaison);
  eye->inclinaison.x *= -1.0;
  eye->inclinaison.y *= -1.0;
  eye->inclinaison.z *= -1.0;
  rotate_inverse(&eye->origin, &eye->inclinaison);
}
