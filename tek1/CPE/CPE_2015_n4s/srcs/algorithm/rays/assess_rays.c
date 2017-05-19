/*
** assess_rays.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/rays/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 16:24:53 2016 Buyumad Anas
** Last update Sun May 29 21:28:34 2016 Gauthier Cler
*/

#include	"ia.h"

int		get_bigger_ray(float *rays)
{
  int		selectioned;
  int		index;

  index = 0;
  selectioned = 0;
  while (index < NB_RAYS)
    {
      if (rays[index] > rays[selectioned])
	selectioned = index;
      index += 1;
    }
  return (selectioned);
}

int		assess_rays(float *rays, char **answer_tab)
{
  int		index;
  int		ray;

  ray = 0;
  index = 3;
  while (answer_tab[index])
    {
      rays[ray] = my_atof(answer_tab[index]);
      ray += 1;
      index += 1;
    }
  return (SUCCESS);
}
