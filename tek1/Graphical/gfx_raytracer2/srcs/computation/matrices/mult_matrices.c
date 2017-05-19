/*
** mult_matrices.c for raytracer2 in /home/skyrise/Work/Repositories/Epitech/GFX/gfx_raytracer2/srcs/computation/matrices/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat May 14 21:15:16 2016 Buyumad Anas
** Last update Sat May 14 21:39:53 2016 Buyumad Anas
*/

#include	"raytracer.h"

void		copy_matrix(float *matrix, float *result)
{
  matrix[0] = result[0];
  matrix[1] = result[1];
  matrix[2] = result[2];
  matrix[3] = result[3];
  matrix[4] = result[4];
  matrix[5] = result[5];
  matrix[6] = result[6];
  matrix[7] = result[7];
  matrix[8] = result[8];
}

void		mult_matrix_y(float *matrix, int angle)
{
  float		result[9];

  result[0] = matrix[0] * xcos[get_angle(angle)] +
      matrix[1] * 0.0 + matrix[2] * (xsin[get_angle(angle)] * (-1.0));
  result[1] = matrix[0] * 0.0 + matrix[1] * 1.0 + matrix[2] * 0.0;
  result[2] = matrix[0] * xsin[get_angle(angle)] +
      matrix[1] * 0.0 + matrix[2] * xcos[get_angle(angle)];
  result[3] = matrix[3] * xcos[get_angle(angle)] +
      matrix[4] * 0.0 + matrix[5] * (xsin[get_angle(angle)] * (-1.0));
  result[4] = matrix[3] * 0.0 + matrix[4] * 1.0 + matrix[5] * 0.0;
  result[5] = matrix[3] * xsin[get_angle(angle)] +
      matrix[4] * 0.0 + matrix[5] * xcos[get_angle(angle)];
  result[6] = matrix[6] * xcos[get_angle(angle)] +
      matrix[7] * 0.0 + matrix[8] * (xsin[get_angle(angle)] * (-1.0));
  result[7] = matrix[6] * 0.0 + matrix[7] * 1.0 + matrix[8] * 0.0;
  result[8] = matrix[6] * xsin[get_angle(angle)] +
      matrix[7] * 0.0 + matrix[8] * xcos[get_angle(angle)];
  copy_matrix(matrix, result);
}

void		mult_matrix_z(float *matrix, int angle)
{
  float		result[9];

  result[0] = matrix[0] * xcos[get_angle(angle)] +
      matrix[1] * xsin[get_angle(angle)] + matrix[2] * 0.0;
  result[1] = matrix[0] * (xsin[get_angle(angle)] * (-1.0)) +
      matrix[1] * xcos[get_angle(angle)] + matrix[2] * 0.0;
  result[2] = matrix[0] * 0.0 + matrix[1] * 0.0 + matrix[2] * 1.0;
  result[3] = matrix[3] * xcos[get_angle(angle)] +
      matrix[4] * xsin[get_angle(angle)] + matrix[5] * 0.0;
  result[4] = matrix[3] * (xsin[get_angle(angle)] * (-1.0)) +
      matrix[4] * xcos[get_angle(angle)] + matrix[5] * 0.0;
  result[5] = matrix[3] * 0.0 + matrix[4] * 0.0 + matrix[5] * 1.0;
  result[6] = matrix[6] * xcos[get_angle(angle)] +
      matrix[7] * xsin[get_angle(angle)] + matrix[8] * 0.0;
  result[7] = matrix[6] * (xsin[get_angle(angle)] * (-1.0)) +
      matrix[7] * xcos[get_angle(angle)] + matrix[8] * 0.0;
  result[8] = matrix[6] * 0.0 + matrix[7] * 0.0 + matrix[8] * 1.0;
  copy_matrix(matrix, result);
}
