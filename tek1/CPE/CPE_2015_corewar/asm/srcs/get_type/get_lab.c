/*
** get_lab.c for get_lab in /home/montag_v/rendu/BACKUP_TYPE/type
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Wed Mar 23 11:39:54 2016 valentin montagne
** Last update Wed Mar 23 13:58:31 2016 Gauthier Cler
*/

#include	"asm.h"

int		wrong_char(char letter)
{
  int		i;

  i = 0;
  while (LABEL_CHARS[i])
    {
      if (letter == LABEL_CHARS[i])
	return (SUCCESS);
      i++;
    }
  return (ERROR);
}

int		get_lab(char *arg)
{
  int		i;
  int		dir;

  i = 0;
  dir = 0;
  while (arg[i] == '\\')
    i++;
  if (arg[i] == DIRECT_CHAR)
    dir = 1;
  if (arg[i + dir] != LABEL_CHAR)
    return (0);
  while (arg[i + dir + 1])
    if (wrong_char(arg[1 + dir + i++]))
      return (0);
  if (dir == 1)
    return (4);
  return (5);
}
