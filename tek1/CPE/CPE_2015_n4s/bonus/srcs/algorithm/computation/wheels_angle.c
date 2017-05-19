/*
** wheels_angle.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 24 18:08:02 2016 Buyumad Anas
** Last update Sun May 29 21:24:06 2016 Gauthier Cler
*/

#include	"ia.h"

static void	middle_tweak(t_data *data)
{
  float		w_x;
  float		coeff;

  coeff = 1;
  (data->spread[0] < data->spread[7]) ? (coeff *= -1) : 0;
  if (data->spread[0] < data->spread[7])
      w_x = data->spread[0];
  else
      w_x = data->spread[7];
  if (w_x < 350.0 && w_x >= 200.0)
    data->turn_angle += 0.05 * coeff * 1.25;
  else if (w_x < 200.0 && w_x >= 100.0)
    data->turn_angle += 0.10 * coeff * 1.5;
  else if (w_x < 100.0)
    data->turn_angle += 0.15 * coeff * 2.0;
}

static void	tweak(t_data *data)
{
  float		wall_distance;

  if (data->turn_angle < 0)
    wall_distance = data->spread[0];
  else
    wall_distance = data->spread[7];
  if (wall_distance < 350.0 && wall_distance >= 200.0)
    data->turn_angle *= 2;
  else if (wall_distance < 200.0 && wall_distance >= 100.0)
    data->turn_angle *= 3;
  else if (wall_distance < 100.0 && wall_distance >= 0.0)
    data->turn_angle *= 4;
}

void		compute_wheels_angle(t_data *data, int main_spread)
{
  (main_spread == 3 || main_spread == 4) ? data->turn_angle = 0.0 : 0;
  (main_spread == 2 || main_spread == 5) ? data->turn_angle = 0.05 : 0;
  (main_spread == 1 || main_spread == 6) ? data->turn_angle = 0.10 : 0;
  (main_spread == 0 || main_spread == 7) ? data->turn_angle = 0.15 : 0;
  (main_spread >= 4) ? data->turn_angle *= -1.0 : 0;
  if (main_spread != 3 && main_spread != 4)
    tweak(data);
  else
    middle_tweak(data);
}
