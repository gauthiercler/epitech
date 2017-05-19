/*
** rotation_x.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/matrices/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed May 11 16:25:22 2016 Buyumad Anas
** Last update Sat May 14 21:04:01 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		init_x(float *matrix, int angle)
{
  matrix[0] = 1.0;
  matrix[1] = 0.0;
  matrix[2] = 0.0;
  matrix[3] = 0.0;
  matrix[4] = xcos[get_angle(angle)];
  matrix[5] = (-1.0) * xsin[get_angle(angle)];
  matrix[6] = 0.0;
  matrix[7] = xsin[get_angle(angle)];
  matrix[8] = xcos[get_angle(angle)];
}

static void	init_result_x(float *result, float *matrix, t_position *point)
{
  result[0] = point->x * matrix[0] + point->y *
      matrix[1] + point->z * matrix[2];
  result[1] = point->x * matrix[3] + point->y *
      matrix[4] + point->z * matrix[5];
  result[2] = point->x * matrix[6] + point->y *
      matrix[7] + point->z * matrix[8];
}

void		rotate_x(t_position *point, float angle)
{
  float		matrix[9];
  float		result[3];

  if ((int)angle == 0)
    return ;
  init_x(matrix, (int)angle);
  init_result_x(result, matrix, point);
  point->x = result[0];
  point->y = result[1];
  point->z = result[2];
}
