/*
** rotation_y.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/matrices/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 16:42:08 2016 Buyumad Anas
** Last update Sat May 14 21:03:58 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		init_y(float *matrix, int angle)
{
  matrix[0] = xcos[get_angle(angle)];
  matrix[1] = 0.0;
  matrix[2] = xsin[get_angle(angle)];
  matrix[3] = 0.0;
  matrix[4] = 1.0;
  matrix[5] = 0.0;
  matrix[6] = xsin[get_angle(angle)] * (-1.0);
  matrix[7] = 0.0;
  matrix[8] = xcos[get_angle(angle)];
}

static void	init_result_y(float *result, float *matrix, t_position *point)
{
  result[0] = point->x * matrix[0] + point->y *
      matrix[1] + point->z * matrix[2];
  result[1] = point->x * matrix[3] + point->y *
      matrix[4] + point->z * matrix[5];
  result[2] = point->x * matrix[6] + point->y *
      matrix[7] + point->z * matrix[8];
}

void		rotate_y(t_position *point, float angle)
{
  float		matrix[9];
  float		result[3];

  if ((int)angle == 0)
    return ;
  init_y(matrix, (int)angle);
  init_result_y(result, matrix, point);
  point->x = result[0];
  point->y = result[1];
  point->z = result[2];
}
