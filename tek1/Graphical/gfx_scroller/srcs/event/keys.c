/*
** keys.c for gfx_scroller in /home/keyrise/Work/Repositories/Epitech/RUSH/gfx_scroller/srcs/event/keys.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  19 13:04:00 2016 Anas Buyumad
** Last update Tue Mar 22 11:45:41 2016 Gauthier Cler
*/

#include	"megalovania.h"

void		change_star_color(t_data *data, unsigned int color)
{
  int		i;

  i = 0;
  while (i < 20)
  {
    data->stars[i].color.full = color;
    i += 1;
  }
}

t_bunny_response	key_handle(t_bunny_event_state state,
				   t_bunny_keysym key, void *d)
{
  t_data		*data;

  data = d;
  if (key == BKS_ESCAPE)
    return (EXIT_SUCCESS);
  if (key == BKS_UP)
    data->ondulation += 20;
  if (key == BKS_DOWN)
    data->ondulation -= 20;
  if (key == BKS_P && state == GO_DOWN)
    {
      if (!data->peanut_active)
	{
	  data->peanut_active = true;
	  change_star_color(data, YELLOW);
	}
      else
	{
	  data->peanut_active = false;
	  change_star_color(data, WHITE);
	}
    }
  return (GO_ON);
}
