/*
** keys_events.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 12:53:55 2016 Buyumad Anas
** Last update Thu Apr 14 17:50:03 2016 Buyumad Anas
*/

#include	"adventure.h"

int			dir_key(t_adventure *adventure, t_bunny_keysym key)
{
  if (adventure->current_level >= 0 && adventure->current_level < NB_LEVELS)
    {
      if (key == BKS_LEFT)
	{
	  if (tick_level(adventure, 1) == ERROR)
	    return (ERROR);
	}
      else if (key == BKS_RIGHT)
	{
	  if (tick_level(adventure, 2) == ERROR)
	    return (ERROR);
	}
    }
  return (SUCCESS);
}

t_bunny_response	handle_keys(t_bunny_event_state state,
				    t_bunny_keysym key,
				    void *data)
{
  t_adventure		*adventure;

  (void)state;
  adventure = data;
  if (key == BKS_RIGHT || key == BKS_LEFT)
    dir_key(adventure, key);
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}
