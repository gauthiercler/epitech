/*
** click_events.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 15:38:26 2016 Anas Buyumad
** Last update Sun Apr 17 23:35:37 2016 Gauthier Cler
*/

#include			"adventure.h"

void				analyze_caller(t_adventure *adventure, int analyze,
					       const t_bunny_position *pos)
{
  if (analyze == 0 && adventure->character.in_graph == false)
    {
      if (!adventure->character.moving)
	set_moving_character(adventure, pos);
    }
  else if (analyze == 1)
    {
      adventure->character.moving = false;
      adventure->character.current = 0;
    }
  else if (analyze == 3)
    {
      adventure->character.in_graph = true;
      if (adventure->character.moving_graph == false)
	graph(adventure, pos);
    }
}

t_bunny_response		handle_clicks(t_bunny_event_state state,
					      t_bunny_mousebutton mouse,
					      void *data)
{
  t_adventure			*adventure;
  const t_bunny_position	*pos;
  int				analyze;

  adventure = data;
  if (mouse == BMB_LEFT && state == GO_DOWN)
    pos = bunny_get_mouse_position();
  else
    return (GO_ON);
  if (adventure->current_level == -1)
    return (click_menu(state, mouse, data));
  else if (adventure->current_level >= 0 && adventure->current_level < NB_LEVELS)
    {
      analyze = analyze_click(adventure, pos);
      analyze_caller(adventure, analyze, pos);
    }
  return (GO_ON);
}
