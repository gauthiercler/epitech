/*
** compute_output.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 20:06:33 2016 Buyumad Anas
** Last update Sun May 29 21:25:56 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

int		compute_output(t_data *data)
{
  float		distance;
  int		main_spread;

  main_spread = get_main_spread(data->spread);
  distance = data->spread[main_spread];
  compute_distance(distance, &data->car_speed, data->previous_speed);
  if (data->car_speed < 1.0)
    {
      compute_wheels_angle(data, main_spread);
      shift_wheels(data);
    }
  data->previous_spread = main_spread;
  return (SUCCESS);
}
