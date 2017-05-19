/*
** tick_dynamics.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 15 15:24:23 2016 Buyumad Anas
** Last update Fri Apr 15 15:43:13 2016 Buyumad Anas
*/

#include	"adventure.h"

void		tack(t_elem *elem)
{
  elem->pos.x += elem->ratio;
  if (elem->pos.x > 2000)
    elem->pos.x = -500;
}

void		tick_dyn(t_decor *decor)
{
  int		i;

  i = 0;
  if (decor->dynamics == NULL)
    return ;
  while (decor->dynamics[i].name != NULL)
    {
      tack(&decor->dynamics[i]);
      i += 1;
    }
}

void		tick_dynamics(t_decor *decors)
{
  int		i;

  i = 0;
  while (i < NB_DECOR)
    {
      tick_dyn(&decors[i]);
      i += 1;
    }
}
