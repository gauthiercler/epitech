/*
** speed.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/computation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 24 17:47:36 2016 Buyumad Anas
** Last update Sun May 29 21:24:23 2016 Gauthier Cler
*/

#include	"ia.h"

void		compute_distance(float distance, float *speed,
				 float previous_speed)
{
  float		coeff;
  float		raport;

  coeff = distance / 2000.0;
  (coeff >= 1.0) ? *speed = 1.0 : (*speed = coeff);

  if (*speed > previous_speed)
    {
      raport = *speed - previous_speed;
      raport /= 8.0;
      *speed = previous_speed + raport;
    }
  if (*speed > 0.4)
    *speed = 0.4;
}
