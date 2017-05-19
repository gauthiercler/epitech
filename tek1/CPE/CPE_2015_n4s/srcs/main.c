/*
** main.c for main in /home/gogo/rendu/CPE_2015_n4s/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 21:58:50 2016 Gauthier Cler
** Last update Sun May 29 21:25:00 2016 Gauthier Cler
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"ia.h"

static int		start_simulation(t_data *data)
{
  if (call_instruction(data, "START_SIMULATION", 0, NO_MODE) == ERROR)
    return (ERROR);
  free_array(data->answer_tab);
  data->car_speed = 0;
  data->previous_speed = 0;
  data->previous_spread = 3;
  data->turn_angle = 0.0;
  if (call_instruction(data, "CAR_FORWARD", data->car_speed, FLOAT) == ERROR)
    return (ERROR);
  free_array(data->answer_tab);
  return (SUCCESS);
}

static int		start_race(t_data *data)
{
  if (start_simulation(data) == ERROR)
    return (ERROR);
  format(2, "Simulation Started\n");
  while (call_instruction(data, "GET_INFO_LIDAR", 0, NO_MODE) != ERROR)
    {
      if (assess_rays(data->rays, data->answer_tab) == ERROR)
	{
	  free_array(data->answer_tab);
	  return (ERROR);
	}
      free_array(data->answer_tab);
      assess_spread(data->spread, data->rays);
      compute_output(data);
      if (data->car_speed != data->previous_speed)
	{
	  if (call_instruction(data, "CAR_FORWARD", data->car_speed,
			       FLOAT) == ERROR)
	    return (ERROR);
	  free_array(data->answer_tab);
	}
      data->previous_speed = data->car_speed;
    }
  format(2, "Simulation Stopped\n");
  return (SUCCESS);
}

int			main(void)
{
  int			ret_value;
  t_data		data;

  ret_value = start_race(&data);
  return (ret_value);
}
