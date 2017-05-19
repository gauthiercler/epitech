/*
** init_data.c for data in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Fri May 20 15:35:28 2016 montag_v
** Last update Fri May 20 17:27:45 2016 montag_v
*/

#include	"raytracer.h"

int		init_data(t_vector_data *data, t_object *obj)
{
  if ((data->vector =
       bunny_malloc(sizeof(t_position) * data->count[V])) == NULL)
    return (format(2, "Error couldn't malloc\n"));
  if ((data->vectorn =
       bunny_malloc(sizeof(t_position) * data->count[VN])) == NULL)
    return (format(2, "Error couldn't malloc\n"));
  if ((data->vectort =
       bunny_malloc(sizeof(t_position) * data->count[VT])) == NULL)
    return (format(2, "Error couldn't malloc\n"));
  if ((obj->infos.triangle =
       bunny_malloc(sizeof(t_triangle) * data->count[F])) == NULL)
    return (format(2, "Error couldn't malloc\n"));
  return (SUCCESS);
}
