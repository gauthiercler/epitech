/*
** gen_stars.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/stars/gen_stars.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:57:40 2016 Anas Buyumad
** Last update Tue Mar 22 11:50:43 2016 Gauthier Cler
*/

#include	"megalovania.h"

void		rand_star(t_star *star)
{
  int		r;

  star->pos.x = rand() % 1920;
  star->pos.y = rand() % 1080;
  r = rand() % 105;
  if (r > 0 && r <= 75)
    star->type = 1;
  else if (r > 75 && r <= 90)
    star->type = 2;
  else if (r > 90 && r <= 100)
    star->type = 3;
  else if (r > 102)
    star->type = 4;
  if (star->type == 4)
    star->speed = 75;
  else if (star->type == 3)
    star->speed = 25;
  else if (star->type == 2)
    star->speed = 15;
  else if (star->type == 1)
    star->speed = 5;
  star->color.full = WHITE;
}

void	gen_stars(t_data *data)
{
  int	i;

  i = 0;
  while (i < 20)
    {
      rand_star(&data->stars[i]);
      i += 1;
    }
}
