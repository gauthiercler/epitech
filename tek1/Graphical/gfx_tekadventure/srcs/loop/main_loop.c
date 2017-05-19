/*
** main_loop.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 17:56:20 2016 Anas Buyumad
** Last update Wed Apr 20 21:20:48 2016 Gauthier Cler
*/

#include	"adventure.h"

void			go_next_level(t_adventure *adventure)
{
  if (adventure->character.position.x > 925)
    {
      if (adventure->current_level < NB_LEVELS - 1)
	{
	  adventure->current_level += 1;
	  adventure->character.position.x = 25;
	  adventure->main_pos = 0;
	}
    }
  else if (adventure->character.position.x < 25)
    {
      if (adventure->current_level - 1 >= 0)
	{
	  adventure->current_level -= 1;
	  adventure->character.position.x = 850;
	  adventure->main_pos = 0;
	}
    }
}

int			level_main(t_adventure *adventure, t_level *level)
{
  if (adventure->character.moving)
    move_character(adventure);
  else
    go_next_level(adventure);
  draw_level(adventure, level);
  tick_dynamics(level->decors);
  return (SUCCESS);
}

int			room_main(t_adventure *adventure, t_room *room)
{
  draw_room(adventure, room);
  if (adventure->character.moving_graph)
    move_graph_character(adventure);
  draw_character(adventure);
  return (SUCCESS);
}

int			level_loop(t_adventure *adventure, t_level *level)
{
  if (level->selected == 0)
    level_main(adventure, level);
  else if (level->selected > 0)
    room_main(adventure, &level->rooms[level->selected - 1]);
  return (SUCCESS);
}

t_bunny_response	main_loop(void *data)
{
  t_adventure		*adventure;

  adventure = data;
  if (adventure->current_level == -1)
    menu_loop(adventure);
  if (adventure->current_level >= 0 && adventure->current_level < NB_LEVELS)
    level_loop(adventure, &adventure->levels[adventure->current_level]);
  bunny_display(adventure->window);
  return (GO_ON);
}
