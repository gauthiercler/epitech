/*
** pause.c for pause in /home/gogo/rendu/PSU_2015_tetris/srcs/game/input
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 16 22:47:47 2016 Gauthier Cler
** Last update Wed Mar 16 22:54:21 2016 Gauthier Cler
*/

#include	"tetris.h"

void		pause_loop(char *pause, char *quit)
{
  int		i;
  char		buffer[100];

  buffer[0] = '\0';
  while (my_strcmp(pause, buffer) != SUCCESS)
    {
      i = read(0, buffer, sizeof(buffer));
      buffer[i] = '\0';
      if (my_strcmp(quit, buffer) == SUCCESS)
	{
	  set_term_settings(1);
	  curs_set(1);
	  putp(tigetstr("clear"));
	  exit(0);
	}
    }
}
