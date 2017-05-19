/*
** main.c for main in /home/gogo/rendu/CPE_2015_n4s/srcs/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 21:58:50 2016 Gauthier Cler
** Last update Sun May 29 21:53:20 2016 Gauthier Cler
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"ia.h"

static int		start_simulation(t_data *data)
{
  if (call_instruction(data, "START_SIMULATION", 0, NO_MODE) == ERROR)
    return (ERROR);
  free_array(data->answer_tab);
  data->car_speed = 1;
  data->previous_speed = 1;
  data->previous_spread = 3;
  data->turn_angle = 0.0;
  data->previous_angle = 0.0;
  if (call_instruction(data, "CAR_FORWARD", data->car_speed, FLOAT) == ERROR)
    return (ERROR);
  free_array(data->answer_tab);
  return (SUCCESS);
}

static int		init_bunny(t_raycast *data)
{
  data->pix = bunny_new_pixelarray(320, 200);
  if (data->pix == NULL)
    return (ERROR);
  data->win = bunny_start(320, 200, 0, "N4S");
  if (data->win == NULL)
    return (ERROR);
  return (SUCCESS);
}

static int		delete_bunny(t_raycast *data)
{
  bunny_stop(data->win);
  bunny_delete_clipable(&data->pix->clipable);
  return (SUCCESS);
}

static int		start_race(t_data *data)
{
  t_raycast		bunny;

  if (init_bunny(&bunny) == ERROR)
    return (ERROR);
  if (start_simulation(data) == ERROR)
    return (ERROR);
  while (call_instruction(data, "GET_INFO_LIDAR", 0, NO_MODE) != ERROR)
    {
      if (assess_rays(data->rays, data->answer_tab) == ERROR)
	return (ERROR);
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
      draw_fps(&bunny, data);
    }
  delete_bunny(&bunny);
  return (SUCCESS);
}

static int		check_env(char **ae)
{
  int			count;

  if (ae == NULL)
    return (ERROR);
  count = 0;
  while (ae[count])
    {
      if (my_strcmp(ae[count], "DISPLAY=:0") == 0)
	return (SUCCESS);
      count += 1;
    }
  return (ERROR);
}

int			main(int ac, char **av, char **ae)
{
  t_data		data;

  (void)ac;
  (void)av;
  if (check_env(ae) == ERROR)
    return (ERROR);
  return (start_race(&data));
}
