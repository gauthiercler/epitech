/*
** is_link.c for is_link in /home/montag_v/rendu/CPE_2015_Lemin
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Fri Apr 22 11:37:36 2016 montag_v
** Last update Fri Apr 22 12:32:35 2016 montag_v
*/

#include	"lemin.h"

int             is_link(char *line)
{
  int           i;

  i = 0;
  while (line[i] == ' ' && line[i] == '\t')
    i += 1;
  while (line[i] != '\0')
    {
      if (line[i] == '-')
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
