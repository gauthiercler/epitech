/*
** parse_ai.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/sources/parser/parse_ai.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 15:11:54 2017 Montagne Valentin
** Last update Fri Jun 23 15:11:54 2017 Montagne Valentin
*/

#include			<stdio.h>
#include			<stdlib.h>
#include 			<string.h>
#include			"parse_stream.h"

static const t_dictio		dico[] =
  {
    { FORWARD, "Forward", SHORT_TICK, NULL, response_forward },
    { RIGHT, "Right", SHORT_TICK, NULL, response_right },
    { LEFT, "Left", SHORT_TICK, NULL, response_left },
    { LOOK, "Look", SHORT_TICK, NULL, response_look },
    { INVENTORY, "Inventory", NOTICK, NULL, response_inventory },
    { BROADCAST, "Broadcast ", SHORT_TICK,
      parse_broadcast, response_broadcast },
    { CONNECT_NBR, "Connect_nbr", NOTICK, NULL, NULL },
    { FORK, "Fork", LIFE_TICK, NULL, response_fork },
    { EJECT, "Eject", SHORT_TICK, NULL, NULL },
    { TAKE_OBJ, "Take ", SHORT_TICK, parse_take, response_take },
    { DROP_OBJ, "Set ", SHORT_TICK, parse_drop, response_drop },
    { INCANTATION, "Incantation", NOTICK, NULL, response_inc_begin },
    { UNKNOWN, NULL, NOTICK, NULL, response_unknown }
  };

t_error				parse_ai(char *stream, t_command *r)
{
  t_error			ret;
  unsigned int			i;

  i = 0;
  while (dico[i].token != NULL)
  {
    if (strncmp(dico[i].token, stream, strlen(dico[i].token)) == 0)
    {
      r->fill(r, dico[i].type, dico[i].tick, dico[i].resp);
      if (dico[i].fct != NULL)
	if ((ret = dico[i].fct(stream + strlen(dico[i].token), r))
	    != NOTHING)
	  return (ret);
      break;
    }
    i += 1;
  }
  r->fill(r, dico[i].type, dico[i].tick, dico[i].resp);
  return (NOTHING);
}