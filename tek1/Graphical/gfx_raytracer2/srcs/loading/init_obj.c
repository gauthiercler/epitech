/*
** init_obj.c for init_obj in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Thu May 12 14:16:42 2016 montag_v
** Last update Sun May 22 10:16:09 2016 montag_v
*/

#include	"raytracer.h"

void		init_obj(t_object *obj)
{
  obj->origin.x = 0;
  obj->origin.y = 0;
  obj->origin.z = 0;
  obj->infos.color.full = 0;
  obj->infos.texture = NULL;
  obj->infos.inclinaison.x = 0;
  obj->infos.inclinaison.y = 0;
  obj->infos.inclinaison.z = 0;
  obj->infos.normal.x = 0;
  obj->infos.normal.y = 0;
  obj->infos.normal.z = 0;
  obj->infos.height = 0;
  obj->infos.radius = 0;
  obj->infos.angle = 0;
  obj->infos.center_y = 0;
}
