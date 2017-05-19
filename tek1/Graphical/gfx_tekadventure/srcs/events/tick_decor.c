/*
** tick_decor.c for tekadventure in /home/doleanv/Premiere_annee/infographie/gfx_tekadventure/srcs/events
**
** Made by Doleans Vianney
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Wed Apr 13 17:18:56 2016 Doleans Vianney
** Last update Sun Apr 17 19:46:40 2016 Gauthier Cler
*/

#include	"adventure.h"

void			tick(t_elem *elem, int mode)
{
  if (mode == 1)
    elem->tick -= 1;
  else if (mode == 2)
    elem->tick += 1;
  if (elem->tick == elem->ratio)
    {
      elem->pos.x -= 1;
      elem->tick = 0;
    }
  else if (elem->tick == ((-1) * elem->ratio))
    {
      elem->pos.x += 1;
      elem->tick = 0;
    }
}

void		tick_decor(t_decor *decor, int mode)
{
  int		i;

  i = 0;
  while (decor->elems[i].name != NULL)
    {
      tick(&decor->elems[i], mode);
      i++;
    }
}
