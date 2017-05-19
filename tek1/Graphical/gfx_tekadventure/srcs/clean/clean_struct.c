/*
** clean_struct.c for clean_struct in /home/gogo/rendu/gfx_tekadventure/srcs/clean
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 14 14:05:59 2016 Gauthier Cler
** Last update Sun Apr 17 20:13:00 2016 Gauthier Cler
*/

#include		"adventure.h"

void			clean_elems(t_elem *elems)
{
  int			i;

  if (elems != NULL)
    {
      i = 0;
      while (elems[i].name != NULL)
	{
	  bunny_free(elems[i].name);
	  i += 1;
	}
      bunny_free(elems);
    }
}

void			clean_levels(t_level *levels)
{
  int			i;
  int			j;

  i = 0;
  while (i < NB_LEVELS)
    {
      j = 0;
      while (j < NB_DECOR)
	{
	  clean_elems(levels[i].decors[j].elems);
	  clean_elems(levels[i].decors[j].dynamics);
	  j += 1;
	}
      j = 0;
      while (levels[i].rooms[j].background != NULL)
	{
	  clean_elems(levels[i].rooms[j].elems);
	  bunny_delete_clipable(levels[i].rooms[j].background);
	  clean_graph(levels[i].rooms[j].graphs);
	  j += 1;
	}
      i += 1;
    }
}

void			clean_ressources(t_ressource *ressources)
{
  int			i;

  i = 0;
  while (ressources[i].name != NULL)
    {
      if (ressources[i].picture != NULL)
	bunny_delete_clipable(ressources[i].picture);
      bunny_free(ressources[i].name);
      i += 1;
    }
  bunny_free(ressources);
}

void			clean_character(t_character *character)
{
  if (character->stay_right.pix != NULL)
    bunny_delete_clipable(character->stay_right.pix);
  if (character->stay_left.pix != NULL)
    bunny_delete_clipable(character->stay_left.pix);
  if (character->move_right.pix != NULL)
    bunny_delete_clipable(character->move_right.pix);
  if (character->move_left.pix != NULL)
    bunny_delete_clipable(character->move_left.pix);
}

int			clean_struct(t_adventure *adventure)
{
  bunny_stop(adventure->window);
  if (adventure->pix != NULL)
  bunny_delete_clipable(&adventure->pix->clipable);
  bunny_delete_sound(&adventure->menu.music->sound);
  clean_levels(adventure->levels);
  clean_ressources(adventure->ressources);
  clean_character(&adventure->character);
  clean_menu(&adventure->menu);
  return (SUCCESS);
}
