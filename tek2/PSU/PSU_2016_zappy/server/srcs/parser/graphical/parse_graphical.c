/*
** parse_graphical.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/parser/graphical/parse_graphical.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jun 24 13:36:44 2017 Montagne Valentin
** Last update Sat Jun 24 13:36:44 2017 Montagne Valentin
*/

#include			<stdio.h>
#include			<stdlib.h>
#include 			<string.h>
#include			"parse_stream.h"

static const t_dictio		dico[] =
  {
    { MAP_SIZE, "msz", NOTICK, NULL, NULL },
    { CELL_CONTENT, "bct ", NOTICK, NULL, NULL },
    { MAP_CONTENT, "mct", NOTICK, NULL, NULL },
    { TEAM_NAMES, "tna", NOTICK, NULL, NULL },
    { PLAYER_POSITION, "ppo ", NOTICK, NULL, NULL },
    { PLAYER_LVL, "plv  ", NOTICK, NULL, NULL },
    { PLAYER_INVENTORY, "pin ", NOTICK, NULL, NULL },
    { NEED_TIME, "sgt", NOTICK, NULL, NULL },
    { TIME_MODIFICATION, "sst ", NOTICK, NULL, NULL },
    { UNKNOWN, NULL, NOTICK, NULL, NULL }
  };

t_error				parse_graphical(char *stream, t_command *r)
{
  t_error			ret;
  unsigned int			i;

  i = 0;
  while (dico[i].token != NULL)
  {
    if (strncmp(dico[i].token, stream, strlen(dico[i].token)) == 0)
    {
      if (dico[i].fct != NULL)
      {
	if ((ret = dico[i].fct(stream + strlen(dico[i].token), r))
	    != NOTHING)
	  return (ret);
      }
      else
	r->fill(r, dico[i].type, NOTICK, NULL);
      break;
    }
    i += 1;
  }
  return (NOTHING);
}