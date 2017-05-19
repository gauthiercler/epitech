/*
** find_hitboxes.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sat Apr 16 14:36:14 2016 Buyumad Anas
** Last update Sun Apr 17 23:39:51 2016 Gauthier Cler
*/

#include	"adventure.h"

void		check_elem_pos(t_elem *elems, t_character *character,
			       const t_bunny_position *pos, t_position *values)
{
  if ((pos->x >= elems->pos.x) &&
      (pos->x <= elems->pos.x + elems->hitbox.x) &&
      (pos->y >= elems->pos.y) &&
      (pos->y <= elems->pos.y + elems->hitbox.y))
    {
      values->x = elems->interaction.type;
      values->y = elems->interaction.value;
      if (values->x == 1)
	{
	  if ((character->position.x + 50 < elems->pos.x)
	      || (character->position.x - 50 < elems->pos.y))
	    values->x = 0;
	  if ((character->position.x - 50 >
	       elems->pos.x + elems->hitbox.x))
	    values->x = 0;
	}
    }
}

t_position	*find_elem(t_elem *elems, const t_bunny_position *pos,
			   t_character *character)
{
  t_position	*values;
  int		i;

  i = 0;
  if ((values = bunny_malloc(sizeof(t_position))) == NULL)
    return (NULL);
  values->x = 0;
  values->y = 0;
  while (elems[i].name != NULL)
    {
      check_elem_pos(&elems[i], character, pos, values);
      i += 1;
    }
  return (values);
}

t_position	*find_hit(t_level *level, const t_bunny_position *pos,
			  t_character *character)
{
  t_position	*values;
  int		i;

  i = 0;
  while (i < NB_DECOR)
    {
      if (level->decors[i].elems[0].name != NULL)
	{
	  if (level->decors[i].elems[1].name == NULL)
	    return (NULL);
	}
      if ((values =
	   find_elem(level->decors[i].elems, pos, character)) == NULL)
	return (NULL);
      if (values->x == 1)
	{
	  level->selected = values->y;
	  backup_pos(character);
	  return (values);
	}
      i += 1;
    }
  return (NULL);
}

t_position	*find_room_hit(t_adventure *adventure, t_room *room,
			       const t_bunny_position *pos)
{
  t_position	*values;

  if ((values = bunny_malloc(sizeof(t_position))) == NULL)
    return (NULL);
  values->x = 0;
  values->y = 0;
  if (pos->x >= 900 && pos->y < 200)
    {
      adventure->character.in_graph = false;
      adventure->levels[adventure->current_level].selected = 0;
      adventure->character.position.x = adventure->character.save_pos.x;
      adventure->character.position.y = adventure->character.save_pos.y;
    }
  (void)room;
  return (values);
}

int		find_hitboxes(t_adventure *adventure, const t_bunny_position *pos)
{
  t_position	*values;

  if (adventure->levels[adventure->current_level].selected == 0)
    {
      if ((values = find_hit(&adventure->levels[adventure->current_level],
			     pos, &adventure->character)) == NULL)
	return (0);
      return (values->x);
    }
  else
    {
      if ((values =
	   find_room_hit(adventure,
			 &adventure->levels[adventure->current_level]
			 .rooms[adventure->levels[adventure->current_level]
				.selected - 1], pos)) == NULL)
        format(1, "Find hitboxes in Room.");
    }
  return (0);
}
