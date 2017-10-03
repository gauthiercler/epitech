/*
** to_str.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/tile/to_str.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 14:42:32 2017 Montagne Valentin
** Last update Fri Jun 30 14:42:32 2017 Montagne Valentin
*/

#include		<stdio.h>
#include 		<string.h>
#include		"tile.h"

static unsigned int	get_len(t_tile *self)
{
  unsigned int		len;

  len = 0;
  len += self->nb_players(self) * (strlen(PLAYER_STR) + 1);
  len += self->egg_list->size(self->egg_list) * (strlen(EGG_STR) + 1);
  len += self->inventory->food * (strlen(FOOD_STR) + 1);
  len += self->inventory->linemate * (strlen(LINEMATE_STR) + 1);
  len += self->inventory->deraumere * (strlen(DERAUMERE_STR) + 1);
  len += self->inventory->sibur * (strlen(SIBUR_STR) + 1);
  len += self->inventory->mendiane * (strlen(MENDIANE_STR) + 1);
  len += self->inventory->phiras * (strlen(PHIRAS_STR) + 1);
  len += self->inventory->thystame * (strlen(THYSTAME_STR) + 1);
  return (len);
}

static void			write_object(char *str, char *object,
						unsigned int nb)
{
  unsigned int			j;
  unsigned int			i;

  j = 0;
  while (j < nb)
  {
    i = 0;
    while (str[i])
      i += 1;
    str[i] = ' ';
    strcpy(str + (i + 1), object);
    str[i + 1 + strlen(object)] = '\0';
    j += 1;
  }
}

char			*tile_to_str(t_tile *self)
{
  char			*to_str;
  unsigned int		len;

  len = get_len(self);
  to_str = malloc(sizeof(char) * (len + 1));
  if (to_str == NULL)
    return (NULL);
  to_str[0] = '\0';
  write_object(to_str, PLAYER_STR, (unsigned int)self->nb_players(self));
  write_object(to_str, EGG_STR,
	       (unsigned int)self->egg_list->size(self->egg_list));
  write_object(to_str, FOOD_STR, self->inventory->food);
  write_object(to_str, DERAUMERE_STR, self->inventory->deraumere);
  write_object(to_str, LINEMATE_STR, self->inventory->linemate);
  write_object(to_str, MENDIANE_STR, self->inventory->mendiane);
  write_object(to_str, SIBUR_STR, self->inventory->sibur);
  write_object(to_str, PHIRAS_STR, self->inventory->phiras);
  write_object(to_str, THYSTAME_STR, self->inventory->thystame);
  return (to_str);
}