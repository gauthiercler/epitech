/*
** rotate_inverse.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/matrices/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat May 14 20:52:26 2016 Buyumad Anas
** Last update Thu May 19 22:58:33 2016 Buyumad Anas
*/

#include	"raytracer.h"

static int	init_matrix(float *matrix, t_position *inclinaison)
{
  if ((int)inclinaison->x != 0)
    {
      init_x(matrix, (int)((-1.0) * inclinaison->x));
      return (1);
    }
  else if ((int)inclinaison->y != 0)
    {
      init_y(matrix, (int)((-1.0) * inclinaison->y));
      return (2);
    }
  else if ((int)inclinaison->z != 0)
    {
      init_z(matrix, (int)((-1.0) * inclinaison->z));
      return (3);
    }
  return (0);
}

static void	init_result(float *result, float *matrix, t_position *point)
{
  result[0] = point->x * matrix[0] + point->y *
      matrix[1] + point->z * matrix[2];
  result[1] = point->x * matrix[3] + point->y *
      matrix[4] + point->z * matrix[5];
  result[2] = point->x * matrix[6] + point->y *
      matrix[7] + point->z * matrix[8];
}

void		rotate_inverse(t_position *point, t_position *inclinaison)
{
  float		matrix[9];
  float		result[3];
  int		state;

  if ((state = init_matrix(matrix, inclinaison)) == 0)
    return ;
  else if (state == 1)
    {
      mult_matrix_y(matrix, (int)((-1.0) * inclinaison->y));
      mult_matrix_z(matrix, (int)((-1.0) * inclinaison->z));
    }
  else if (state == 2)
    {
      mult_matrix_z(matrix, (int)((-1.0) * inclinaison->z));
    }
  init_result(result, matrix, point);
  point->x = result[0];
  point->y = result[1];
  point->z = result[2];
}
