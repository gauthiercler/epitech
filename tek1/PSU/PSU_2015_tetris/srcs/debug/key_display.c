/*
** key_display.c for key_display in /home/gogo/rendu/PSU_2015_tetris/srcs/debug
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Thu Mar 17 18:10:04 2016 Gauthier Cler
** Last update Thu Mar 17 18:10:16 2016 Gauthier Cler
*/

#include	"tetris.h"

void		display_debug_keys(char *str)
{
  if (str[0] == ' ' && str[1] == '\0')
    my_putstr("(space)");
  else
    my_putstr(str);
}
