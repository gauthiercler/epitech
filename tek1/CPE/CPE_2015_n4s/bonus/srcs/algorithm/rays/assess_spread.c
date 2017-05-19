/*
** assess_spread.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/algorithm/rays/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue May 24 17:17:52 2016 Buyumad Anas
** Last update Tue May 24 17:32:17 2016 Buyumad Anas
*/

#include	"ia.h"

int		get_main_spread(float *spread)
{
  int		selectioned;
  int		index;

  index = 0;
  selectioned = 0;
  while (index < NB_SPREAD)
    {
      if (spread[index] > spread[selectioned])
	selectioned = index;
      index += 1;
    }
  return (selectioned);
}

void		assess_spread(float *spread, float *rays)
{
  int		index;
  int		rays_index;

  index = 0;
  rays_index = 0;
  while (index < NB_SPREAD)
    {
      spread[index] = (rays[rays_index] + rays[rays_index + 1] +
		       rays[rays_index + 2] + rays[rays_index + 3]) / 4.0;
      index += 1;
      rays_index += 4;
    }
}
