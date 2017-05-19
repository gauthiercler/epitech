/*
** wheels.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 20:56:09 2016 Buyumad Anas
** Last update Sun May 29 21:26:01 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"ia.h"

float		get_wheels_angle(t_data *data)
{
  float		wheels_angle;

  if (call_instruction(data, "GET_CURRENT_WHEELS", 0, NO_MODE) == ERROR)
    return (-1);
  free_array(data->answer_tab);
  wheels_angle = my_atof(data->answer_tab[3]);
  return (wheels_angle);
}

int		shift_wheels(t_data *data)
{
  if (data->previous_angle != data->turn_angle)
    {
      if (call_instruction(data, "WHEELS_DIR", data->turn_angle, FLOAT) == ERROR)
	return (ERROR);
      free_array(data->answer_tab);
    }
  data->previous_angle = data->turn_angle;
  return (SUCCESS);
}
